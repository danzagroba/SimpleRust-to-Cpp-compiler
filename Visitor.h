#pragma once
#include "AST.h"

class Visitor {
public:
    virtual void visit(Node& node) = 0;
    virtual void visit(CommandNode& commandNode) = 0;
    virtual void visit(TypeNode& typeNode) = 0;
    virtual void visit(ExpressionNode& expressionNode) = 0;
    virtual void visit(LogicalExpressionNode& logicalExpressionNode) = 0;
    virtual void visit(ArithmeticExpressionNode& arithmeticExpressionNode) = 0;
    virtual void visit(MainFunctionNode& mainFunctionNode) = 0;
    virtual void visit(FunctionNode& functionNode) = 0;
    virtual void visit(FunctionCallCommandNode& functionCallNode) = 0;
    virtual void visit(FunctionCallExpressionNode& functionCallNode) = 0;
    virtual void visit(ProgramNode& programNode) = 0;
    virtual void visit(ParameterNode& parameterNode) = 0;
    virtual void visit(ReturnNode& returnNode) = 0;
    virtual void visit(IntegerLiteralNode& integerLiteralNode) = 0;
    virtual void visit(FloatLiteralNode& floatLiteralNode) = 0;
    virtual void visit(BooleanLiteralNode& booleanLiteralNode) = 0;
    virtual void visit(IdentifierNode& identifierNode) = 0;
    virtual void visit(ArrayAcessNode& arrayAccessNode) = 0;
    virtual void visit(VariableDeclarationNode& variableDeclarationNode) = 0;
    virtual void visit(VariableAssignmentNode& VariableAssignmentNode) = 0;
    virtual void visit(ListElementsNode& listElementsNode) = 0;
    virtual void visit(ArrayDeclarationNode& arrayDeclarationNode) = 0;
    virtual void visit(ArrayAssignmentNode& arrayAssignmentNode) = 0;
    virtual void visit(IfElseNode& ifElseNode) = 0;
    virtual void visit(WhileNode& whileNode) = 0;
    virtual void visit(ForNode& forNode) = 0;
    virtual void visit(AdditionOperatorNode& additionOperatorNode) = 0;
    virtual void visit(SubtractionOperatorNode& subtractionOperatorNode) = 0;
    virtual void visit(MultiplicationOperatorNode& multiplicationOperatorNode) = 0;
    virtual void visit(DivisionOperatorNode& divisionOperatorNode) = 0;
    virtual void visit(EqualityOperatorNode& equalityOperatorNode) = 0;
    virtual void visit(InequalityOperatorNode& inequalityOperatorNode) = 0;
    virtual void visit(LessThanOrEqualOperatorNode& lessThanOrEqualOperatorNode) = 0;
    virtual void visit(LessThanOperatorNode& lessThanOperatorNode) = 0;
    virtual void visit(GreaterThanOrEqualOperatorNode& greaterThanOrEqualOperatorNode) = 0;
    virtual void visit(GreaterThanOperatorNode& greaterThanOperatorNode) = 0;
    virtual void visit(LogicalAndOperatorNode& logicalAndOperatorNode) = 0;
    virtual void visit(LogicalOrOperatorNode& logicalOrOperatorNode) = 0;
    virtual void visit(NotOperatorNode& notOperatorNode) = 0;
    virtual void visit(InputNode& inputNode) = 0;
    virtual void visit(OutputNode& outputNode) = 0;

    virtual ~Visitor() = default;
};