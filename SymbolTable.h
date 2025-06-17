#include <unordered_map>
#include <string>
#include "AST.h"

class SymbolTable{
    public:
    //Tabela de simbolos para variáveis
    std::unordered_map<std::string, TypeNode*> variables;
    //Tabela de simbolos para constantes
    std::unordered_map<std::string, TypeNode*> constants;
  

    SymbolTable();
    ~SymbolTable();
};

