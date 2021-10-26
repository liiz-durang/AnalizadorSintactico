#ifndef  LR0_H
#define LR0_H

#include "Grammar.h"
#include "Lexer.h"
#include <string>
#include<stack>

using namespace std;

enum ActionType {reduce, shift, acep, error};

struct acc{
    ActionType tipo;
    int action;
    acc(){};
    acc(ActionType tipo, int action){
        this->tipo = tipo;
        this->action = action;
    };
};

class LR0
{
private:
    Grammar grammar;
    map<int, map<int,acc>> ACC;
    map<int, map<int,int>> GOTO;
    map<int,string> tokens;
    int token;
    string stoken;
    Lexer *lexer;
public:
    LR0(Lexer *lexer);
    ~LR0();
    void initTokens();
    int parse();
    void loadSyms();
    void loadProds();
    void loadTable();
    void error(string msg);
    void eat();
};
#endif // ! LL1_H