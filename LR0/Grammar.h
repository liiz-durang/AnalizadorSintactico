#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <map>
#include <vector>
using namespace std;
#include "Symbol.h"
#include "Production.h"

class Grammar
{
public:    
    map<int, Symbol> syms;    
    map<int, Production> prods;
    int term;
    int noTerm;

public:
    Grammar(/* args */);    
    ~Grammar();
    void print();
    void addSymbol(int i, Symbol s);
    void addProduction(int i, Production p);
    int getNumProds();
    int getNumTerm();
    int getNunNonTerm();
    void setNumTerm(int n);
    void setNunNonTerm(int n);
};

#endif