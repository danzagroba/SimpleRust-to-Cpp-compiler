#include <unordered_map>
#include <string>


class SymbolTable{
    public:
    //Tabela de simbolos para variáveis
    std::unordered_map<std::string, std::string> variables;
    //Tabela de simbolos para constantes
    std::unordered_map<std::string, std::string> constants;
  

    SymbolTable();
    ~SymbolTable();
};

