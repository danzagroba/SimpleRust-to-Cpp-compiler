# Simple Rust to Cpp compiler


## Como compilar e executar o interpretador

```bash
bison -d compiler.y
flex compiler.l

# Windows:
g++ -std=c++17 -Wno-register compiler.tab.c lex.yy.c SymbolTable.cpp -Wall -o compiler.exe
# Linux:
g++ -std=c++17 -Wno-register compiler.tab.c lex.yy.c SymbolTable.cpp -Wall -o compiler

# para executar no modo interativo
./compiler

# Para executar o arquivo de teste
./compiler < test01.txt 
```