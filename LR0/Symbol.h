#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
using namespace std;

enum TYPE
{
    terminal,
    noterminal,
    emptystr
};

class Symbol
{
private:
    int index;
    int pos;
    TYPE type;
    string name;

public:
    Symbol();    
    Symbol(string name, int pos, TYPE type, int index);
    ~Symbol();

    int getPos();
    int getType();
    int getIndex();
    string getName();

    void setPos(int pos);
    void setType(TYPE type);
    void setIndex(int index);
    void setName(string name);
};

#endif