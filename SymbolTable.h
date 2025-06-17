#include <unordered_map>
#include <string>
#include "AST.h"

class SymbolTable{
    public:
    //SymbolTable for variables
    std::unordered_map<std::string, TypeNode*> variables;
    //Constants are not supported in this grammar anymore
    //SymbolTable for constants
    //std::unordered_map<std::string, TypeNode*> constants;
  

    SymbolTable();
    ~SymbolTable();
};

