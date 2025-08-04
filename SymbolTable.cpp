#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, TypeNode*>();
    variables.clear();
    vectors = std::unordered_map<std::string, TypeNode*>();
    vectors.clear();
}

SymbolTable::~SymbolTable() {
    for (auto const& [key, val] : variables) {
        delete val;
    }
    variables.clear();
    for (auto const& [key, val] : vectors) {
        delete val;
    }
    vectors.clear();
}
