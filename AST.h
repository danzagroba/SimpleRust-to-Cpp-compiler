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
    virtual void print(int indent = 0);
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
    
    virtual void accept(class Visitor& visitor) override = 0;
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
    ~MainFunctionNode() override;
    
    void accept(class Visitor& visitor) override;
    
    void print(int indent = 0) override;

    void addCommand(class CommandNode* command);
    const vector<class CommandNode*>& getCommands() const;
};

class IntegerLiteralNode: public ArithmeticExpressionNode
{
public:
    int value;

    IntegerLiteralNode(int value);
    ~IntegerLiteralNode() override = default;

    void accept(class Visitor& visitor) override;

    int getValue() const;
};

class FloatLiteralNode: public ArithmeticExpressionNode
{
public:
    float value;

    FloatLiteralNode(float value);
    ~FloatLiteralNode() override = default;

    void accept(class Visitor& visitor) override;

    float getValue() const;
};

class BooleanLiteralNode: public LogicalExpressionNode
{
public:
    bool value;

    BooleanLiteralNode(bool value);
    ~BooleanLiteralNode() override = default;

    void accept(class Visitor& visitor) override;

    bool getValue() const;
};


class IdentifierNode: public ExpressionNode
{
public:
    string identifier;

    IdentifierNode(const string& identifier);
    ~IdentifierNode() override = default;

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
    TypeNode* type;
    vector<ExpressionNode*> elements;
    
public:
    ListElementsNode(TypeNode* t);
    ~ListElementsNode() override;

    void accept(class Visitor& visitor) override;

    TypeNode* getType() const;
    void addElement(ExpressionNode* element);
    const vector<ExpressionNode*>& getElements() const;
};

class VariableDeclarationNode: public CommandNode
{
public:
    TypeNode* type;
    IdentifierNode* identifier;
    ExpressionNode* initialValue; // if nullptr the variable is not initialized

    VariableDeclarationNode(TypeNode* t, IdentifierNode* id, ExpressionNode* iv = nullptr);
    ~VariableDeclarationNode() override;

    void accept(class Visitor& visitor) override;

    TypeNode* getType() const;
    const string& getIdentifier() const;
};

class ArrayDeclarationNode: public CommandNode
{
public:
//Constants are not supported in this grammar anymore
//In this version vectors can't be initialized
TypeNode* type;
IdentifierNode* identifier;
ExpressionNode* size;

ArrayDeclarationNode(TypeNode* type, IdentifierNode* id, ExpressionNode* size);
~ArrayDeclarationNode() override;

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

    ArrayAcessNode(IdentifierNode* id, ExpressionNode* idx);
    ~ArrayAcessNode() override;

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
    ExpressionNode* getIndex() const;
};

class VariableAssignmentNode: public CommandNode
{
public:
    IdentifierNode* identifier;
    ExpressionNode* value;

    VariableAssignmentNode(IdentifierNode* id, ExpressionNode* val);
    ~VariableAssignmentNode() override;

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
    
    ArrayAssignmentNode(IdentifierNode* id, ExpressionNode* idx, ExpressionNode* val);
    ~ArrayAssignmentNode() override;
    
    void accept(class Visitor& visitor) override;
    
    const string& getIdentifier() const;
    ExpressionNode* getIndex() const;
    ExpressionNode* getValue() const;
};


class IfElseNode: public CommandNode
{
    public:
    LogicalExpressionNode* condition;
    bool has_else;
    vector<CommandNode*> ifCommands;
    vector<CommandNode*> elseCommands;
    
    IfElseNode(LogicalExpressionNode* condition, bool has_e);
    ~IfElseNode() override;
    
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
    
    WhileNode(LogicalExpressionNode* cond);
    ~WhileNode() override;
    
    void accept(class Visitor& visitor) override;
    
    void addCommand(CommandNode* command);
    const vector<CommandNode*>& getCommands() const;
};

class ForNode: public CommandNode
{
    public:
    static int count; // used to define the name of the variable in the for loop, like "it0", "it1", etc.
    IdentifierNode* identifier;
    ExpressionNode* initialvalue;  //"0"..5
    ExpressionNode* finalvalue;   //0.."5"
    vector<CommandNode*> commands; 
    
    ForNode(IdentifierNode* id,ArithmeticExpressionNode* initial, ArithmeticExpressionNode* final);
    ~ForNode() override;
    
    void accept(class Visitor& visitor) override;
    
    const string& getIdentifier() const;
    void addCommand(CommandNode* command);
    const vector<CommandNode*>& getCommands() const;
};


// +
class AdditionOperatorNode: public ArithmeticExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    AdditionOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~AdditionOperatorNode() override;

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

    SubtractionOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~SubtractionOperatorNode() override;

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

    MultiplicationOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~MultiplicationOperatorNode() override;

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

    DivisionOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~DivisionOperatorNode() override;

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

    EqualityOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~EqualityOperatorNode() override;
    
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

    InequalityOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~InequalityOperatorNode() override;

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

    LessThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~LessThanOrEqualOperatorNode() override;
    
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

    LessThanOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~LessThanOperatorNode();

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

    GreaterThanOrEqualOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~GreaterThanOrEqualOperatorNode() override;

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

    GreaterThanOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~GreaterThanOperatorNode() override;

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// &&
class LogicalAndOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    LogicalAndOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~LogicalAndOperatorNode() override;

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// ||
class LogicalOrOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* left;
    ExpressionNode* right;

    LogicalOrOperatorNode(ExpressionNode* left, ExpressionNode* right);
    ~LogicalOrOperatorNode() override;

    void accept(class Visitor& visitor) override;

    ExpressionNode* getLeft() const;
    ExpressionNode* getRight() const;
};

// !
class NotOperatorNode: public LogicalExpressionNode
{
public:
    ExpressionNode* expression;

    NotOperatorNode(ExpressionNode* expr);
    ~NotOperatorNode() override;

    void accept(class Visitor& visitor) override;

    ExpressionNode* getExpression() const;
};

class InputNode: public CommandNode
{
public:
    IdentifierNode* identifier;

    InputNode(IdentifierNode* id);
    ~InputNode() override;

    void accept(class Visitor& visitor) override;

    const string& getIdentifier() const;
};

class OutputNode: public CommandNode
{
public:
    ExpressionNode* expression;
    bool line;

    OutputNode(ExpressionNode* expr, bool ln);
    ~OutputNode() override;

    void accept(class Visitor& visitor) override;

    ExpressionNode* getExpression() const;
};
