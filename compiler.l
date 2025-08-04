%{
#include <iostream>
using namespace std;
#include "AST.h"

#include "compiler.tab.h"

int yyparse();

%}
%option yylineno

INTEGER [\+\-]?[0-9]+
FLOATING [\+\-]?[0-9]+"."[0-9]+

VAR [a-zA-Z][a-zA-Z0-9_]*
OP [+*/-]

%%

{OP}        { return yytext[0]; } 
{INTEGER}   { yylval.ival = atoi(yytext); return INTEGER;   }
{FLOATING}  { yylval.fval = atof(yytext); return FLOATING;  }

"fn" { return FUNCTION; }
"main" { return MAIN; }

"i32"   { return TINT;   }
"f32" { return TFLOAT; }
"bool"  { return TBOOL;  }


"(" {return LEFT;}
")" {return RIGHT;}

"{" {return LBRACE;}
"}" {return RBRACE;}

"[" {return LBRACKET;}
"]" {return RBRACKET;}

"&&" {return AND;}
"||" {return OR;}

"true" { return TRUE; }
"false" { return FALSE; }

"=" { return ATRIB; }
"=="  { return EQ; }
"!=" { return NE; }
"<"  { return LT; }
"<=" { return LE; }
">"  { return GT; }
">=" { return GE; }

"let" { return LET; }
"mut" { return MUT; }
":" { return COLON; }

"if"    { return IF;    }
"else"  { return ELSE;  }

"for"   { return FOR; }
"in"    { return IN; }
".."    { return TO; }
"while" { return WHILE; }

"input!"  { return READ;  }
"print!" { return WRITE; }
"println!" { return WRITELN; }

";" { return EOL; }
<<EOF>>  {return 0;}

{VAR}       { yylval.str = new std::string(yytext); return ID;}

[ \t\r\n]+ { }


.  { cout << "Entrada invalida: " << yytext << endl; }

%%


int yywrap() {
    return 1;
}

void yyerror(const char *str) {
    if (yytext)
        fprintf(stderr, "Syntax error: %s at line %d, token '%s'\n", str, yylineno, yytext);
    else
        fprintf(stderr, "Syntax error: %s at line %d\n", str, yylineno);
}