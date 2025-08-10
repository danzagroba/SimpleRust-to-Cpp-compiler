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
    else{
        return false;
    }
    
}

SemanticVisitor::SemanticVisitor(SymbolTable& symbolTable)
    : symbolTable(symbolTable), lastType(nullptr), hasError(false) {}

SemanticVisitor::~SemanticVisitor() {
}

void SemanticVisitor::visit(class Node& node) {}
void SemanticVisitor::visit(class CommandNode& commandNode) {}
void SemanticVisitor::visit(class TypeNode& typeNode) {}
void SemanticVisitor::visit(class ExpressionNode& expressionNode) {}
void SemanticVisitor::visit(class LogicalExpressionNode& logicalExpressionNode) {
    lastType = std::make_unique<BooleanTypeNode>();
}
void SemanticVisitor::visit(class ArithmeticExpressionNode& arithmeticExpressionNode) {}

void SemanticVisitor::visit(class MainFunctionNode& mainFunctionNode) {
    for (CommandNode* command : mainFunctionNode.getCommands()) {
        command->accept(*this);
    }
}
void SemanticVisitor::visit(class FunctionNode& functionNode) {
    bool hasReturn = false;
    for (ParameterNode* param : functionNode.getParameters()) {
        param->accept(*this);
    }
    for (CommandNode* command : functionNode.getCommands()) {
        command->accept(*this);
        if(dynamic_cast<ReturnNode*>(command)) {
            std::unique_ptr<TypeNode> returnNodeType = move(lastType);
            if(!compareTypes(functionNode.returnType, returnNodeType.get()))
            {
                hasError = true;
                cerr << "[ERROR] Return type mismatch in function: " << functionNode.identifier->getIdentifier() << endl;
            }
            else {
                hasReturn = true;
            }
        }
    }
    if(!hasReturn) {
        hasError = true;
        cerr << "[ERROR] Missing return statement in function: " << functionNode.identifier->getIdentifier() << endl;
    }
}

void SemanticVisitor::visit(class FunctionCallCommandNode& functionCallNode) {
    auto it = symbolTable.functions.find(functionCallNode.identifier->getIdentifier());
    auto itNode = symbolTable.functionNodes.find(functionCallNode.identifier->getIdentifier());
    if (it != symbolTable.functions.end() || itNode != symbolTable.functionNodes.end()) {
        FunctionNode* function = itNode->second;
        if (functionCallNode.arguments->size() != function->getParameters().size()) {
            hasError = true;
            cerr << "[ERROR] Function call argument count mismatch for function: " << functionCallNode.identifier->getIdentifier() << endl;
        } else {
            for (size_t i = 0; i < functionCallNode.arguments->size(); ++i) {
                (*functionCallNode.arguments)[i]->accept(*this);
                std::unique_ptr<TypeNode> argumentType = move(lastType);
                if (!compareTypes(function->getParameters()[i]->getType(), argumentType.get())) {
                    hasError = true;
                    cerr << "[ERROR] Type mismatch for argument " << i + 1 << " in function call: " << functionCallNode.identifier->getIdentifier() << endl;
                }
            }
        }
    } else {
        hasError = true;
        cerr << "[ERROR] Function not found: " << functionCallNode.identifier->getIdentifier() << endl;
    }
}

void SemanticVisitor::visit(class FunctionCallExpressionNode& functionCallNode) {
    auto it = symbolTable.functions.find(functionCallNode.identifier->getIdentifier());
    auto itNode = symbolTable.functionNodes.find(functionCallNode.identifier->getIdentifier());
    if (it != symbolTable.functions.end() && itNode != symbolTable.functionNodes.end()) {
        
        FunctionNode* function = itNode->second;
        if (functionCallNode.arguments->size() != function->getParameters().size()) {
            hasError = true;
            cerr << "[ERROR] Function call argument count mismatch for function: " << functionCallNode.identifier->getIdentifier() << endl;
        } else {
            for (size_t i = 0; i < functionCallNode.arguments->size(); ++i) {
                (*functionCallNode.arguments)[i]->accept(*this);
                std::unique_ptr<TypeNode> argumentType = move(lastType);
                if (!compareTypes(function->getParameters()[i]->getType(), argumentType.get())) {
                    hasError = true;
                    cerr << "[ERROR] Type mismatch for argument " << i + 1 << " in function call: " << functionCallNode.identifier->getIdentifier() << endl;
                }
            }
            functionCallNode.identifier->accept(*this);
        }
    } else {
        hasError = true;
        cerr << "[ERROR] Function not found: " << functionCallNode.identifier->getIdentifier() << endl;
    }
}

void SemanticVisitor::visit(class ProgramNode& programNode) {
    for (FunctionNode* function : (*programNode.functions)) {
        function->accept(*this);
    }
    if ((*programNode.functions).empty()) {
        hasError = true;
        cerr << "[ERROR] Program must contain at least one function." << endl;
    }
    if (programNode.mainFunction) {
        programNode.mainFunction->accept(*this);
    }
    else {
        hasError = true;
        cerr << "[ERROR] Program must contain a main function." << endl;
    }
}

void SemanticVisitor::visit(class ParameterNode& parameterNode) {}

void SemanticVisitor::visit(class ReturnNode& returnNode) {
    returnNode.returnValue->accept(*this);
}
void SemanticVisitor::visit(class IntegerLiteralNode& integerLiteralNode) {
    lastType = std::make_unique<IntegerTypeNode>();
}
void SemanticVisitor::visit(class FloatLiteralNode& floatLiteralNode) {
    lastType = std::make_unique<FloatTypeNode>();
}
void SemanticVisitor::visit(class BooleanLiteralNode& booleanLiteralNode) {
    lastType = std::make_unique<BooleanTypeNode>();
}
void SemanticVisitor::visit(class IdentifierNode& identifierNode) {
    
    auto it = symbolTable.variables.find(identifierNode.getIdentifier());
    if (it != symbolTable.variables.end()) {
        TypeNode* FoundType = it->second;
        if (dynamic_cast<IntegerTypeNode*>(FoundType)) {
            lastType = std::make_unique<IntegerTypeNode>();
        } else if (dynamic_cast<FloatTypeNode*>(FoundType)) {
            lastType = std::make_unique<FloatTypeNode>();
        } else if (dynamic_cast<BooleanTypeNode*>(FoundType)) {
            lastType = std::make_unique<BooleanTypeNode>();
        }
    } else {
        it = symbolTable.vectors.find(identifierNode.getIdentifier());
        if (it != symbolTable.vectors.end()) {
            TypeNode* FoundType = it->second;
            if (dynamic_cast<IntegerTypeNode*>(FoundType)) {
                lastType = std::make_unique<IntegerTypeNode>();
            } else if (dynamic_cast<FloatTypeNode*>(FoundType)) {
                lastType = std::make_unique<FloatTypeNode>();
            } else if (dynamic_cast<BooleanTypeNode*>(FoundType)) {
                lastType = std::make_unique<BooleanTypeNode>();
            }
        
        } else {
            it = symbolTable.functions.find(identifierNode.getIdentifier());
            if (it != symbolTable.functions.end()) {
                TypeNode* FoundType = it->second;
                if (dynamic_cast<IntegerTypeNode*>(FoundType)) {
                    lastType = std::make_unique<IntegerTypeNode>();
                } else if (dynamic_cast<FloatTypeNode*>(FoundType)) {
                    lastType = std::make_unique<FloatTypeNode>();
                } else if (dynamic_cast<BooleanTypeNode*>(FoundType)) {
                    lastType = std::make_unique<BooleanTypeNode>();
                }
            } else {
                hasError = true;
                cerr << "[ERROR] Identifier not found: " << identifierNode.getIdentifier() << endl;
            }
        }
    }
    
}

void SemanticVisitor::visit(ArrayAcessNode& arrayAccessNode) {
    arrayAccessNode.index->accept(*this);
    std::unique_ptr<TypeNode> indexType = move(lastType);
    

    if (indexType && !dynamic_cast<IntegerTypeNode*>(indexType.get())) {
        hasError = true;
        cerr << "[ERROR] Index must be of type Integer for array access."<< arrayAccessNode.getIdentifier() << endl;
    }
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
            hasError = true;
            cerr << "[ERROR] Trying to assign a variable that does not exist: " << variableDeclarationNode.getIdentifier() << endl;
            return;
        }

        variableDeclarationNode.initialValue->accept(*this);
        std::unique_ptr<TypeNode> expressionType = move(lastType);
        

        if (!compareTypes(varType, expressionType.get())) {
            hasError = true;
            cerr << "[ERROR] Type of the expression is incompatible with the variable type: " << variableDeclarationNode.getIdentifier() << endl;
        }

    }   
}

void SemanticVisitor::visit(VariableAssignmentNode& node) {
    TypeNode* varType = nullptr;
    auto it = symbolTable.variables.find(node.getIdentifier());
    if (it != symbolTable.variables.end()) {
        varType = it->second;
    } else {
        hasError = true;
        cerr << "[ERROR] Trying to assign a variable that does not exist: " << node.getIdentifier() << endl;
        return;
    }

    node.value->accept(*this);
    std::unique_ptr<TypeNode> expressionType = move(lastType);
    

    if (!compareTypes(varType, expressionType.get())) {
        hasError = true;
        cerr << "[ERROR] Type of the expression is incompatible with the variable type: " << node.getIdentifier() << endl;
    }

}

void SemanticVisitor::visit(ListElementsNode& listElementsNode) {
    const auto& elements = listElementsNode.getElements();


    TypeNode* expectedType = listElementsNode.getType();

    for (size_t i = 1; i < elements.size(); ++i) {
        elements[i]->accept(*this);
        std::unique_ptr<TypeNode> currentElementType = move(lastType);
        

        if (!compareTypes(expectedType, currentElementType.get())) {
            hasError = true;
            cerr << "[ERROR] Inconsistents types on list of initialing vector." << endl;
        }
        
    }
    if (dynamic_cast<IntegerTypeNode*>(expectedType)) {
        lastType = std::make_unique<IntegerTypeNode>();
    } else if (dynamic_cast<FloatTypeNode*>(expectedType)) {
        lastType = std::make_unique<FloatTypeNode>();
    } else if (dynamic_cast<BooleanTypeNode*>(expectedType)) {
        lastType = std::make_unique<BooleanTypeNode>();
    } else {
        hasError = true;
        cerr << "[ERROR] Unsupported type in listElementsNode.getType()." << endl;
    }
}
void SemanticVisitor::visit(ArrayDeclarationNode& arrayDeclarationNode) {
    TypeNode* varType = nullptr;
    auto it = symbolTable.vectors.find(arrayDeclarationNode.getIdentifier());
    if (it != symbolTable.vectors.end()) {
        varType = it->second;
    }
    else {
        hasError = true;
        cerr << "[ERROR] Trying to declare an array that already exists: " << arrayDeclarationNode.getIdentifier() << endl;
        return;
    }
    arrayDeclarationNode.getSize()->accept(*this);

    std::unique_ptr<TypeNode> sizeType = move(lastType);

    if (!dynamic_cast<IntegerTypeNode*>(sizeType.get())) {
        hasError = true;
        cerr << "[ERROR] Size of the array must be of type Integer: " << arrayDeclarationNode.getIdentifier() << endl;
        return;
    }
    if (!compareTypes(varType, arrayDeclarationNode.getType())) {
        hasError = true;
        cerr << "[ERROR] Type of the array is incompatible with the declared type: " << arrayDeclarationNode.getIdentifier() << endl;
        return;
    }
}
    

void SemanticVisitor::visit(ArrayAssignmentNode& arrayAssignmentNode) {
    TypeNode* varType = nullptr;
    auto it = symbolTable.vectors.find(arrayAssignmentNode.getIdentifier());
    if (it != symbolTable.vectors.end()) {
        varType = it->second;
    } else {
        hasError = true;
        cerr << "[ERROR] Trying to assign to an array that does not exist: " << arrayAssignmentNode.getIdentifier() << endl;
        return;
    }

    arrayAssignmentNode.index->accept(*this);
    std::unique_ptr<TypeNode> indexType = move(lastType);
    

    if (!dynamic_cast<IntegerTypeNode*>(indexType.get())) {
        hasError = true;
        cerr << "[ERROR] Index must be of type Integer for array access: " << arrayAssignmentNode.getIdentifier() << endl;
    }


    arrayAssignmentNode.value->accept(*this);
    std::unique_ptr<TypeNode> valueType = move(lastType);
    

    if (!compareTypes(varType, valueType.get())) {
        hasError = true;
        cerr << "[ERROR] Type of the value is incompatible with the array type: " << arrayAssignmentNode.getIdentifier() << endl;
    }

}

void SemanticVisitor::visit(IfElseNode& IfElseNode)
{
    IfElseNode.condition->accept(*this);
    std::unique_ptr<TypeNode> conditionType = move(lastType);
    

    if (!dynamic_cast<BooleanTypeNode*>(conditionType.get())) {
        hasError = true;
        cerr << "[ERROR] Condition must be of type Boolean in If-Else statement." << endl;
    }


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
    std::unique_ptr<TypeNode> conditionType = move(lastType);
    

    if (!dynamic_cast<BooleanTypeNode*>(conditionType.get())) {
        hasError = true;
        cerr << "[ERROR] Condition must be of type Boolean in While statement." << endl;
    }


    for (CommandNode* command : whileNode.getCommands()) {
        command->accept(*this);
    }
}

void SemanticVisitor::visit(ForNode& forNode) {
    
    string iteratorName = forNode.identifier->getIdentifier();
    auto it = symbolTable.variables.find(iteratorName);
    
    if (it == symbolTable.variables.end()) {
        symbolTable.variables.insert({iteratorName, new IntegerTypeNode()});
        cerr << "[INFO] Iterator '" << iteratorName << "' declared as Integer in symbol table during semantic visit." << endl;
    } else {
        if (!dynamic_cast<IntegerTypeNode*>(it->second)) {
            hasError = true;
            cerr << "[ERROR] For loop iterator must be of type Integer: " << iteratorName << endl;
        }
    }
    
    forNode.initialvalue->accept(*this);
    std::unique_ptr<TypeNode> initialType = move(lastType);
    
    forNode.finalvalue->accept(*this);
    std::unique_ptr<TypeNode> finalType = move(lastType);
    

    if (!dynamic_cast<IntegerTypeNode*>(initialType.get()) || !dynamic_cast<IntegerTypeNode*>(finalType.get())) {
        hasError = true;
        cerr << "[ERROR] Initial and final values must be of type Integer in For loop." << endl;
    }

    for (CommandNode* command : forNode.getCommands()) {
        command->accept(*this);
    }
}

void SemanticVisitor::visit(AdditionOperatorNode& additionOperatorNode) {
    additionOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    additionOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Addition must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType.get()) || dynamic_cast<FloatTypeNode*>(rightType.get())) {
        lastType = std::make_unique<FloatTypeNode>();
    } else {
        lastType = std::make_unique<IntegerTypeNode>();
    }

    
    
}

void SemanticVisitor::visit(SubtractionOperatorNode& subtractionOperatorNode) {
    subtractionOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    subtractionOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Subtraction must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType.get()) || dynamic_cast<FloatTypeNode*>(rightType.get())) {
        lastType = std::make_unique<FloatTypeNode>();
    } else {
        lastType = std::make_unique<IntegerTypeNode>();
    }

    
    
}

void SemanticVisitor::visit(MultiplicationOperatorNode& multiplicationOperatorNode) {
    multiplicationOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    multiplicationOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Multiplication must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType.get()) || dynamic_cast<FloatTypeNode*>(rightType.get())) {
        lastType = std::make_unique<FloatTypeNode>();
    } else {
        lastType = std::make_unique<IntegerTypeNode>();
    }

    
    
}

void SemanticVisitor::visit(DivisionOperatorNode& divisionOperatorNode) {
    divisionOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    divisionOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Division must be compatible." << endl;
    }
    if(dynamic_cast<FloatTypeNode*>(leftType.get()) || dynamic_cast<FloatTypeNode*>(rightType.get())) {
        lastType = std::make_unique<FloatTypeNode>();
    } else {
        lastType = std::make_unique<IntegerTypeNode>();
    }

    
    
}

void SemanticVisitor::visit(EqualityOperatorNode& equalityOperatorNode) {
    equalityOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    equalityOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Equality must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

    
    
}
void SemanticVisitor::visit(InequalityOperatorNode& inequalityOperatorNode) {
    inequalityOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    inequalityOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Inequality must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(LessThanOrEqualOperatorNode& lessThanOrEqualOperatorNode) {
    lessThanOrEqualOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    lessThanOrEqualOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Less Than or Equal must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

    
    
}
void SemanticVisitor::visit(LessThanOperatorNode& lessThanOperatorNode) {
    lessThanOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    lessThanOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Less Than must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(GreaterThanOrEqualOperatorNode& greaterThanOrEqualOperatorNode) {
    greaterThanOrEqualOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    
    greaterThanOrEqualOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);
    

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Greater Than or Equal must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(GreaterThanOperatorNode& greaterThanOperatorNode) {
    
    greaterThanOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);

    greaterThanOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);

    if (!compareTypes(leftType.get(), rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Types of operands in Greater Than must be compatible." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(LogicalAndOperatorNode& logicalAndOperatorNode) {
    logicalAndOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    logicalAndOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);

    if (!dynamic_cast<BooleanTypeNode*>(leftType.get()) || !dynamic_cast<BooleanTypeNode*>(rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Both operands in Logical And must be of type Boolean." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(LogicalOrOperatorNode& logicalOrOperatorNode) {
    logicalOrOperatorNode.getLeft()->accept(*this);
    std::unique_ptr<TypeNode> leftType = move(lastType);
    logicalOrOperatorNode.getRight()->accept(*this);
    std::unique_ptr<TypeNode> rightType = move(lastType);

    if (!dynamic_cast<BooleanTypeNode*>(leftType.get()) || !dynamic_cast<BooleanTypeNode*>(rightType.get())) {
        hasError = true;
        cerr << "[ERROR] Both operands in Logical Or must be of type Boolean." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}
void SemanticVisitor::visit(NotOperatorNode& notOperatorNode) {

    
    notOperatorNode.getExpression()->accept(*this);
    std::unique_ptr<TypeNode> expressionType = move(lastType);
    

    if (!dynamic_cast<BooleanTypeNode*>(expressionType.get())) {
        hasError = true;
        cerr << "[ERROR] Operand in Not Operator must be of type Boolean." << endl;
    }
    lastType = std::make_unique<BooleanTypeNode>();

}

void SemanticVisitor::visit(InputNode& InputNode) {
    InputNode.identifier->accept(*this);
    
    std::unique_ptr<TypeNode> identifierType = move(lastType);

    if (!dynamic_cast<IntegerTypeNode*>(identifierType.get()) && 
        !dynamic_cast<FloatTypeNode*>(identifierType.get()) && 
        !dynamic_cast<BooleanTypeNode*>(identifierType.get())) {
        hasError = true;
        cerr << "[ERROR] Input identifier must be of type Integer, Float, or Boolean." << endl;
    }
}
void SemanticVisitor::visit(OutputNode& outputNode) {
    outputNode.getExpression()->accept(*this);
    std::unique_ptr<TypeNode> expressionType = move(lastType);

    if (!dynamic_cast<IntegerTypeNode*>(expressionType.get()) && 
        !dynamic_cast<FloatTypeNode*>(expressionType.get()) && 
        !dynamic_cast<BooleanTypeNode*>(expressionType.get())) {
        hasError = true;
        cerr << "[ERROR] Output expression must be of type Integer, Float, or Boolean." << endl;
    }
}