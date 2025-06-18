#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, TypeNode*>();
    variables.clear();
}

SymbolTable::~SymbolTable() {
    variables.clear();
}
