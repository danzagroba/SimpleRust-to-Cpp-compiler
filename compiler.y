%{
#define ERROR_START "[ERROR] " <<  __LINE__  << ": "
#include <iostream>
using namespace std;
#include "AST.h"
#include "SymbolTable.h"
//#include "AtribMetadata.h"

int yylex(void);
int yywrap(void);
void yyerror(const char* s);
    
SymbolTable st;
MainFunctionNode* ast_root = nullptr;
%}

%union {
    int     ival;
    float   fval;
    std::string* str;
    bool    boolean;
};


%start program



/*=========================================================================
                            TOKENS
=========================================================================*/


%token FUNCTION MAIN

%token <ival>INTEGER 
%token <fval>FLOATING 

%token <str> ID

%token TINT TFLOAT TBOOL

%token LET MUT COLON

%token LEFT RIGHT LBRACE RBRACE

%token NOT AND OR

%token TRUE FALSE

%token ATRIB EQ NE LT LE GT GE

%token IF THEN ELSE BEGIN_TOKEN END

%token READ WRITE WRITELN

%token EOL 

%type <str> TYPE
%type <boolean> OPT_MUT

//%type <boolean> LOGICAL_EXPR
/*

%type <boolean> logical_expression comparison_expression boolean_factor
%type <fval> expression term factor
%type <atrib_metadata> conditional_atrib else_command
*/

/*=========================================================================
                            GRAMMAR RULES
=========================================================================*/
%%
program: FUNCTION MAIN LEFT RIGHT LBRACE commands RBRACE { cout<< "Program Started." << endl;};

commands: command
    | commands command;

command: declaration
    //| if_command
    //| atrib
    //| read_command
    //| write_command;

TYPE: TINT { $$ = new std::string("INT"); }
    | TFLOAT { $$ = new std::string("FLOAT"); }
    | TBOOL { $$ = new std::string("BOOL"); }
    ;

OPT_MUT: 
    MUT { $$ = true; }
    | /* empty */ { $$ = false; }
    ;
declaration:

    LET OPT_MUT ID COLON TYPE EOL
    {   
        if($2)
        {
            if(st.variables.find(*$3) == st.variables.end())
            {
                st.variables.insert({*$3, *$5});
                cout << "[INFO] " << "\t Variable " << *$3 << " declared as " << *$5 << "." << endl;
            }
            else{
                cout << ERROR_START << "Variable " << *$3 << " already declared." << endl;
                delete $3;
                delete $5;
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if(st.constants.find(*$3) == st.constants.end())
            {
                st.constants.insert({*$3, *$5});
                cout << "[INFO] " << "\t Constant " << *$3 << " declared as " << *$5 << "." << endl;
            }
            else{
                cout << ERROR_START << "Constant " << *$3 << " already declared." << endl;
                delete $3;
                delete $5;
                exit(EXIT_FAILURE);
            }
        }
        delete $3;
        delete $5;
    }

    //EXPR:
    //LOGICAL_EXPR
    //| ARITMETIC_EXPR
    ;

%%


int main() { 

    int parse_result = yyparse();
    if (parse_result == 0) 
    {
        cout << "Parsing successful!" << endl;
        if(ast_root)
        {
            delete ast_root;
            ast_root = nullptr;
        } 
    } 
    else 
    {
        cout << "Parsing failed." << endl;
    }
    return parse_result;
}