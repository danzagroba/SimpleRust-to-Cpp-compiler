%{
#define ERROR_START "[ERROR] " <<  __LINE__  << ": "
#include <iostream>
using namespace std;
#include "SymbolTable.h"
//#include "AtribMetadata.h"

int yylex(void);
int yywrap(void);
void yyerror(const char* s);
    
SymbolTable st;

%}

%union {
    int     ival;
    float   fval;
    std::string* str;
    bool    boolean;
    //AtribMetadata* atrib_metadata;
}


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

%token EOL NEW_LINE

%type <str> TYPE
%type <boolean> OPT_MUT

%type <boolean> LOGICAL_EXPR
/*

%type <boolean> logical_expression comparison_expression boolean_factor
%type <fval> expression term factor
%type <atrib_metadata> conditional_atrib else_command
*/

/*=========================================================================
                            GRAMMAR RULES
=========================================================================*/
%%
//program: FUNCTION MAIN LEFT RIGHT LBRACE commands RBRACE;
program: commands;

commands: command
    | commands command;

command: declaration
    //| if_command
    | atrib
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

    LET OPT_MUT ID COLON TYPE EOL NEW_LINE
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
    /* LET OPT_MUT ID COLON TYPE EQ EXPRESSION EOL NEW_LINE
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
    };*/

    EXPR:
    LOGICAL_EXPR
    | ARITMETIC_EXPR
    ;

/*conditional_atrib: 
    ID ATRIB logical_expression EOL NEW_LINE {
        cout << "[INFO] " << "\t realizando atribuição lógica" << endl;

        AtribMetadata * atrib = nullptr;
        if(st.variables.find(*$1) != st.variables.end())
        {
            if(st.variables[*$1] == "BOOL")
            {
                atrib = new AtribMetadata();
                atrib->type = "BOOL";
                atrib->id = *$1;
                atrib->value.boolValue = static_cast<bool>($3);
                
                $$ = atrib;
            }
            else
            {
                cout << ERROR_START << " Variable " << *$1 << " is not a boolean." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << "is not declared." << endl;
        }
        delete $1;
        if(atrib == nullptr)
        {
            $$ = nullptr;
        }
    }
    // TODO corrigir como os atribs de IDs
    | ID ATRIB expression EOL NEW_LINE {
        cout << "[INFO] " << "\t realizando atribuição de expressao numérica" << endl; 
        // retornar o tipo do id, o id e o valor em uma estrutura
        AtribMetadata * atrib = nullptr;
        if(st.variables.find(*$1) != st.variables.end())
        {
            if(st.variables[*$1] == "INT")
            {
                atrib = new AtribMetadata();
                atrib->type = "INT";
                atrib->id = *$1;
                atrib->value.intValue = static_cast<int>($3);
                
                $$ = atrib;
            }
            else if(st.variables[*$1] == "FLOAT")
            {
                atrib = new AtribMetadata();
                atrib->type = "FLOAT";
                atrib->id = *$1;
                atrib->value.floatValue = static_cast<float>($3);
                
                $$ = atrib;
            }
            else if(st.variables[*$1] == "BOOL")
            {
                atrib = new AtribMetadata();
                atrib->type = "BOOL";
                atrib->id = *$1;
                atrib->value.boolValue = static_cast<bool>($3);
                
                $$ = atrib;
            }
            else 
            {
                cout << ERROR_START << " Variable " << *$1 << " is not a number nor a bool." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << "was not declared." << endl;
        }
        delete $1;
        if(atrib == nullptr)
        {
            $$ = nullptr;
        }
    }
;

else_command: 
    ELSE NEW_LINE BEGIN_TOKEN NEW_LINE conditional_atrib END NEW_LINE { $$ = $5; }
    ;

if_command:
    IF LEFT logical_expression RIGHT THEN NEW_LINE BEGIN_TOKEN NEW_LINE conditional_atrib END NEW_LINE else_command
    {
        bool evaluation_result = $3;

        if(evaluation_result)
        {
            cout << "If condition is true." << endl;
            if($9 != nullptr) {
                if($9->type == "INT")
                {   
                    mm.intTable[$9->id] = $9->value.intValue;
                }   
                else if($9->type == "FLOAT")
                {
                    mm.floatTable[$9->id] = $9->value.floatValue;
                }
                else if($9->type == "BOOL")
                {
                    mm.boolTable[$9->id] = $9->value.boolValue;
                }

            }
            else {
                cout << ERROR_START << " Variable " << $9->id << " not declared." << endl;
            }
            delete $9;
        }
        else
        {
            cout << "If condition is false." << endl;
            if($12 != nullptr) {
                if($12->type == "INT")
                {   
                    mm.intTable[$12->id] = $12->value.intValue;
                }   
                else if($12->type == "FLOAT")
                {
                    mm.floatTable[$12->id] = $12->value.floatValue;
                }
                else if($12->type == "BOOL")
                {
                    mm.boolTable[$12->id] = $12->value.boolValue;
                }

            }
            else {
                cout << ERROR_START << " Variable " << $12->id << " not declared." << endl;
            }
            delete $12;
        }
    };


    

write_command: 
    WRITE LEFT ID RIGHT EOL NEW_LINE {
        if(st.variables.find(*$3) != st.variables.end())
        {
            cout << "Reading variable: " << *$3 << endl;
            if(st.variables[*$3] == "INT")
            {
                cout<<mm.intTable[*$3]<<endl;
            }
            else if(st.variables[*$3] == "FLOAT")
            {
                cout<<mm.floatTable[*$3]<<endl;
            }
            else if(st.variables[*$3] == "BOOL")
            {
                cout<<mm.boolTable[*$3]<<endl;
            }
            else{
                cout << ERROR_START << " Variable " << *$3 << " not declared." << endl;
            }
        }
        else{
            cout << ERROR_START << " Variable " << *$3 << " not declared." << endl;
        }
    };

read_command: 
    READ LEFT ID RIGHT EOL NEW_LINE {
        if(st.variables.find(*$3) != st.variables.end())
        {
            if(st.variables[*$3] == "INT")
            {
                cin >> mm.intTable[*$3];
            }
            else if(st.variables[*$3] == "FLOAT")
            {
                cin >> mm.floatTable[*$3];
            }
            if(st.variables[*$3] == "BOOL")
            {
                cin >> mm.boolTable[*$3];
            }
            else
            {
                cout << ERROR_START << " Variable " << *$3 << " have unknown type." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$3 << "is not declared." << endl;
        }
        delete $3;
    };
    


// an expression uses * or / or neither
term: term '*' factor   { $$ = $1 * $3; }
    | term '/' factor   { $$ = $1 / $3; }
    | factor            { $$ = $1;      }
;

factor: INTEGER             { $$ = $1; }
    | FLOATING              { $$ = $1; }
    | LEFT expression RIGHT { $$ = $2; }
    | ID {  
        int intValue;
        float floatValue;

        if(st.variables.find(*$1) != st.variables.end())
        {
            cout << "[INFO] Variable  " << *$1 << " found in symbols table." << endl;
            if(st.variables[*$1] == "INT")
            {
                intValue = mm.intTable[*$1];
                $$ = intValue;
            }
            else if(st.variables[*$1] == "FLOAT")
            {
                floatValue = mm.floatTable[*$1];
                $$ = floatValue;
            }
            else if(st.variables[*$1] == "BOOL")
            {
                if(mm.boolTable[*$1]) {
                    intValue = 1;
                }
                else {
                    intValue = 0;
                }
                $$ = intValue;
            }
            else 
            {
                cout << ERROR_START << " Variable " << *$1 << " cannot be cast to a number." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << " was not declared." << endl;
        }
        delete $1;
    };

// nao precisa do negativo e positivo na frente, o atoi e atof cuidam disso
expression: expression '+' expression {$$ = $1 + $3;}
    | expression '-' expression {$$ = $1 - $3;}
    | term {$$ = $1;}
;

boolean_factor:
    TRUE {$$ = true;}
    | FALSE {$$ = false;}
    | LEFT logical_expression RIGHT {$$ = $2;}
    ;

comparison_expression: 
    expression EQ expression {$$ = $1 == $3;      cout << $1 << " == " << $3 << " = " << $$ << endl;}
    | expression NE expression {$$ = $1 != $3;    cout << $1 << " <> " << $3 << " = " << $$ << endl;}
    | expression LT expression {$$ = $1 < $3;     cout << $1 << " < "  << $3 << " = " << $$ << endl;}
    | expression LE expression {$$ = $1 <= $3;    cout << $1 << " <= " << $3 << " = " << $$ << endl;}
    | expression GT expression {$$ = $1 > $3;     cout << $1 << " > "  << $3 << " = " << $$ << endl;}
    | expression GE expression {$$ = $1 >= $3;    cout << $1 << " >= " << $3 << " = " << $$ << endl;}
    | expression {
        if($1 == 0)
        {
            $$ = false;
        }
        else
        {
            $$ = true;
        }
    }
    | boolean_factor {$$ = $1;};

logical_expression: 
    comparison_expression AND comparison_expression     { $$ = $1 && $3;}
    | comparison_expression OR comparison_expression    { $$ = $1 || $3;}
    | NOT comparison_expression                         { $$ = !$2;     }
    | comparison_expression                             { $$ = $1;      };

atribs: 
    ID ATRIB expression EOL NEW_LINE {
        // TESTAR
        if(st.variables.find(*$1) != st.variables.end())
        {
            if(st.variables[*$1] == "INT")
            {
                mm.intTable[*$1] = static_cast<int>($3);
            }
            else if(st.variables[*$1] == "FLOAT")
            {
                mm.floatTable[*$1] = $3;
            }
            else 
            {
                cout << ERROR_START << " Variable " << *$1 << " is not a number." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << " not declared." << endl;
        }
        delete $1;
    }
    | ID ATRIB logical_expression EOL NEW_LINE {
        if(st.variables.find(*$1) != st.variables.end())
        {
            if(st.variables[*$1] == "BOOL")
            {
                mm.boolTable[*$1] = $3;
            }
            else
            {
                cout << ERROR_START << " Variable " << *$1 << " is not a boolean." << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << "is not declared." << endl;
        }
        delete $1;
    }
    | ID ATRIB ID EOL NEW_LINE {
        // TODO testar

        // se os dois ids existem na tabela de símbolos
        if(st.variables.find(*$1) != st.variables.end() && st.variables.find(*$3) != st.variables.end())
        {
            string receiverType = st.variables[*$1];
            string senderType = st.variables[*$3];
            // se o id da esquerda é um int
            if(receiverType == "INT")
            {
                // se o id da direita é um int
                if(senderType == "INT")
                {
                    mm.intTable[*$1] = mm.intTable[*$3];
                }
                // se o id da direita é um float
                else if(senderType == "FLOAT")
                {
                    mm.intTable[*$1] = static_cast<int>(mm.floatTable[*$3]);
                }
                // se o id da direita é um bool
                else if(senderType == "BOOL")
                {
                    mm.intTable[*$1] = static_cast<int>(mm.boolTable[*$3]); // testar
                }
                else 
                {
                    cout << ERROR_START << " Variable " << *$3 << " has an unknown type" << endl;
                }
            }
            // se o id da esquerda é um float
            else if(receiverType == "FLOAT")
            {
                // se o id da direita é um int
                if(senderType == "INT")
                {
                    mm.intTable[*$1] = static_cast<float>(mm.intTable[*$3]);
                }
                // se o id da direita é um float
                else if(senderType == "FLOAT")
                {
                    mm.intTable[*$1] = mm.floatTable[*$3];
                }
                // se o id da direita é um bool
                else if(senderType == "BOOL")
                {
                    mm.intTable[*$1] = static_cast<float>(mm.boolTable[*$3]); // testar
                }
                else 
                {
                    cout << ERROR_START << " Variable " << *$3 << " has an unknown type" << endl;
                }
            }
            // se o id da esquerda é um bool
            else if(receiverType == "BOOL")
            {
                // se o id da direita é um int
                if(senderType == "INT")
                {
                    mm.intTable[*$1] = static_cast<bool>(mm.intTable[*$3]);
                }
                // se o id da direita é um float
                else if(senderType == "FLOAT")
                {
                    mm.intTable[*$1] = static_cast<bool>(mm.floatTable[*$3]);
                }
                // se o id da direita é um bool
                else if(senderType == "BOOL")
                {
                    mm.intTable[*$1] = (mm.boolTable[*$3]); 
                }
                else 
                {
                    cout << ERROR_START << " Variable " << *$3 << " has an unknown type" << endl;
                }
            }
            else 
            {
                cout << ERROR_START << " Variable " << *$1 << " has an unknown type" << endl;
            }
        }
        else
        {
            cout << ERROR_START << " Variable " << *$1 << " not declared." << endl;
        }

        delete $1;
        delete $3;
    }
    ;

    */
%%