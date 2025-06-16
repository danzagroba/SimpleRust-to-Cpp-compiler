#pragma once
#include <iostream>
using namespace std;
#include <vector>


// Base class for all nodes in the AST
class Node 
{
public:
    virtual ~Node() = default; 
    virtual void accept(class Visitor& visitor) = 0;
};


class CommandNode: public Node
{
    public:
    CommandNode() = default;
    ~CommandNode() override = default;
    
    void accept(class Visitor& visitor) override = 0;
};


class TypeNode: public Node
{
    public:
    TypeNode() = default;
    ~TypeNode() override = default;
    
    void accept(class Visitor& visitor) override;
};

class ExpressionNode: public Node
{
public:
    ExpressionNode() = default;
    ~ExpressionNode() override = default;

    void accept(class Visitor& visitor) override = 0;
};

class LogicalExpressionNode: public ExpressionNode
{
public:
    LogicalExpressionNode() = default;
    ~LogicalExpressionNode() override = default;

    void accept(class Visitor& visitor) override = 0;
};

class ArithmeticExpressionNode: public ExpressionNode
{
public:
    ArithmeticExpressionNode() = default;
    ~ArithmeticExpressionNode() override = default;

    void accept(class Visitor& visitor) override = 0;
};

class MainFunctionNode: public Node
{
    private:
    vector<CommandNode*> commands;
    
    public:
    MainFunctionNode() = default;
    ~MainFunctionNode() override {
        for (CommandNode* command : commands) {
            delete command;
        }
    }
    
    void accept(class Visitor& visitor) override;
    
    void addCommand(class CommandNode* command);
    const vector<class CommandNode*>& getCommands() const;
};

class IntegerLiteralNode: public ExpressionNode
{
public:
    int value;

    IntegerLiteralNode(int value): value(value) {}
    ~IntegerLiteralNode() override;

    void accept(class Visitor& visitor) override;

    int getValue() const;
};

class FloatLiteralNode: public ExpressionNode
{
public:
    float value;

    FloatLiteralNode(float value): value(value) {}
    ~FloatLiteralNode() override;

    void accept(class Visitor& visitor) override;

    float getValue() const;
};

class BooleanLiteralNode: public ExpressionNode
{
public:
    bool value;

    BooleanLiteralNode(bool value): value(value) {}
    ~BooleanLiteralNode() override;

    void accept(class Visitor& visitor) override;

    bool getValue() const;
};


class IdentifierNode: public ExpressionNode
{
public:
    string identifier;

    IdentifierNode(const string& identifier): identifier(identifier) {}
    ~IdentifierNode() override;

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
};
    
class IntegerTypeNode: public TypeNode
{
public:
    IntegerTypeNode() = default;
    ~IntegerTypeNode() override = default;

    void accept(class Visitor& visitor) override;
};

class FloatTypeNode: public TypeNode
{
public:
    FloatTypeNode() = default;
    ~FloatTypeNode() override = default;

    void accept(class Visitor& visitor) override;
};

class BooleanTypeNode: public TypeNode
{
public:
    BooleanTypeNode() = default;
    ~BooleanTypeNode() override = default;

    void accept(class Visitor& visitor) override;
};

class ListElementsNode: public Node
{
private:
    vector<ExpressionNode*> elements;
    
public:
    ListElementsNode(): elements() {}
    ~ListElementsNode() override
    {
        for (ExpressionNode* element : elements) {
            if(element != nullptr)
            {
                delete element;
                element = nullptr;
            }
        }
    }

    void accept(class Visitor& visitor) override;

    void addElement(ExpressionNode* element);
    const vector<ExpressionNode*>& getElements() const;
};

class VariableDeclarationNode: public CommandNode
{
public:
    bool isMut;
    TypeNode* type;
    IdentifierNode* identifier;
    ExpressionNode* initialValue; // if nullptr the variable is not initialized

    VariableDeclarationNode(TypeNode* t, IdentifierNode* id, bool isMut = false, ExpressionNode* initialValue = nullptr);
    ~VariableDeclarationNode() override
    {
        delete type;
        delete identifier;
        if(initialValue != nullptr)
        {
            delete initialValue;
        }
    }

    void accept(class Visitor& visitor) override;

    TypeNode* getType() const;
    const string& getIdentifier() const;
};

class ArrayDeclarationNode: public CommandNode
{
public:
//The arrays are mutable by default, so the isMut flag is not needed here
TypeNode* type;
IdentifierNode* identifier;
ExpressionNode* size;
ListElementsNode* initialElements;

ArrayDeclarationNode(TypeNode* type, IdentifierNode* id, ExpressionNode* size, bool isMut = false, ListElementsNode* list = nullptr)
    : type(type), identifier(id), size(size), initialElements(list)
{
    if (initialElements == nullptr) {
        initialElements = new ListElementsNode();
    }
}
~ArrayDeclarationNode() override
{
    delete type;
    delete identifier;
    delete size;
    if(initialElements != nullptr)
    {
        delete initialElements;
    }
}

    void accept(class Visitor& visitor) override;
    
    TypeNode* getType() const;
    const string& getIdentifier() const;
    ExpressionNode* getSize() const;
};

class ArrayAcessNode: public ExpressionNode
{
public:
    IdentifierNode* identifier;
    ExpressionNode* index;

    ArrayAcessNode(IdentifierNode* id, ExpressionNode* idx): identifier(id), index(idx) {}
    ~ArrayAcessNode() override
    {
        delete identifier;
        delete index;
    }

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
    ExpressionNode* getIndex() const;
};

class ScalarAssignmentNode: public CommandNode
{
public:
    IdentifierNode* identifier;
    ExpressionNode* value;

    ScalarAssignmentNode(IdentifierNode* id, ExpressionNode* val): identifier(id), value(val) {}
    ~ScalarAssignmentNode() override
    {
        delete identifier;
        delete value;
    }

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
    ExpressionNode* getValue() const;
};

class ArrayAssignmentNode: public CommandNode
{
    public:
    IdentifierNode* identifier;
    ExpressionNode* index; 
    ExpressionNode* value;
    
    ArrayAssignmentNode(IdentifierNode* id, ExpressionNode* idx, ExpressionNode* val): identifier(id), index(idx), value(val) {}
    ~ArrayAssignmentNode() override
    {
        delete identifier;
        delete index;
        delete value;
    }
    
    void accept(class Visitor& visitor) override;
    
    const string& getIdentifier() const;
    ExpressionNode* getIndex() const;
    ExpressionNode* getValue() const;
};


class IfElseNode: public CommandNode
{
    public:
    LogicalExpressionNode* condition;
    vector<CommandNode*> ifCommands;
    vector<CommandNode*> elseCommands;
    
    IfElseNode(LogicalExpressionNode* cond): condition(cond) {}
    ~IfElseNode() override
    {
        delete condition;
        for (CommandNode* command : ifCommands) {
            delete command;
        }
        for (CommandNode* command : elseCommands) {
            delete command;
        }
    }
    
    void accept(class Visitor& visitor) override;
    
    void addIfCommand(CommandNode* command);
    void addElseCommand(CommandNode* command);
    
    const vector<CommandNode*>& getIfCommands() const;
    const vector<CommandNode*>& getElseCommands() const;
};

class WhileNode: public CommandNode
{
    public:
    LogicalExpressionNode* condition;
    vector<CommandNode*> commands;
    
    WhileNode(LogicalExpressionNode* cond): condition(cond) {}
    ~WhileNode() override
    {
        delete condition;
        for (CommandNode* command : commands) {
            delete command;
        }
    }
    
    void accept(class Visitor& visitor) override;
    
    void addCommand(CommandNode* command);
    const vector<CommandNode*>& getCommands() const;
};

class ForNode: public CommandNode
{
    public:
    static int count; // used to define the name of the variable in the for loop, like "it0", "it1", etc.
    ArithmeticExpressionNode* initialvalue;  //"0"..5
    ArithmeticExpressionNode* finalvalue;   //0.."5"
    string variableName;
    vector<CommandNode*> commands; 
    
    ForNode(ArithmeticExpressionNode* initial, ArithmeticExpressionNode* final)
        : initialvalue(initial), finalvalue(final), variableName("it" + to_string(count))
    {
        count++;
    }
    {
        variableName = "it" + count; // Default variable name, can be changed if needed
        count++;

    }
    ~ForNode() override
    {
        delete initialvalue;
        delete finalvalue;
        for (CommandNode* command : commands) {
            delete command;
        }
    }
    
    void accept(class Visitor& visitor) override;
    
    void addCommand(CommandNode* command);
    const vector<CommandNode*>& getCommands() const;
};


// +
class AdditionOperatorNode: public ArithmeticExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    AdditionOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~AdditionOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// -
class SubtractionOperatorNode: public ArithmeticExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    SubtractionOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~SubtractionOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// *
class MultiplicationOperatorNode: public ArithmeticExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    MultiplicationOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~MultiplicationOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// /
class DivisionOperatorNode: public ArithmeticExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    DivisionOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~DivisionOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// ==
class EqualityOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    EqualityOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~EqualityOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// !=
class InequalityOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    InequalityOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~InequalityOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// <=
class LessThanOrEqualOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    LessThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~LessThanOrEqualOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// <
class LessThanOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    LessThanOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~LessThanOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// >=
class GreaterThanOrEqualOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    GreaterThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~GreaterThanOrEqualOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// >
class GreaterThanOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    GreaterThanOperatorNode(ExpressionNode* left, ExpressionNode* right): left(left), right(right) {}
    ~GreaterThanOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// &&
class LogicalAndOperatorNode: public LogicalExpressionNode
{
public:
    LogicalExpressionNode* left;
    LogicalExpressionNode* right;

    LogicalAndOperatorNode(LogicalExpressionNode* left, LogicalExpressionNode* right): left(left), right(right) {}
    ~LogicalAndOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    LogicalExpressionNode* getLeft() const;
    LogicalExpressionNode* getRight() const;
};

// ||
class LogicalOrOperatorNode: public LogicalExpressionNode
{
public:
    LogicalExpressionNode* left;
    LogicalExpressionNode* right;

    LogicalOrOperatorNode(LogicalExpressionNode* left, LogicalExpressionNode* right): left(left), right(right) {}
    ~LogicalOrOperatorNode() override
    {
        delete left;
        delete right;
    }

    void accept(class Visitor& visitor) override;

    LogicalExpressionNode* getLeft() const;
    LogicalExpressionNode* getRight() const;
};

// !
class NotOperatorNode: public LogicalExpressionNode
{
public:
    LogicalExpressionNode* expression;

    NotOperatorNode(LogicalExpressionNode* expr): expression(expr) {}
    ~NotOperatorNode() override
    {
        delete expression;
    }

    void accept(class Visitor& visitor) override;

    LogicalExpressionNode* getExpression() const;
};

class InputNode: public CommandNode
{
public:
    IdentifierNode* identifier;

    InputNode(IdentifierNode* id): identifier(id) {}
    ~InputNode() override
    {
        delete identifier;
    }

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
};

class OutputNode: public CommandNode
{
public:
    ExpressionNode* expression;

    OutputNode(ExpressionNode* expr): expression(expr) {}
    ~OutputNode() override
    {
        delete expression;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getExpression() const;
};

class OutputlnNode: public CommandNode
{
public:
    ExpressionNode* expression;

    OutputlnNode(ExpressionNode* expr): expression(expr) {}
    ~OutputlnNode() override
    {
        delete expression;
    }

    void accept(class Visitor& visitor) override;

    ExpressionNode* getExpression() const;
};


