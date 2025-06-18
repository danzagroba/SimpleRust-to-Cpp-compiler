#pragma once
#include <unordered_map>
#include <string>
#include "AST.h"

class SymbolTable{
    public:
    //SymbolTable for variables
    std::unordered_map<std::string, TypeNode*> variables;

    SymbolTable();
    ~SymbolTable();
};

