/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPILER_TAB_H_INCLUDED
# define YY_YY_COMPILER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FUNCTION = 258,                /* FUNCTION  */
    MAIN = 259,                    /* MAIN  */
    RETURN = 260,                  /* RETURN  */
    ID = 261,                      /* ID  */
    TINT = 262,                    /* TINT  */
    TFLOAT = 263,                  /* TFLOAT  */
    TBOOL = 264,                   /* TBOOL  */
    INTEGER = 265,                 /* INTEGER  */
    FLOATING = 266,                /* FLOATING  */
    LET = 267,                     /* LET  */
    MUT = 268,                     /* MUT  */
    COLON = 269,                   /* COLON  */
    COMMA = 270,                   /* COMMA  */
    ARROW = 271,                   /* ARROW  */
    LEFT = 272,                    /* LEFT  */
    RIGHT = 273,                   /* RIGHT  */
    LBRACE = 274,                  /* LBRACE  */
    RBRACE = 275,                  /* RBRACE  */
    LBRACKET = 276,                /* LBRACKET  */
    RBRACKET = 277,                /* RBRACKET  */
    NOT = 278,                     /* NOT  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    TRUE = 281,                    /* TRUE  */
    FALSE = 282,                   /* FALSE  */
    ATRIB = 283,                   /* ATRIB  */
    EQ = 284,                      /* EQ  */
    NE = 285,                      /* NE  */
    LT = 286,                      /* LT  */
    LE = 287,                      /* LE  */
    GT = 288,                      /* GT  */
    GE = 289,                      /* GE  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    FOR = 292,                     /* FOR  */
    IN = 293,                      /* IN  */
    TO = 294,                      /* TO  */
    WHILE = 295,                   /* WHILE  */
    READ = 296,                    /* READ  */
    WRITE = 297,                   /* WRITE  */
    WRITELN = 298,                 /* WRITELN  */
    EOL = 299                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "compiler.y"

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


#line 162 "compiler.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COMPILER_TAB_H_INCLUDED  */
