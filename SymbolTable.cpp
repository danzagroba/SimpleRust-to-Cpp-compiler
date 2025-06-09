#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    variables = std::unordered_map<std::string, std::string>();
    variables.clear();

}

SymbolTable::~SymbolTable() {
    variables.clear();
}
