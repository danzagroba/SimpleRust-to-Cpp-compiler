#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, TypeNode*>();
    variables.clear();
}

SymbolTable::~SymbolTable() {
    for (auto const& [key, val] : variables) {
        delete val;
    }
    variables.clear();
}
