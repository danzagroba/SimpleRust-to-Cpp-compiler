#include "SemanticVisitor.h"

bool SemanticVisitor::compareTypes(TypeNode* type1, TypeNode* type2)
{
    if (!type1 || !type2) {
        return false;
    }
    
    if(dynamic_cast<IntegerTypeNode*>(type1) && dynamic_cast<IntegerTypeNode*>(type2)) {
        return true;
    }
    else if(dynamic_cast<FloatTypeNode*>(type1) && dynamic_cast<FloatTypeNode*>(type2)) {
        return true;
    }
    else if(dynamic_cast<BooleanTypeNode*>(type1) && dynamic_cast<BooleanTypeNode*>(type2)) {
        return true;
    }
    else if(dynamic_cast<FloatTypeNode*>(type1) && dynamic_cast<IntegerTypeNode*>(type2)) {
        return true; //Float can be assigned from Integer
    }
    else{
        return false;
    }
    
}

SemanticVisitor::SemanticVisitor(SymbolTable& symbolTable)
    : symbolTable(symbolTable), lastType(nullptr) {}

SemanticVisitor::~SemanticVisitor() {
    if(lastType) {
        delete lastType;
    }
}

void SemanticVisitor::visit(class Node& node) {}
void SemanticVisitor::visit(class CommandNode& commandNode) {}
void SemanticVisitor::visit(class TypeNode& typeNode) {}
void SemanticVisitor::visit(class ExpressionNode& expressionNode) {}
void SemanticVisitor::visit(class LogicalExpressionNode& logicalExpressionNode) {
    delete lastType; 
    lastType = new BooleanTypeNode();
}
void SemanticVisitor::visit(class ArithmeticExpressionNode& arithmeticExpressionNode) {}
void SemanticVisitor::visit(class MainFunctionNode& mainFunctionNode) {
    for (CommandNode* command : mainFunctionNode.getCommands()) {
        command->accept(*this);
    }
}
void SemanticVisitor::visit(class IntegerLiteralNode& integerLiteralNode) {
    delete lastType; 
    lastType = new IntegerTypeNode();
}
void SemanticVisitor::visit(class FloatLiteralNode& floatLiteralNode) {
    delete lastType;
    lastType = new FloatTypeNode();
}
void SemanticVisitor::visit(class BooleanLiteralNode& booleanLiteralNode) {
    delete lastType;
    lastType = new BooleanTypeNode();
}
void SemanticVisitor::visit(class IdentifierNode& identifierNode) {
    delete lastType;
    lastType = nullptr;
    auto it = symbolTable.variables.find(identifierNode.getIdentifier());
    if (it != symbolTable.variables.end()) {
        TypeNode* FoundType = it->second;
        if (dynamic_cast<IntegerTypeNode*>(FoundType)) {
            lastType = new IntegerTypeNode();
        } else if (dynamic_cast<FloatTypeNode*>(FoundType)) {
            lastType = new FloatTypeNode();
        } else if (dynamic_cast<BooleanTypeNode*>(FoundType)) {
            lastType = new BooleanTypeNode();
        }
    } else {
        cerr << "[ERROR] Identifier not found: " << identifierNode.getIdentifier() << endl;
    }
    
}

void SemanticVisitor::visit(ArrayAcessNode& arrayAccessNode) {
    arrayAccessNode.index->accept(*this);
    TypeNode* indexType = lastType;
    lastType = nullptr;

    if (indexType && !dynamic_cast<IntegerTypeNode*>(indexType)) {
        cerr << "[ERROR] Index must be of type Integer for array access."<< arrayAccessNode.getIdentifier() << endl;
    }
    delete indexType;
    arrayAccessNode.identifier->accept(*this);
}

void SemanticVisitor::visit(VariableDeclarationNode& variableDeclarationNode) {
    if(variableDeclarationNode.initialValue)
    {
        TypeNode* varType = nullptr;
        auto it = symbolTable.variables.find(variableDeclarationNode.getIdentifier());
        if (it != symbolTable.variables.end()) {
            varType = it->second;
        } else {
            cerr << "[ERROR] Trying to assign a variable that does not exist: " << variableDeclarationNode.getIdentifier() << endl;
            return;
        }

        variableDeclarationNode.initialValue->accept(*this);
        TypeNode* expressionType = lastType;
        lastType = nullptr;

        if (!compareTypes(varType, expressionType)) {
            cerr << "[ERROR] Type of the expression is incompatible with the variable type: " << variableDeclarationNode.getIdentifier() << endl;
        }

        delete expressionType;
    }   
}

void SemanticVisitor::visit(VariableAssignmentNode& node) {
    TypeNode* varType = nullptr;
    auto it = symbolTable.variables.find(node.getIdentifier());
    if (it != symbolTable.variables.end()) {
        varType = it->second;
    } else {
        cerr << "[ERROR] Trying to assign a variable that does not exist: " << node.getIdentifier() << endl;
        return;
    }

    node.value->accept(*this);
    TypeNode* expressionType = lastType;
    lastType = nullptr;

    if (!compareTypes(varType, expressionType)) {
        cerr << "[ERROR] Type of the expression is incompatible with the variable type: " << node.getIdentifier() << endl;
    }

    delete expressionType;
}

void SemanticVisitor::visit(ListElementsNode& listElementsNode) {
    const auto& elements = listElementsNode.getElements();


    TypeNode* expectedType = listElementsNode.getType();

    for (size_t i = 1; i < elements.size(); ++i) {
        elements[i]->accept(*this);
        TypeNode* currentElementType = lastType;
        lastType = nullptr;

        if (!compareTypes(expectedType, currentElementType)) {
            cerr << "[ERROR] Inconsistents types on list of initialing vector." << endl;
        }
        
        delete currentElementType;
    }
    if (dynamic_cast<IntegerTypeNode*>(expectedType)) {
        lastType = new IntegerTypeNode();
    } else if (dynamic_cast<FloatTypeNode*>(expectedType)) {
        lastType = new FloatTypeNode();
    } else if (dynamic_cast<BooleanTypeNode*>(expectedType)) {
        lastType = new BooleanTypeNode();
    }
    lastType = expectedType; 
}

void SemanticVisitor::visit(ArrayAssignmentNode& arrayAssignmentNode) {
    TypeNode* varType = nullptr;
    auto it = symbolTable.variables.find(arrayAssignmentNode.getIdentifier());
    if (it != symbolTable.variables.end()) {
        varType = it->second;
    } else {
        cerr << "[ERROR] Trying to assign to an array that does not exist: " << arrayAssignmentNode.getIdentifier() << endl;
        return;
    }

    arrayAssignmentNode.index->accept(*this);
    TypeNode* indexType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<IntegerTypeNode*>(indexType)) {
        cerr << "[ERROR] Index must be of type Integer for array access: " << arrayAssignmentNode.getIdentifier() << endl;
    }

    delete indexType;

    arrayAssignmentNode.value->accept(*this);
    TypeNode* valueType = lastType;
    lastType = nullptr;

    if (!compareTypes(varType, valueType)) {
        cerr << "[ERROR] Type of the value is incompatible with the array type: " << arrayAssignmentNode.getIdentifier() << endl;
    }

    delete valueType;
}

void SemanticVisitor::visit(IfElseNode& IfElseNode)
{
    IfElseNode.condition->accept(*this);
    TypeNode* conditionType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<BooleanTypeNode*>(conditionType)) {
        cerr << "[ERROR] Condition must be of type Boolean in If-Else statement." << endl;
    }

    delete conditionType;

    for (CommandNode* command : IfElseNode.getIfCommands()) {
        command->accept(*this);
    }

    if(IfElseNode.has_else)
    {
        for (CommandNode* command : IfElseNode.getElseCommands()) {
            command->accept(*this);
        }
    }
}

void SemanticVisitor::visit(WhileNode& whileNode) {
    whileNode.condition->accept(*this);
    TypeNode* conditionType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<BooleanTypeNode*>(conditionType)) {
        cerr << "[ERROR] Condition must be of type Boolean in While statement." << endl;
    }

    delete conditionType;

    for (CommandNode* command : whileNode.getCommands()) {
        command->accept(*this);
    }
}

void SemanticVisitor::visit(ForNode& forNode) {
    forNode.initialvalue->accept(*this);
    TypeNode* initialType = lastType;
    forNode.finalvalue->accept(*this);
    TypeNode* finalType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<IntegerTypeNode*>(initialType) || !dynamic_cast<IntegerTypeNode*>(finalType)) {
        cerr << "[ERROR] Initial and final values must be of type Integer in For loop." << endl;
    }
    delete initialType;
    delete finalType;

    for (CommandNode* command : forNode.getCommands()) {
        command->accept(*this);
    }
}

void SemanticVisitor::visit(AdditionOperatorNode& additionOperatorNode) {
    additionOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    additionOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Addition must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType) || dynamic_cast<FloatTypeNode*>(rightType)) {
        lastType = new FloatTypeNode();
    } else {
        lastType = new IntegerTypeNode();
    }

    delete leftType;
    delete rightType;
}

void SemanticVisitor::visit(SubtractionOperatorNode& subtractionOperatorNode) {
    subtractionOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    subtractionOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Subtraction must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType) || dynamic_cast<FloatTypeNode*>(rightType)) {
        lastType = new FloatTypeNode();
    } else {
        lastType = new IntegerTypeNode();
    }

    delete leftType;
    delete rightType;
}

void SemanticVisitor::visit(MultiplicationOperatorNode& multiplicationOperatorNode) {
    multiplicationOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    multiplicationOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Multiplication must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType) || dynamic_cast<FloatTypeNode*>(rightType)) {
        lastType = new FloatTypeNode();
    } else {
        lastType = new IntegerTypeNode();
    }

    delete leftType;
    delete rightType;
}

void SemanticVisitor::visit(DivisionOperatorNode& divisionOperatorNode) {
    divisionOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    divisionOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Division must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType) || dynamic_cast<FloatTypeNode*>(rightType)) {
        lastType = new FloatTypeNode();
    } else {
        lastType = new IntegerTypeNode();
    }

    delete leftType;
    delete rightType;
}

void SemanticVisitor::visit(EqualityOperatorNode& equalityOperatorNode) {
    equalityOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    equalityOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Equality must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(InequalityOperatorNode& inequalityOperatorNode) {
    inequalityOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    inequalityOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Inequality must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(LessThanOrEqualOperatorNode& lessThanOrEqualOperatorNode) {
    lessThanOrEqualOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    lessThanOrEqualOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Less Than or Equal must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(LessThanOperatorNode& lessThanOperatorNode) {
    lessThanOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    lessThanOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Less Than must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(GreaterThanOrEqualOperatorNode& greaterThanOrEqualOperatorNode) {
    delete lastType;
    lastType = nullptr;
    greaterThanOrEqualOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    greaterThanOrEqualOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Greater Than or Equal must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(GreaterThanOperatorNode& greaterThanOperatorNode) {
    delete lastType;
    lastType = nullptr;
    greaterThanOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    greaterThanOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!compareTypes(leftType, rightType)) {
        cerr << "[ERROR] Types of operands in Greater Than must be compatible." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(LogicalAndOperatorNode& logicalAndOperatorNode) {
    delete lastType;
    lastType = nullptr;
    logicalAndOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    logicalAndOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<BooleanTypeNode*>(leftType) || !dynamic_cast<BooleanTypeNode*>(rightType)) {
        cerr << "[ERROR] Both operands in Logical And must be of type Boolean." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(LogicalOrOperatorNode& logicalOrOperatorNode) {
    delete lastType;
    lastType = nullptr;
    logicalOrOperatorNode.getLeft()->accept(*this);
    TypeNode* leftType = lastType;
    lastType = nullptr;
    logicalOrOperatorNode.getRight()->accept(*this);
    TypeNode* rightType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<BooleanTypeNode*>(leftType) || !dynamic_cast<BooleanTypeNode*>(rightType)) {
        cerr << "[ERROR] Both operands in Logical Or must be of type Boolean." << endl;
    }
    lastType = new BooleanTypeNode();

    delete leftType;
    delete rightType;
}
void SemanticVisitor::visit(NotOperatorNode& notOperatorNode) {
    delete lastType;
    lastType = nullptr;
    notOperatorNode.getExpression()->accept(*this);
    TypeNode* expressionType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<BooleanTypeNode*>(expressionType)) {
        cerr << "[ERROR] Operand in Not Operator must be of type Boolean." << endl;
    }
    lastType = new BooleanTypeNode();

    delete expressionType;

}

void SemanticVisitor::visit(InputNode& InputNode) {
    delete lastType;
    lastType = nullptr;
    InputNode.identifier->accept(*this);
    TypeNode* identifierType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<IntegerTypeNode*>(identifierType) && 
        !dynamic_cast<FloatTypeNode*>(identifierType) && 
        !dynamic_cast<BooleanTypeNode*>(identifierType)) {
        cerr << "[ERROR] Input identifier must be of type Integer, Float, or Boolean." << endl;
    }

    delete identifierType;
}
void SemanticVisitor::visit(OutputNode& outputNode) {
    outputNode.getExpression()->accept(*this);
    TypeNode* expressionType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<IntegerTypeNode*>(expressionType) && 
        !dynamic_cast<FloatTypeNode*>(expressionType) && 
        !dynamic_cast<BooleanTypeNode*>(expressionType)) {
        cerr << "[ERROR] Output expression must be of type Integer, Float, or Boolean." << endl;
    }

    delete expressionType;
}
void SemanticVisitor::visit(OutputlnNode& outputlnNode) {
    outputlnNode.getExpression()->accept(*this);
    TypeNode* expressionType = lastType;
    lastType = nullptr;

    if (!dynamic_cast<IntegerTypeNode*>(expressionType) && 
        !dynamic_cast<FloatTypeNode*>(expressionType) && 
        !dynamic_cast<BooleanTypeNode*>(expressionType)) {
        cerr << "[ERROR] Output expression must be of type Integer, Float, or Boolean." << endl;
    }

    delete expressionType;
}