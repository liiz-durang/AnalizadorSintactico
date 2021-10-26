#include "Grammar.h"
#include <fstream>
#include <sstream>
#include <iostream>

Grammar::Grammar(/* args */)
{
}


Grammar::~Grammar()
{
    syms.clear();
    prods.clear();
}

void Grammar::print()
{    
}

void Grammar::addProduction(int i, Production p)
{
    prods[i] = p;
}

void Grammar::addSymbol(int i, Symbol s)
{
    syms[i] = s;
}

int Grammar::getNumProds()
{
    return prods.size();    
}

int Grammar::getNumTerm()
{
    return term;
}
    
int Grammar::getNunNonTerm()
{
    return noTerm;
}

void Grammar::setNumTerm(int n)
{
    term=n;
}
    
void Grammar::setNunNonTerm(int n)
{
    noTerm = n;
}
