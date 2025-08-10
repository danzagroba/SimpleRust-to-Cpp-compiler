%{
#define ERROR_START "[ERROR] " <<  __LINE__  << ": "
#include <iostream>
using namespace std;
#include "AST.h"
#include "SymbolTable.h"
#include "SemanticVisitor.h"
#include "CodeVisitor.h"

int yylex(void);
int yywrap(void);
void yyerror(const char* s);
    
SymbolTable st;
ProgramNode* ast_root = nullptr;

%}

%union {
    int     ival;
    float   fval;
    std::string* str;
    bool    boolean;

    //AST Nodes
    Node* node_ptr;
    CommandNode* command_node_ptr;
    vector<CommandNode*>* command_list_ptr; 
    TypeNode* type_node_ptr;
    ExpressionNode* expr_node_ptr;
    std::vector<ExpressionNode*>* expr_list_ptr;
    LogicalExpressionNode* logical_expr_node_ptr;
    ArithmeticExpressionNode* arith_expr_node_ptr;
    MainFunctionNode* main_func_node_ptr;
    FunctionNode* function_node_ptr;
    FunctionCallCommandNode* function_command_node_ptr;
    FunctionCallExpressionNode* function_expr_node_ptr;
    std::vector<FunctionNode*>* function_list_ptr;
    ParameterNode* parameter_node_ptr; 
    ReturnNode* return_node_ptr;
    vector<ParameterNode*>* parameter_list_ptr;
    IdentifierNode* id_node_ptr;
    IntegerLiteralNode* int_literal_node_ptr;
    FloatLiteralNode* float_literal_node_ptr;
    BooleanLiteralNode* bool_literal_node_ptr;
    VariableDeclarationNode* var_decl_node_ptr;
    ListElementsNode* list_elements_node_ptr;
    ArrayDeclarationNode* array_decl_node_ptr; 
    VariableAssignmentNode* Variable_assign_node_ptr; 
    ArrayAssignmentNode* array_assign_node_ptr; 
    IfElseNode* if_else_node_ptr; 
    WhileNode* while_node_ptr; 
    ForNode* for_node_ptr; 
    AdditionOperatorNode* add_op_node_ptr; 
    SubtractionOperatorNode* sub_op_node_ptr; 
    MultiplicationOperatorNode* mul_op_node_ptr; 
    DivisionOperatorNode* div_op_node_ptr; 
    EqualityOperatorNode* eq_op_node_ptr; 
    InequalityOperatorNode* ne_op_node_ptr; 
    LessThanOrEqualOperatorNode* le_op_node_ptr; 
    LessThanOperatorNode* lt_op_node_ptr; 
    GreaterThanOrEqualOperatorNode* ge_op_node_ptr; 
    GreaterThanOperatorNode* gt_op_node_ptr; 
    LogicalAndOperatorNode* and_op_node_ptr; 
    LogicalOrOperatorNode* or_op_node_ptr; 
    NotOperatorNode* not_op_node_ptr; 
    InputNode* input_node_ptr; 
    OutputNode* output_node_ptr; 
    ArrayAcessNode* array_access_node_ptr; 

};


%start program



/*=========================================================================
                            TOKENS
=========================================================================*/


%token FUNCTION MAIN RETURN

%token <str> ID

%token TINT TFLOAT TBOOL

%token <ival> INTEGER
%token <fval> FLOATING

%token LET MUT COLON COMMA ARROW

%token LEFT RIGHT LBRACE RBRACE LBRACKET RBRACKET

%token NOT AND OR

%token TRUE FALSE

%token ATRIB EQ NE LT LE GT GE

%token IF ELSE

%token FOR IN TO
%token WHILE

%token READ WRITE WRITELN

%token EOL 

%token '+' '-' '*' '/'

%type <main_func_node_ptr> program
%type <command_list_ptr> commands
%type <command_node_ptr> command
%type <function_list_ptr> fns
%type <function_node_ptr> fn
%type <parameter_list_ptr> parameters
%type <parameter_node_ptr> parameter
%type <type_node_ptr> TYPE
%type <var_decl_node_ptr> declaration
%type <array_decl_node_ptr> array_declaration
%type <Variable_assign_node_ptr> assign
%type <array_assign_node_ptr> array_assign
%type <if_else_node_ptr> if_else_command
%type <for_node_ptr> for_command
%type <while_node_ptr> while_command
%type <function_command_node_ptr> function_command


%type <expr_node_ptr> expression
%type <expr_list_ptr> expr_list
%type <arith_expr_node_ptr> arithmetic_expression
%type <logical_expr_node_ptr> logical_expression

%type <expr_node_ptr> factor
%type <expr_node_ptr> term

%type <input_node_ptr> read_command
%type <output_node_ptr> write_command

%type <return_node_ptr> return_command

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left '+' '-'
%left '*' '/'
%right NOT


/*=========================================================================
                            GRAMMAR RULES
=========================================================================*/
%%
program: fns FUNCTION MAIN LEFT RIGHT LBRACE commands RBRACE { 
        cout<< "Program Started." << endl;
        ast_root = new ProgramNode();
        MainFunctionNode* main_func_node_ptr = new MainFunctionNode();
        std::vector<CommandNode*>* cmds_list = $7;
        for (CommandNode* cmd : *cmds_list) {
            main_func_node_ptr->addCommand(cmd);
        }
        ast_root->mainFunction = main_func_node_ptr;
        ast_root->functions = $1;
        delete cmds_list;
    }
    ;
fns: fns fn
    {
        $$ = $1;
        $$->push_back($2);
        //cout << "[INFO] " << "\t Function added to function list." << endl;
    }
    | fn
    {
        $$ = new std::vector<FunctionNode*>();
        $$->push_back($1);
        //cout << "[INFO] " << "\t Function added to function list." << endl;
    }
    ;

fn: FUNCTION ID LEFT parameters RIGHT ARROW TYPE LBRACE commands RBRACE { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$2);
        TypeNode* return_type_node_ptr = $7;

        FunctionNode* function_node_ptr = new FunctionNode(id_node_ptr, return_type_node_ptr);

        std::vector<ParameterNode*>* prmt_list = $4;
        for (ParameterNode* prmt : *prmt_list) {
            function_node_ptr->addParameter(prmt);
            st.variables.insert({prmt->identifier->getIdentifier(), prmt->getType()});
        }
        delete prmt_list;
        
        std::vector<CommandNode*>* cmds_list = $9;
        for (CommandNode* cmd : *cmds_list) {
            function_node_ptr->addCommand(cmd);
        }
        delete cmds_list;

        $$ = function_node_ptr;
        st.functions.insert({id_node_ptr->getIdentifier(), return_type_node_ptr});
        st.functionNodes.insert({id_node_ptr->getIdentifier(), function_node_ptr});
        //cout << "[INFO] " << "\t Function " << *$2 << " added to AST." << endl;
        delete $2;
    }
    | FUNCTION ID LEFT RIGHT ARROW TYPE LBRACE commands RBRACE { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$2);
        TypeNode* return_type_node_ptr = $6;

        FunctionNode* function_node_ptr = new FunctionNode(id_node_ptr, return_type_node_ptr);

        std::vector<CommandNode*>* cmds_list = $8;
        for (CommandNode* cmd : *cmds_list) {
            function_node_ptr->addCommand(cmd);
        }
        delete cmds_list;

        $$ = function_node_ptr;
        st.functions.insert({id_node_ptr->getIdentifier(), return_type_node_ptr});
        st.functionNodes.insert({id_node_ptr->getIdentifier(), function_node_ptr});
        //cout << "[INFO] " << "\t Function " << *$2 << " added to AST." << endl;
        delete $2;
    }
    ;

expr_list: expression
    {
        $$ = new std::vector<ExpressionNode*>();
        $$->push_back($1);
        //cout << "[INFO] " << "\t Expression added to expression list." << endl;    
    }
    | expr_list COMMA expression
    {
        $$ = $1;
        $$->push_back($3);
        //cout << "[INFO] " << "\t Expression added to expression list." << endl;    
    }
    ;

parameters: parameter
    {
        $$ = new std::vector<ParameterNode*>();
        $$->push_back($1);
        //cout << "[INFO] " << "\t Parameter added to parameter list." << endl;    
    }
    | parameters COMMA parameter
    {
        $$ = $1;
        $$->push_back($3);
        //cout << "[INFO] " << "\t Parameter added to parameter list." << endl;    
    }
    ;

parameter:MUT ID COLON TYPE
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*$2);
        TypeNode* type_node_ptr = $4;

        $$ = new ParameterNode(id_node_ptr, type_node_ptr);
        //cout << "[INFO] " << "\t Parameter " << *$2 << " added to AST." << endl;
        delete $2;
    }
    ;

commands: command 
    {
        $$ = new std::vector<CommandNode*>();
        $$->push_back($1);
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
    | commands command
    {
        $$ = $1;
        $$->push_back($2);
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    };

command: declaration { $$ = $1; }
    | array_declaration { $$ = $1; }
    | assign { $$ = $1; }
    | array_assign { $$ = $1; }
    | if_else_command { $$ = $1; }
    | for_command { $$ = $1; }
    | while_command { $$ = $1; }
    | read_command { $$ = $1; }
    | write_command { $$ = $1; }
    | return_command { $$ = $1; }
    | function_command {$$ = $1; }
    ;

TYPE: TINT { $$ = new IntegerTypeNode(); }
    | TFLOAT { $$ = new FloatTypeNode(); }
    | TBOOL { $$ = new BooleanTypeNode; }
    ;

declaration:

    LET MUT ID COLON TYPE EOL
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*$3);

        TypeNode* type_node_ptr = $5;

        $$ = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable/Constant " << *$3 << " added to AST." << endl;
        delete $3;
    }
    | LET MUT ID COLON TYPE ATRIB expression EOL
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*$3);

        TypeNode* type_node_ptr = $5;
    
        $$ = new VariableDeclarationNode(type_node_ptr, id_node_ptr, $7);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable " << *$3 << " added to AST." << endl;
        delete $3;
    }
;

array_declaration: LET MUT ID COLON LBRACKET TYPE EOL expression RBRACKET EOL
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*$3);
    TypeNode* type_node_ptr = $6;

    $$ = new ArrayDeclarationNode(type_node_ptr, id_node_ptr, $8);
    st.vectors.insert({id_node_ptr->getIdentifier(), type_node_ptr});

    //cout << "[INFO] " << "\t Array " << *$3 << " added to AST." << endl;
    delete $3;
}
;
assign: ID ATRIB expression EOL
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
    if(st.variables.find(id_node_ptr->getIdentifier()) != st.variables.end()) {
        $$ = new VariableAssignmentNode(id_node_ptr, $3);
        //cout << "[INFO] " << "\t Variable assignment for " << *$1 << " added to AST." << endl;
    }
    else {
        yyerror("Identifier not declared.");
        delete id_node_ptr;
        $$ = nullptr;
    }
    delete $1;
}
;
array_assign: ID LBRACKET expression RBRACKET ATRIB expression EOL
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
    if(st.vectors.find(id_node_ptr->getIdentifier()) != st.vectors.end()) {
        $$ = new ArrayAssignmentNode(id_node_ptr, $3, $6);
        //cout << "[INFO] " << "\t Array assignment for " << *$1 << " added to AST." << endl;
    } 
    else {
        yyerror("Array identifier not declared.");
        delete id_node_ptr;
        $$ = nullptr;
    }
    delete $1;
}

if_else_command: IF logical_expression LBRACE commands RBRACE ELSE LBRACE commands RBRACE {
        IfElseNode* if_else = new IfElseNode($2, true);
        
        std::vector<CommandNode*>* cmds_list = $4;
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        cmds_list = $8;
        for (CommandNode* cmd : *cmds_list) {
            if_else->addElseCommand(cmd);
        }
        delete cmds_list;
        $$ = if_else;
        //cout << "[INFO] " << "\t If-Else command AST node created." << endl;
    } 
    | IF logical_expression LBRACE commands RBRACE{
        IfElseNode* if_else = new IfElseNode($2, false);
        
        std::vector<CommandNode*>* cmds_list = $4;
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        $$ = if_else;
        //cout << "[INFO] " << "\t If command AST node created." << endl;
    }
;

for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE {
        IdentifierNode* iterator_id_node = new IdentifierNode(*($3));

        ForNode* for_node = new ForNode(iterator_id_node, $5, $7);

        std::vector<CommandNode*>* cmds_list = $9;
        for (CommandNode* cmd : *cmds_list) {
            for_node->addCommand(cmd);
        }
        delete cmds_list;

        $$ = for_node;

         //cout << "[INFO] " << "\t For loop command AST node created." << endl;

        delete $3;
    }
;
while_command: WHILE logical_expression LBRACE commands RBRACE
{
    WhileNode* while_node = new WhileNode($2);
    std::vector<CommandNode*>* cmds_list = $4;
    for (CommandNode* cmd : *cmds_list) {
        while_node->addCommand(cmd);
    }
    delete cmds_list;

    $$ = while_node;
    //cout << "[INFO] " << "\t While loop command AST node created." << endl;
} 

read_command: READ LEFT ID RIGHT EOL
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*($3));
        $$ = new InputNode(id_node_ptr);
        //cout << "[INFO] " << "\t Input command AST node created." << endl;
        delete $3;
    }
    ;

write_command: WRITE LEFT expression RIGHT EOL
    {
        $$ = new OutputNode($3,false);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
    | WRITELN LEFT expression RIGHT EOL
    {
        $$ = new OutputNode($3, true);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
    ;

return_command: RETURN expression EOL
    {
        $$ = new ReturnNode($2);
        //cout << "[INFO] " << "\t Return command AST node created." << endl;
    }

function_command: ID LEFT expr_list RIGHT EOL
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        if(st.functions.find(id_node_ptr->getIdentifier()) != st.functions.end()) {
            FunctionCallCommandNode* function_call_node_ptr = new FunctionCallCommandNode(id_node_ptr, $3);
            $$ = function_call_node_ptr;
            //cout << "[INFO] " << "\t Function call for " << *$1 << " added to AST." << endl;
        } 
        else {
            yyerror("Function not declared.");
            delete id_node_ptr;
            $$ = nullptr;
        }
        delete $1;
    }
    | ID LEFT RIGHT EOL
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        if(st.functions.find(id_node_ptr->getIdentifier()) != st.functions.end()) {
            FunctionCallCommandNode* function_call_node_ptr = new FunctionCallCommandNode(id_node_ptr, new std::vector<ExpressionNode*>());
            $$ = function_call_node_ptr;
            //cout << "[INFO] " << "\t Function call for " << *$1 << " added to AST." << endl;
        } 
        else {
            yyerror("Function not declared.");
            delete id_node_ptr;
            $$ = nullptr;
        }
        delete $1;
    }
    ;

expression: arithmetic_expression { $$ = $1; }
    | logical_expression { $$ = $1; }
    ;

arithmetic_expression: arithmetic_expression '+' arithmetic_expression
    { 
        $$ = new AdditionOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
    | arithmetic_expression '-' arithmetic_expression
    { 
        $$ = new SubtractionOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
    | term
    { 
        $$ = static_cast<ArithmeticExpressionNode*>($1); 
        //cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
    ;

logical_expression: expression AND expression
    { 
        $$ = new LogicalAndOperatorNode($1, $3);
        //cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
    | expression OR expression
    { 
        $$ = new LogicalOrOperatorNode($1, $3);
        //cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
    | NOT expression
    { 
        $$ = new NotOperatorNode($2); 
        //cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
    | expression EQ expression
    { 
        $$ = new EqualityOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
    | expression NE expression
    { 
        $$ = new InequalityOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
    | expression LT expression
    { 
        $$ = new LessThanOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
    | expression LE expression
    { 
        $$ = new LessThanOrEqualOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
    | expression GT expression
    { 
        $$ = new GreaterThanOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
    | expression GE expression
    { 
        $$ = new GreaterThanOrEqualOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
    | LEFT logical_expression RIGHT
    { 
        $$ = $2; 
        //cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
    ;

term: factor
    | term '*' factor
    { 
        $$ = new MultiplicationOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
    | term '/' factor
    { 
        $$ = new DivisionOperatorNode($1, $3); 
        //cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
    ;
    
factor: INTEGER 
    { 
        $$ = new IntegerLiteralNode($1); 
        //cout << "[INFO] " << "\t Integer literal " << $1 << " added to AST." << endl;
    }
    | FLOATING 
    { 
        $$ = new FloatLiteralNode($1); 
        //cout << "[INFO] " << "\t Float literal " << $1 << " added to AST." << endl;
    }
    | ID 
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        $$ = id_node_ptr; 
        //cout << "[INFO] " << "\t Identifier " << *$1 << " added to AST." << endl;
        delete $1;
    }
    | ID LBRACKET expression RBRACKET
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        $$ = new ArrayAcessNode(id_node_ptr, $3);
        //cout << "[INFO] " << "\t Array access for " << *$1 << " added to AST." << endl;
        delete $1;
    }
    | ID LEFT expr_list RIGHT
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        $$ = new FunctionCallExpressionNode(id_node_ptr, $3);
        //cout << "[INFO] " << "\t Function call for " << *$1 << " added to AST." << endl;
        delete $1;
    }
    | ID LEFT RIGHT
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*$1);
        $$ = new FunctionCallExpressionNode(id_node_ptr, new std::vector<ExpressionNode*>());
        //cout << "[INFO] " << "\t Function call for " << *$1 << " added to AST." << endl;
        delete $1;
    }
    | LEFT expression RIGHT 
    { 
        $$ = $2; 
        //cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
    | TRUE 
    { 
        $$ = new BooleanLiteralNode(true); 
        //cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
    | FALSE 
    { 
        $$ = new BooleanLiteralNode(false); 
        //cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
    ;

%%



int main() { 
    int parse_result = yyparse();
    int semantic_result = false;
    if (parse_result == 0) 
    {
        cout << "Parsing successful!" << endl;
        if(ast_root){
            SemanticVisitor semantic(st);
            ast_root->accept(semantic);
            if(semantic.hasError) {
                cout << "Semantic errors found." << endl;
            } else {
                cout << "Semantic analysis completed successfully." << endl;
            }
            semantic_result = semantic.hasError;
        }
    } 
    else 
    {
        cout << "Parsing failed." << endl;
    }

    if(parse_result == 0 && ast_root && semantic_result == 0)
    {
        CodeVisitor code(st);
        ast_root->accept(code);
        code.createFinalCode();
    }
    delete ast_root;
    ast_root = nullptr;
    return parse_result;
}