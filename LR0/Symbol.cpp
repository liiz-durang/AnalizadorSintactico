#include "Symbol.h"

Symbol::Symbol(/* args */)
{
}

Symbol::Symbol(string name, int pos, TYPE type, int index)
{
    this->name = name;
    this->pos = pos;
    this->type = type;
    this->index = index;
}

Symbol::~Symbol()
{
}

int Symbol::getPos()
{
    return pos;
}

int Symbol::getType()
{
    return type;
}

int Symbol::getIndex()
{
    return index;
}

string Symbol::getName()
{
    return name;
}

void Symbol::setPos(int pos)
{
    this->pos = pos;
}

void Symbol::setType(TYPE type)
{
    this->type = type;
}

void Symbol::setIndex(int index)
{
    this->index = index;
}

void Symbol::setName(string name)
{
    this->name = name;
}