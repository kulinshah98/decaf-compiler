#ifndef _statementGenVisitor_H
#define _statementGenVisitor_H

void * visit(ast_statement * node) {
    llvm::BasicBlock * block = symbol_table_obj.top_block();
    if (block->getTerminator()) {
            // terminate any and all instructions which end the current block when there are still instructions to do
        llvm::Instruction * terminator = block->getTerminator();
        terminator->eraseFromParent();
    }
    ast_assignment_statement * assignmentStatement = dynamic_cast<ast_assignment_statement *>(node);
    ast_block_statement * blockStatement = dynamic_cast<ast_block_statement *>(node);
    ast_method_call * methodCall = dynamic_cast<ast_method_call *>(node);
    ast_if_statement * ifStatement = dynamic_cast<ast_if_statement *>(node);
    ast_for_statement * forStatement = dynamic_cast<ast_for_statement *>(node);
    ast_return_statement * returnStatement = dynamic_cast<ast_return_statement *>(node);
    ast_continue_statement * continueStatement = dynamic_cast<ast_continue_statement *>(node);
    ast_break_statement * breakStatement = dynamic_cast<ast_break_statement *>(node);
    if (assignmentStatement) {
        return this->visit(assignmentStatement);
    }
    if (blockStatement) {
        symbol_table_obj.push_block(NULL);
        this->visit(blockStatement);
        symbol_table_obj.pop_block();
        return NULL;
    }
    if (methodCall) {
        return this->visit(methodCall);
    }
    if (ifStatement) {
        return this->visit(ifStatement);
    }
    if (forStatement) {
        return this->visit(forStatement);
    }
    if (returnStatement) {
        return this->visit(returnStatement);
    }
    if (continueStatement) {
        return this->visit(continueStatement);
    }
    if (breakStatement) {
        return this->visit(breakStatement);
    }
    return ErrorHandler("Should Never Be Called"); // Should never be called.
}

void * visit(ast_if_statement * node) {
    llvm::BasicBlock * entryBlock = symbol_table_obj.top_block();
    llvm::Value * condition = static_cast<llvm::Value *>(this->visit(node->get_condition()));
    llvm::ICmpInst * comparison = new llvm::ICmpInst(*entryBlock, llvm::ICmpInst::ICMP_NE, condition, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), "tmp");
    llvm::BasicBlock * ifBlock = llvm::BasicBlock::Create(MyGlobalContext, "ifBlock", entryBlock->getParent());
    llvm::BasicBlock * mergeBlock = llvm::BasicBlock::Create(MyGlobalContext, "mergeBlock", entryBlock->getParent());

    llvm::BasicBlock * returnedBlock = NULL;

    symbol_table_obj.push_block(ifBlock);
    this->visit(node->getIf_block());
    returnedBlock = symbol_table_obj.top_block();
    symbol_table_obj.pop_block();
    if (!returnedBlock->getTerminator()) {
        llvm::BranchInst::Create(mergeBlock, returnedBlock);
    }
    if (node->getElse_block()) {
        llvm::BasicBlock * elseBlock = llvm::BasicBlock::Create(MyGlobalContext, "elseBlock", entryBlock->getParent());

        symbol_table_obj.push_block(elseBlock);
        this->visit(node->getElse_block());
        returnedBlock = symbol_table_obj.top_block();
        symbol_table_obj.pop_block();
        if (!returnedBlock->getTerminator()) {
            llvm::BranchInst::Create(mergeBlock, returnedBlock);
        }
        llvm::BranchInst::Create(ifBlock, elseBlock, comparison, entryBlock);
    } else {
        llvm::BranchInst::Create(ifBlock, mergeBlock, comparison, entryBlock);
    }
    auto localVariables = symbol_table_obj.get_local_variables();
    symbol_table_obj.pop_block();
    symbol_table_obj.push_block(mergeBlock);
    symbol_table_obj.set_local_variables(localVariables);
    return NULL;
}

void * visit(ast_for_statement * node) {
    if (!symbol_table_obj.lookup_global_vars(node->get_id())) {
        return ErrorHandler("Variable Not Declared");
    }
    llvm::BasicBlock * entryBlock = symbol_table_obj.top_block();
    llvm::BasicBlock * headerBlock = llvm::BasicBlock::Create(MyGlobalContext, "loop_header", entryBlock->getParent(), 0);
    llvm::BasicBlock * bodyBlock = llvm::BasicBlock::Create(MyGlobalContext, "loop_body", entryBlock->getParent(), 0);
    llvm::BasicBlock * afterLoopBlock = llvm::BasicBlock::Create(MyGlobalContext, "after_loop", entryBlock->getParent(), 0);

    symbol_table_obj.push_break_continue_stack(afterLoopBlock, headerBlock);

    new llvm::StoreInst(static_cast<llvm::Value *>(this->visit(node->getInit_condition())), symbol_table_obj.return_locals(node->get_id()), false, entryBlock);
    llvm::Value * val = new llvm::LoadInst(symbol_table_obj.return_locals(node->get_id()), "load", headerBlock);
    llvm::ICmpInst * comparison = new llvm::ICmpInst(*headerBlock, llvm::ICmpInst::ICMP_NE, val, static_cast<llvm::Value *>(this->visit(node->getEnd_condition())), "tmp");
    llvm::BranchInst::Create(bodyBlock, afterLoopBlock, comparison, headerBlock);
    llvm::BranchInst::Create(headerBlock, entryBlock);
    symbol_table_obj.push_block(bodyBlock);
    this->visit(node->get_block());
    bodyBlock = symbol_table_obj.top_block();
    symbol_table_obj.pop_block();
    if (!bodyBlock->getTerminator()) {
        llvm::BranchInst::Create(headerBlock, bodyBlock);
    }

    auto localVariables = symbol_table_obj.get_local_variables();
    symbol_table_obj.pop_block();
    symbol_table_obj.push_block(afterLoopBlock);
    symbol_table_obj.set_local_variables(localVariables);

    symbol_table_obj.pop_break_continue_stack();
    return NULL;
}

void * visit(ast_return_statement * node) {
    llvm::Function * function = symbol_table_obj.top_block()->getParent(); // Doubt full
    llvm::Type * type = function->getReturnType();
    if (type->isVoidTy()) {
        if(node->get_expr()) {
            return ErrorHandler("Unknown Return for Void Type");
        } else {
            return llvm::ReturnInst::Create(MyGlobalContext,symbol_table_obj.top_block());
        }
    } else {
        if (node->get_expr()) {
            llvm::Value * expression = static_cast<llvm::Value *>(this->visit(node->get_expr()));
            return llvm::ReturnInst::Create(MyGlobalContext, expression, symbol_table_obj.top_block());
        } else {
            return ErrorHandler("Void type return for non void function");
        }
    }
}

void * visit(ast_continue_statement * node) {
    llvm::BasicBlock * block = symbol_table_obj.get_continue_stack();
    if (!block) {
        return ErrorHandler("Incorrect continue usage");
    }
    llvm::BasicBlock * curBlock = symbol_table_obj.top_block();
    return llvm::BranchInst::Create(block, curBlock);
}

void * visit(ast_break_statement * node) {
    llvm::BasicBlock * block = symbol_table_obj.get_break_stack();
    if (!block) {
        return ErrorHandler("Incorrect break usage");
    }
    llvm::BasicBlock * curBlock = symbol_table_obj.top_block();
    auto localVariables = symbol_table_obj.get_local_variables();
    symbol_table_obj.pop_block();
    symbol_table_obj.push_block(block);
    symbol_table_obj.set_local_variables(localVariables);
    return llvm::BranchInst::Create(block, curBlock);
}

#endif
