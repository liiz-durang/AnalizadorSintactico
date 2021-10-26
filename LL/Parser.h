#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <stack>
#include <vector>
#include "Grammar.h"
#include "Lexer.h"
using namespace std;
using namespace COMP;


class Parser{
    private:
        map <int, map<int,int>> table;
        Grammar grammar;
        Lexer *lexer;
        int token;
    public:
        Parser(/*args*/);
        ~Parser();
        void loadSymbols();
        void loadProds();
        void loadTable();
        int parse();
        void error(string msg);
};

#endif