#include "Production.h"

Production::Production()
{
}

Production::Production(int head, vector<int> body)
{
    this->head = head;
    this->body = body;
}

Production::~Production()
{
    body.clear();
}

void Production::addBody(vector<int> body)
{
    this->body = body;
}

void Production::addHead(int head)
{
    this->head = head;
}

int Production::getHead()
{
    return head;
}
vector<int> Production::getBody()
{
    return body;
}

int Production::getSymbolInPos(int i)
{
    return body[i];
}