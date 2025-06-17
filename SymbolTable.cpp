#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, TypeNode*>();
    constants = std::unordered_map<std::string, TypeNode*>();
    variables.clear();
    constants.clear();
}

SymbolTable::~SymbolTable() {
    variables.clear();
    constants.clear();
}
