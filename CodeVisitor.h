#pragma once
#include "Visitor.h"
#include "SymbolTable.h"
#include <iostream>
#include <string>
#include <vector>

class CodeVisitor : public Visitor {
    
private:
    SymbolTable& symbolTable; 
    std::string finalCode;
    int indentLevel;

    void indent();
    void appendCode(const std::string& code);
    
public:
    CodeVisitor(SymbolTable& symbolTable);
    ~CodeVisitor() override;

    void visit(Node& node);
    void visit(CommandNode& commandNode);
    void visit(TypeNode& typeNode);
    void visit(ExpressionNode& expressionNode);
    void visit(LogicalExpressionNode& logicalExpressionNode);
    void visit(ArithmeticExpressionNode& arithmeticExpressionNode);
    void visit(MainFunctionNode& mainFunctionNode);
    void visit(FunctionNode& functionNode);
    void visit(ParameterNode& parameterNode);
    void visit(ReturnNode& returnNode);
    void visit(IntegerLiteralNode& integerLiteralNode);
    void visit(FloatLiteralNode& floatLiteralNode);
    void visit(BooleanLiteralNode& booleanLiteralNode);
    void visit(IdentifierNode& identifierNode);
    void visit(ArrayAcessNode& arrayAccessNode);
    void visit(VariableDeclarationNode& variableDeclarationNode);
    void visit(VariableAssignmentNode& VariableAssignmentNode);
    void visit(ListElementsNode& listElementsNode);
    void visit(ArrayDeclarationNode& arrayDeclarationNode);
    void visit(ArrayAssignmentNode& arrayAssignmentNode);
    void visit(IfElseNode& ifElseNode);
    void visit(WhileNode& whileNode);
    void visit(ForNode& forNode);
    void visit(AdditionOperatorNode& additionOperatorNode);
    void visit(SubtractionOperatorNode& subtractionOperatorNode);
    void visit(MultiplicationOperatorNode& multiplicationOperatorNode);
    void visit(DivisionOperatorNode& divisionOperatorNode);
    void visit(EqualityOperatorNode& equalityOperatorNode);
    void visit(InequalityOperatorNode& inequalityOperatorNode);
    void visit(LessThanOrEqualOperatorNode& lessThanOrEqualOperatorNode);
    void visit(LessThanOperatorNode& lessThanOperatorNode);
    void visit(GreaterThanOrEqualOperatorNode& greaterThanOrEqualOperatorNode);
    void visit(GreaterThanOperatorNode& greaterThanOperatorNode);
    void visit(LogicalAndOperatorNode& logicalAndOperatorNode);
    void visit(LogicalOrOperatorNode& logicalOrOperatorNode);
    void visit(NotOperatorNode& notOperatorNode);
    void visit(InputNode& inputNode);
    void visit(OutputNode& outputNode);

};