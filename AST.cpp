#include "AST.h"
#include "Visitor.h"

void Node::print(int indent) {
    for(int i = 0; i < indent; ++i) std::cout << "  ";
    std::cout << typeid(*this).name() << " @ " << this << std::endl;
}

MainFunctionNode::~MainFunctionNode() {
    for (CommandNode* command : commands) {
        delete command;
    }
}

void MainFunctionNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

void MainFunctionNode::print(int indent) {
    Node::print(indent); 
    for (CommandNode* command : commands) {
        if (command) {
            command->print(indent + 1); 
        }
    }
}

void MainFunctionNode::addCommand(CommandNode* command) {
    commands.push_back(command);
}

const vector<CommandNode*>& MainFunctionNode::getCommands() const {
    return commands;
}

FunctionNode::FunctionNode(IdentifierNode* id, TypeNode* returnType): identifier(id), returnType(returnType) {}

FunctionNode::~FunctionNode() {
    returnType = nullptr;
    for (CommandNode* command : commands) {
        delete command;
    }
    for (ParameterNode* param : parameters) {
        delete param;
    }
}

void FunctionNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

void FunctionNode::print(int indent) {
    Node::print(indent); 
    for (CommandNode* command : commands) {
        if (command) {
            command->print(indent + 1); 
        }
    }
}

void FunctionNode::addParameter(ParameterNode* parameter) {
    parameters.push_back(parameter);
}

const vector<ParameterNode*>& FunctionNode::getParameters() const {
    return parameters;
}

void FunctionNode::addCommand(CommandNode* command) {
    commands.push_back(command);
}

const vector<CommandNode*>& FunctionNode::getCommands() const {
    return commands;
}

void ProgramNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ProgramNode::ProgramNode() : mainFunction(nullptr) {}

ProgramNode::~ProgramNode() {
    for (FunctionNode* function : *functions) {
        delete function;
    }
    delete mainFunction;
}
void ProgramNode::addFunction(FunctionNode* function) {
    functions->push_back(function);
}
const vector<FunctionNode*>* ProgramNode::getFunctions() const {
    return functions;
}

FunctionCallCommandNode::FunctionCallCommandNode(IdentifierNode* id, std::vector<ExpressionNode*>* args): identifier(id), arguments(args) {}
FunctionCallCommandNode::~FunctionCallCommandNode() {
    delete identifier;
    for (ExpressionNode* arg : *arguments) {
        delete arg;
        arg = nullptr;
    }
    delete arguments;
}

void FunctionCallCommandNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

FunctionCallExpressionNode::FunctionCallExpressionNode(IdentifierNode* id, std::vector<ExpressionNode*>* args): identifier(id), arguments(args) {}
FunctionCallExpressionNode::~FunctionCallExpressionNode() {
    delete identifier;
    for (ExpressionNode* arg : *arguments) {
        delete arg;
        arg = nullptr;
    }
    delete arguments;
}

void FunctionCallExpressionNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}


ReturnNode::ReturnNode(ExpressionNode* rv) : returnValue(rv) {}

ReturnNode::~ReturnNode() {
    delete returnValue;
}

void ReturnNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ExpressionNode* ReturnNode::getReturnValue() const {
    return returnValue;
}

ParameterNode::ParameterNode(IdentifierNode* id, TypeNode* t): type(t), identifier(id) 
{
    
}

ParameterNode::~ParameterNode() {
    delete type;
    delete identifier;
}

void ParameterNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

TypeNode* ParameterNode::getType() const {
    return type;
}
const string& ParameterNode::getIdentifier() const {
    return identifier->getIdentifier();
}


IntegerLiteralNode::IntegerLiteralNode(int value): value(value) {}

void IntegerLiteralNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

int IntegerLiteralNode::getValue() const {
    return value;
}

FloatLiteralNode::FloatLiteralNode(float value): value(value) {} 

void FloatLiteralNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

float FloatLiteralNode::getValue() const {
    return value;
}

BooleanLiteralNode::BooleanLiteralNode(bool value): value(value) {}

void BooleanLiteralNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

bool BooleanLiteralNode::getValue() const {
    return value;
}

IdentifierNode::IdentifierNode(const string& identifier): identifier(identifier) {}

void IdentifierNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

const string& IdentifierNode::getIdentifier() const {
    return identifier;
}

void IntegerTypeNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

void FloatTypeNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
void BooleanTypeNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ListElementsNode::ListElementsNode(TypeNode* t): type(t), elements() {}

ListElementsNode::~ListElementsNode() {
    for (ExpressionNode* element : elements) {
        if(element != nullptr)
        {
            delete element;
            element = nullptr;
        }
    }
}

TypeNode* ListElementsNode::getType() const {
    return type;
}

void ListElementsNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

void ListElementsNode::addElement(ExpressionNode* element) {
    elements.push_back(element);
}

const vector<ExpressionNode*>& ListElementsNode::getElements() const {
    return elements;
}

VariableDeclarationNode::VariableDeclarationNode(TypeNode* t, IdentifierNode* id, ExpressionNode* iv)
: type(t), identifier(id), initialValue(iv) { }

VariableDeclarationNode::~VariableDeclarationNode() {
    delete type;
    delete identifier;
    if(initialValue != nullptr) {
        delete initialValue;
    }
}

void VariableDeclarationNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

TypeNode* VariableDeclarationNode::getType() const {
    return type;
}

const string& VariableDeclarationNode::getIdentifier() const {
    return identifier->getIdentifier();
}

void ArrayDeclarationNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ArrayDeclarationNode::ArrayDeclarationNode(TypeNode* type, IdentifierNode* id, ExpressionNode* size)
    : type(type), identifier(id), size(size)
{
}

ArrayDeclarationNode::~ArrayDeclarationNode() {
    delete type;
    delete identifier;
    delete size;
}

TypeNode* ArrayDeclarationNode::getType() const {
    return type;
}

const string& ArrayDeclarationNode::getIdentifier() const {
    return identifier->getIdentifier();
}

ExpressionNode* ArrayDeclarationNode::getSize() const {
    return size;
}

ArrayAcessNode::ArrayAcessNode(IdentifierNode* id, ExpressionNode* idx)
    : identifier(id), index(idx) {}

ArrayAcessNode::~ArrayAcessNode() {
    delete identifier;
    delete index;
}

void ArrayAcessNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
const string& ArrayAcessNode::getIdentifier() const {
    return identifier->getIdentifier();
}

ExpressionNode* ArrayAcessNode::getIndex() const {
    return index;
}

VariableAssignmentNode::VariableAssignmentNode(IdentifierNode* id, ExpressionNode* val)
    : identifier(id), value(val) {}

VariableAssignmentNode::~VariableAssignmentNode() {
    delete identifier;
    delete value;
}

void VariableAssignmentNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

const string& VariableAssignmentNode::getIdentifier() const {
    return identifier->getIdentifier();
}
ExpressionNode* VariableAssignmentNode::getValue() const {
    return value;
}

void ArrayAssignmentNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ArrayAssignmentNode::ArrayAssignmentNode(IdentifierNode* id, ExpressionNode* idx, ExpressionNode* val)
    : identifier(id), index(idx), value(val) {}

ArrayAssignmentNode::~ArrayAssignmentNode() {
    delete identifier;
    delete index;
    delete value;
}

const string& ArrayAssignmentNode::getIdentifier() const {
    return identifier->getIdentifier();
}

ExpressionNode* ArrayAssignmentNode::getIndex() const {
    return index;
}

ExpressionNode* ArrayAssignmentNode::getValue() const {
    return value;
}

IfElseNode::IfElseNode(LogicalExpressionNode* condition, bool has_e)
    : condition(condition), has_else(has_e) {}

IfElseNode::~IfElseNode() {
    delete condition;
    for (CommandNode* command : ifCommands) {
        if(command != nullptr) {
            delete command;
        }
    }
    if(has_else)
    {
        for (CommandNode* command : elseCommands) {
           if(command != nullptr) { 
                delete command;
            }
        }
    }
}

void IfElseNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
void IfElseNode::addIfCommand(CommandNode* command) {
    ifCommands.push_back(command);
}
void IfElseNode::addElseCommand(CommandNode* command) {
    elseCommands.push_back(command);
}
const vector<CommandNode*>& IfElseNode::getIfCommands() const {
    return ifCommands;
}
const vector<CommandNode*>& IfElseNode::getElseCommands() const {
    return elseCommands;
}

WhileNode::WhileNode(LogicalExpressionNode* cond)
    : condition(cond) {}

WhileNode::~WhileNode() {
    delete condition;
    for (CommandNode* command : commands) {
        if(command != nullptr) {
            delete command;
        }
    }
}

void WhileNode::addCommand(CommandNode* command) {
    commands.push_back(command);
}

void WhileNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
const vector<CommandNode*>& WhileNode::getCommands() const {
    return commands;
}

ForNode::ForNode(IdentifierNode* id,ArithmeticExpressionNode* initial, ArithmeticExpressionNode* final)
    : identifier(id), initialvalue(initial), finalvalue(final)
{
}

ForNode::~ForNode()
{
    delete identifier;
    delete initialvalue;
    delete finalvalue;
    for (CommandNode* command : commands) {
        delete command;
    }
}

void ForNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

const string& ForNode::getIdentifier() const {
    return identifier->getIdentifier();
}

void ForNode::addCommand(CommandNode* command) {
    commands.push_back(command);
} 

const vector<CommandNode*>& ForNode::getCommands() const {
    return commands;
}

void AdditionOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ExpressionNode* AdditionOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* AdditionOperatorNode::getRight() const {
    return right;
}

AdditionOperatorNode::AdditionOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

AdditionOperatorNode::~AdditionOperatorNode() {
    delete left;
    delete right;
}


SubtractionOperatorNode::SubtractionOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

SubtractionOperatorNode::~SubtractionOperatorNode() {
    delete left;
    delete right;
}
void SubtractionOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* SubtractionOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* SubtractionOperatorNode::getRight() const {
    return right;
}

MultiplicationOperatorNode::MultiplicationOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

MultiplicationOperatorNode::~MultiplicationOperatorNode() {
    delete left;
    delete right;
}

void MultiplicationOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ExpressionNode* MultiplicationOperatorNode::getLeft() const {
    return left;
}

ExpressionNode* MultiplicationOperatorNode::getRight() const {
    return right;
}

DivisionOperatorNode::DivisionOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

DivisionOperatorNode::~DivisionOperatorNode() {
    delete left;
    delete right;
}

void DivisionOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ExpressionNode* DivisionOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* DivisionOperatorNode::getRight() const {
    return right;
}

EqualityOperatorNode::EqualityOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

EqualityOperatorNode::~EqualityOperatorNode() {
    delete left;
    delete right;
}

void EqualityOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

ExpressionNode* EqualityOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* EqualityOperatorNode::getRight() const {
    return right;
}

InequalityOperatorNode::InequalityOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

InequalityOperatorNode::~InequalityOperatorNode() {
    delete left;
    delete right;
}
void InequalityOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* InequalityOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* InequalityOperatorNode::getRight() const {
    return right;
}

LessThanOrEqualOperatorNode::LessThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}
LessThanOrEqualOperatorNode::~LessThanOrEqualOperatorNode() {
    delete left;
    delete right;
}
void LessThanOrEqualOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* LessThanOrEqualOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* LessThanOrEqualOperatorNode::getRight() const {
    return right;
}

LessThanOperatorNode::LessThanOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}
LessThanOperatorNode::~LessThanOperatorNode() {
    delete left;
    delete right;
}
void LessThanOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* LessThanOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* LessThanOperatorNode::getRight() const {
    return right;
}

GreaterThanOrEqualOperatorNode::GreaterThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}
GreaterThanOrEqualOperatorNode::~GreaterThanOrEqualOperatorNode() {
    delete left;
    delete right;
}
void GreaterThanOrEqualOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* GreaterThanOrEqualOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* GreaterThanOrEqualOperatorNode::getRight() const {
    return right;
}

GreaterThanOperatorNode::GreaterThanOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}

GreaterThanOperatorNode::~GreaterThanOperatorNode() {
    delete left;
    delete right;
}
void GreaterThanOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* GreaterThanOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* GreaterThanOperatorNode::getRight() const {
    return right;
}

LogicalAndOperatorNode::LogicalAndOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}
LogicalAndOperatorNode::~LogicalAndOperatorNode() {
    delete left;
    delete right;
}
void LogicalAndOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* LogicalAndOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* LogicalAndOperatorNode::getRight() const {
    return right;
}

LogicalOrOperatorNode::LogicalOrOperatorNode(ExpressionNode* left, ExpressionNode* right)
: left(left), right(right) {}
LogicalOrOperatorNode::~LogicalOrOperatorNode() {
    delete left;
    delete right;
}
void LogicalOrOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* LogicalOrOperatorNode::getLeft() const {
    return left;
}
ExpressionNode* LogicalOrOperatorNode::getRight() const {
    return right;
}

NotOperatorNode::NotOperatorNode(ExpressionNode* expr)
: expression(expr) {}
NotOperatorNode::~NotOperatorNode() {
    delete expression;
}
void NotOperatorNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* NotOperatorNode::getExpression() const {
    return expression;
}
void LogicalExpressionNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}

InputNode::InputNode(IdentifierNode* id)
: identifier(id) {}
InputNode::~InputNode() {
    delete identifier;
}
void InputNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
const string& InputNode::getIdentifier() const {
    return identifier->getIdentifier();
}

OutputNode::OutputNode(ExpressionNode* expr, bool ln)
: expression(expr), line(ln) {}
OutputNode::~OutputNode() {
    delete expression;
}
void OutputNode::accept(class Visitor& visitor) {
    visitor.visit(*this);
}
ExpressionNode* OutputNode::getExpression() const {
    return expression;
}





