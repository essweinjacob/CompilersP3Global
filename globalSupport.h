#ifndef GLOBALSUPPORT_H
#define GLOBALSUPPORT_H
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "token.h"
using namespace std;

typedef struct symbolTable{
    Token id;
}SymbolTable;

class Semantics{
    private:
        SymbolTable holder;
        vector<SymbolTable>st;

        void checkDec(Token tk);
        void checkDef(Token tk);
    
    public:
        void valid(Node *node);
};

#endif