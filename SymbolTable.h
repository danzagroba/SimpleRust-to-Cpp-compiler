#pragma once
#include <unordered_map>
#include <string>
#include "AST.h"

class SymbolTable{
    public:
    std::unordered_map<std::string, TypeNode*> variables;
    std::unordered_map<std::string, TypeNode*> vectors;
    std::unordered_map<std::string, TypeNode*> functions;
    
    //std::unordered_map<std::string, int> scopeMap;
    //int scopeLevel = 0;
    //void pushScope();
    //void popScope();

    SymbolTable();
    ~SymbolTable();
};
