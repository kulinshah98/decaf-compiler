#ifndef _expressionGenVisitor_H
#define _expressionGenVisitor_H

void * visit(ast_literal_expression * node) {
    ast_integer_literal_expression * integerLiteralExpression = dynamic_cast<ast_integer_literal_expression *>(node);
    ast_char_literal_expression * charLiteralExpression = dynamic_cast<ast_char_literal_expression *>(node);
    ast_true_literal_expression * trueLiteralExpression = dynamic_cast<ast_true_literal_expression *>(node);
    ast_false_literal_expression * falseLiteralExpression = dynamic_cast<ast_false_literal_expression *>(node);
    if (integerLiteralExpression) {
        return this->visit(integerLiteralExpression);
    }
    if (charLiteralExpression) {
        return this->visit(charLiteralExpression);
    }
    if (trueLiteralExpression) {
        return this->visit(trueLiteralExpression);
    }
    if (falseLiteralExpression) {
        return this->visit(falseLiteralExpression);
    }
    return ErrorHandler("Should Never Be Called"); // Should never be called.
}

void * visit(ast_integer_literal_expression * node) {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
}

void * visit(ast_char_literal_expression * node) {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
}

void * visit(ast_true_literal_expression * node) {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
}

void * visit(ast_false_literal_expression * node) {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
}

void * visit(ast_binary_operation_expression * node) {
    switch(node->get_op()) {
        case bin_op::plus_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::Add, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::minus_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::Sub, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::multiply_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::Mul, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::divide_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::SDiv, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::modulo_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::SRem, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::lessthan_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLT, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::greaterthan_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGT, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::lessequal_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::greaterequal_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::notequal_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_NE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::equalequal_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        case bin_op::and_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::And, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        case bin_op::or_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::Or, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
    }
    return ErrorHandler("No Known BinaryOperator");
}

void * visit(ast_unary_operation_expression * node) {
    switch(node->get_op()) {
        case un_op::minus_op:
        return llvm::BinaryOperator::Create(llvm::Instruction::Sub, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), static_cast<llvm::Value*>(this->visit(node->get_expr())), "tmp", symbol_table_obj.top_block());
        case un_op::not_op:
        return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), static_cast<llvm::Value*>(this->visit(node->get_expr())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
    }
    return ErrorHandler("No Known UnaryOperator");
}

#endif
