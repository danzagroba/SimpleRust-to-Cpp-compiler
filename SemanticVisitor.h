#pragma once
#include "Visitor.h"
#include "SymbolTable.h"
#include <memory>

class SemanticVisitor : public Visitor {
public:
    SymbolTable& symbolTable; 
    unique_ptr<TypeNode> lastType;

    bool hasError;

    SemanticVisitor(SymbolTable& symbolTable);
    ~SemanticVisitor() override;

    bool compareTypes(TypeNode* type1, TypeNode* type2);

    void visit(Node& node);
    void visit(CommandNode& commandNode);
    void visit(TypeNode& typeNode);
    void visit(ExpressionNode& expressionNode);
    void visit(LogicalExpressionNode& logicalExpressionNode);
    void visit(ArithmeticExpressionNode& arithmeticExpressionNode);
    void visit(MainFunctionNode& mainFunctionNode);
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
