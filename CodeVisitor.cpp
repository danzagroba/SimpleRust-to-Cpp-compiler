#include "CodeVisitor.h"

CodeVisitor::CodeVisitor(SymbolTable& symbolTable) : symbolTable(symbolTable), indentLevel(0) {}

CodeVisitor::~CodeVisitor() {}

void CodeVisitor::indent() {
    for (int i = 0; i < indentLevel; ++i) {
        finalCode += "    ";    
    }
}

void CodeVisitor::appendCode(const std::string& code) {
    finalCode += code;
}


void CodeVisitor::visit(Node& node) {}
void CodeVisitor::visit(CommandNode& commandNode) {}
void CodeVisitor::visit(TypeNode& typeNode) {
    if (dynamic_cast<IntegerTypeNode*>(&typeNode)) {
        appendCode("int ");
    } else if (dynamic_cast<FloatTypeNode*>(&typeNode)) {
        appendCode("float ");
    } else if (dynamic_cast<BooleanTypeNode*>(&typeNode)) {
        appendCode("bool ");
    }
}
void CodeVisitor::visit(ExpressionNode& expressionNode) {}
void CodeVisitor::visit(LogicalExpressionNode& logicalExpressionNode) {
}
void CodeVisitor::visit(ArithmeticExpressionNode& arithmeticExpressionNode) {}

void CodeVisitor::visit(MainFunctionNode& mainFunctionNode) {
    appendCode("int main() {\n");
    indentLevel++;
    for (CommandNode* command : mainFunctionNode.getCommands()) {
        indent();
        command->accept(*this);
    }
    indentLevel--;
    appendCode("}\n");
    std::cout << "Generated C++ Code:\n" << finalCode << std::endl;
}

void CodeVisitor::visit(IntegerLiteralNode& integerLiteralNode)
{
    appendCode(std::to_string(integerLiteralNode.getValue()));
}

void CodeVisitor::visit(FloatLiteralNode& floatLiteralNode) 
{
    appendCode(std::to_string(floatLiteralNode.getValue()));
}

void CodeVisitor::visit(BooleanLiteralNode& booleanLiteralNode) 
{
    appendCode(std::to_string(booleanLiteralNode.getValue()));
}

void CodeVisitor::visit(IdentifierNode& identifierNode) 
{
    appendCode(identifierNode.getIdentifier());
}

void CodeVisitor::visit(ArrayAcessNode& arrayAccessNode) 
{
    appendCode(arrayAccessNode.getIdentifier());
    appendCode("[");
    arrayAccessNode.getIndex()->accept(*this);
    appendCode("]");
}

void CodeVisitor::visit(VariableDeclarationNode& variableDeclarationNode) 
{
    symbolTable.variables.find(variableDeclarationNode.getIdentifier())->second->accept(*this);
    appendCode(variableDeclarationNode.getIdentifier());
    if(variableDeclarationNode.initialValue != nullptr) {
        appendCode(" = ");
        variableDeclarationNode.initialValue->accept(*this);
    }
    appendCode(";\n");
}
void CodeVisitor::visit(VariableAssignmentNode& VariableAssignmentNode) {
    appendCode(VariableAssignmentNode.getIdentifier());
    appendCode(" = ");
    VariableAssignmentNode.getValue()->accept(*this);
    appendCode(";\n");
}
void CodeVisitor::visit(ListElementsNode& listElementsNode) {}

void CodeVisitor::visit(ArrayDeclarationNode& arrayDeclarationNode) {
    symbolTable.vectors.find(arrayDeclarationNode.getIdentifier())->second->accept(*this);
    appendCode(arrayDeclarationNode.getIdentifier());
    appendCode("[");
    arrayDeclarationNode.getSize()->accept(*this);
    appendCode("];\n");
}
void CodeVisitor::visit(ArrayAssignmentNode& arrayAssignmentNode) {
    appendCode(arrayAssignmentNode.getIdentifier());
    appendCode("[");
    arrayAssignmentNode.getIndex()->accept(*this);
    appendCode("] = ");
    arrayAssignmentNode.getValue()->accept(*this);
    appendCode(";\n");
}
void CodeVisitor::visit(IfElseNode& ifElseNode) {
    appendCode("if (");
    ifElseNode.condition->accept(*this);
    appendCode(") {\n");
    indentLevel++;
    for (CommandNode* command : ifElseNode.getIfCommands()) {
        indent();
        command->accept(*this);
        appendCode("\n");
    }
    indentLevel--;
    indent();
    appendCode("}\n");
    if(ifElseNode.has_else) {
        indent();
        appendCode("else {\n");
        indentLevel++;
        for (CommandNode* command : ifElseNode.getElseCommands()) {
            indent();
            command->accept(*this);
            appendCode("\n");
        }
        indentLevel--;
        indent();
        appendCode("}\n");
    }
}
void CodeVisitor::visit(WhileNode& whileNode) {
    appendCode("while (");
    whileNode.condition->accept(*this);
    appendCode(") {\n");
    indentLevel++;
    for (CommandNode* command : whileNode.getCommands()) {
        indent();
        command->accept(*this);
        appendCode("\n");
    }
    indentLevel--;
    indent();
    appendCode("}\n");
}
void CodeVisitor::visit(ForNode& forNode) {
    appendCode("for (int ");
    appendCode(forNode.getIdentifier());
    appendCode(" = ");
    forNode.initialvalue->accept(*this);
    appendCode("; ");
    appendCode(forNode.getIdentifier());
    appendCode(" <= ");
    forNode.finalvalue->accept(*this);
    appendCode("; ");
    appendCode(forNode.getIdentifier());
    appendCode("++) {\n");
    
    indentLevel++;
    for (CommandNode* command : forNode.getCommands()) {
        indent();
        command->accept(*this);
    }
    indentLevel--;
    indent();
    appendCode("}\n");
}
void CodeVisitor::visit(AdditionOperatorNode& additionOperatorNode) {
    additionOperatorNode.getLeft()->accept(*this);
    appendCode(" + ");
    additionOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(SubtractionOperatorNode& subtractionOperatorNode) {
    subtractionOperatorNode.getLeft()->accept(*this);
    appendCode(" - ");
    subtractionOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(MultiplicationOperatorNode& multiplicationOperatorNode) {
    multiplicationOperatorNode.getLeft()->accept(*this);
    appendCode(" * ");
    multiplicationOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(DivisionOperatorNode& divisionOperatorNode) {
    divisionOperatorNode.getLeft()->accept(*this);
    appendCode(" / ");
    divisionOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(EqualityOperatorNode& equalityOperatorNode) {
    equalityOperatorNode.getLeft()->accept(*this);
    appendCode(" == ");
    equalityOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(InequalityOperatorNode& inequalityOperatorNode) {
    inequalityOperatorNode.getLeft()->accept(*this);
    appendCode(" != ");
    inequalityOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(LessThanOrEqualOperatorNode& lessThanOrEqualOperatorNode) {
    lessThanOrEqualOperatorNode.getLeft()->accept(*this);
    appendCode(" <= ");
    lessThanOrEqualOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(LessThanOperatorNode& lessThanOperatorNode) {
    lessThanOperatorNode.getLeft()->accept(*this);
    appendCode(" < ");
    lessThanOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(GreaterThanOrEqualOperatorNode& greaterThanOrEqualOperatorNode) {
    greaterThanOrEqualOperatorNode.getLeft()->accept(*this);
    appendCode(" >= ");
    greaterThanOrEqualOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(GreaterThanOperatorNode& greaterThanOperatorNode) {
    greaterThanOperatorNode.getLeft()->accept(*this);
    appendCode(" > ");
    greaterThanOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(LogicalAndOperatorNode& logicalAndOperatorNode) {
    logicalAndOperatorNode.getLeft()->accept(*this);
    appendCode(" && ");
    logicalAndOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(LogicalOrOperatorNode& logicalOrOperatorNode) {
    logicalOrOperatorNode.getLeft()->accept(*this);
    appendCode(" || ");
    logicalOrOperatorNode.getRight()->accept(*this);
}
void CodeVisitor::visit(NotOperatorNode& notOperatorNode) {
    appendCode("!");
    notOperatorNode.getExpression()->accept(*this);
}
void CodeVisitor::visit(InputNode& inputNode) {
    appendCode("std::cin >> ");
    appendCode(inputNode.getIdentifier());
    appendCode(";\n");
}
void CodeVisitor::visit(OutputNode& outputNode) {
    appendCode("std::cout << ");
    outputNode.getExpression()->accept(*this);
    if (outputNode.line) {
        appendCode(" << std::endl");
    }
    appendCode(";\n");
}

