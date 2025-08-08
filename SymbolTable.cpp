#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, TypeNode*>();
    variables.clear();
    vectors = std::unordered_map<std::string, TypeNode*>();
    vectors.clear();
    functions = std::unordered_map<std::string, TypeNode*>();
    functions.clear();
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
    for (auto const& [key, val] : functions) {
        delete val;
    }
    functions.clear();
}

/*void SymbolTable::pushScope() {
    scopeLevel++;
}

void SymbolTable::popScope() {
    for (auto it = scopeMap.begin(); it != scopeMap.end(); ) {
        if (it->second == scopeLevel) {
            if (variables.find(it->first) != variables.end()) {
                delete variables[it->first];
                variables.erase(it->first);
            }
            else if (vectors.find(it->first) != vectors.end()) {
                delete vectors[it->first];
                vectors.erase(it->first);
            }
            it = scopeMap.erase(it);
        } else {
            ++it;
        }
    }
    scopeLevel--;
}
    */