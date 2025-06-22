#pragma once
#include <unordered_map>
#include <string>
#include "AST.h"

class SymbolTable{
    public:
    std::unordered_map<std::string, TypeNode*> variables;

    SymbolTable();
    ~SymbolTable();
};

