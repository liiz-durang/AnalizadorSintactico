#include "LR0.h"
#include <iostream>
#include "tokens.h"
using namespace std;

LR0::LR0(Lexer *lexer)
{
    this->lexer = lexer;   
}

LR0::~LR0()
{
}

void LR0::eat()
{
    token = lexer->yylex();
    stoken=tokens[token];
}

void LR0::error(string msg)
{
    cout<<msg<<endl;
    exit(EXIT_FAILURE);
}

int LR0::parse()
{
    loadSyms();
    loadProds();
    loadTable();

    stack<int> pila;
    map<int, acc>::iterator accion;
    map<int, acc> rowAcc;    
    vector<int> body;
    Production p;
    initTokens();

    pila.push(-1);
    pila.push(0);
    eat();

    while(true)
    {
        rowAcc = ACC[pila.top()];
        accion = rowAcc.find(token);
        if(accion != rowAcc.end()){
            if(accion->second.tipo == shift){                
                eat();
                pila.push(accion->second.action);
            }else if(accion->second.tipo == reduce){
                p = grammar.prods[accion->second.action];
                body = p.getBody();
                for(vector<int>::iterator sym = body.begin(); sym != body.end(); sym++){
                    pila.pop();
                }
                pila.push(GOTO[pila.top()][p.getHead()]);
            }else if(accion->second.action == acep){
                cout<<"La cadena es aceptada"<<endl;
                return 1;
            }else{
                error("error");
                return -1;
            }
        }else{
            error("error");
            return -1;
        }
    }    
}

void LR0::loadSyms()
{
    grammar.addSymbol(0, Symbol("programa", 0, noterminal, 0));
    grammar.addSymbol(1, Symbol("declaraciones", 1, noterminal, 1));    
    grammar.addSymbol(2, Symbol("declaracion", 2, noterminal, 2));
    grammar.addSymbol(3, Symbol("tipo", 3, noterminal, 3));
    grammar.addSymbol(4, Symbol("listaVar", 4, noterminal, 4));    
    grammar.addSymbol(5, Symbol("sentencias", 5, noterminal, 5));    
    grammar.addSymbol(6, Symbol("sentencia", 6, noterminal, 6));
    grammar.addSymbol(7, Symbol("expresion", 7, noterminal, 7));    
    grammar.addSymbol(8, Symbol("termino", 8, noterminal, 8));    
    grammar.addSymbol(9, Symbol("factor", 9, noterminal, 9));
    grammar.addSymbol(10, Symbol("MAS", 10, terminal, 1));
    grammar.addSymbol(11, Symbol("MENOS", 11, terminal, 2));
    grammar.addSymbol(12, Symbol("MUL", 12, terminal, 3));
    grammar.addSymbol(13, Symbol("DIV", 13, terminal, 4));
    grammar.addSymbol(14, Symbol("ASIG", 14, terminal, 5));
    grammar.addSymbol(15, Symbol("LPAR", 15, terminal, 6));
    grammar.addSymbol(16, Symbol("RPAR", 16, terminal, 7));
    grammar.addSymbol(17, Symbol("COMA", 17, terminal, 8));
    grammar.addSymbol(18, Symbol("PYC", 18, terminal, 9));
    grammar.addSymbol(19, Symbol("ID", 19, terminal, 10));
    grammar.addSymbol(20, Symbol("IF", 20, terminal, 11));
    grammar.addSymbol(21, Symbol("INT", 21, terminal, 12));
    grammar.addSymbol(22, Symbol("WHILE", 22, terminal, 13));
    grammar.addSymbol(23, Symbol("ELSE", 23, terminal, 14));
    grammar.addSymbol(24, Symbol("FLOAT", 24, terminal, 15));
    grammar.addSymbol(25, Symbol("NUMERO", 25, terminal, 16));
    grammar.addSymbol(26, Symbol("LKEY", 26, terminal, 17));
    grammar.addSymbol(27, Symbol("RKEY", 27, terminal, 18));
    grammar.addSymbol(28, Symbol("$", 28, terminal, 0));
    grammar.addSymbol(29, Symbol("EPS", 29, emptystr, 0));
}
void LR0::loadProds()
{
    grammar.addProduction(0, Production(0, {1, 5}));
    grammar.addProduction(1, Production(1, {1, 2}));
    grammar.addProduction(2, Production(1, {2}));
    grammar.addProduction(3, Production(2, {3, 4, 18}));
    grammar.addProduction(4, Production(3, {21}));
    grammar.addProduction(5, Production(3, {24}));
    grammar.addProduction(6, Production(4, {4, 17, 19}));
    grammar.addProduction(7, Production(4, {17}));
    grammar.addProduction(8, Production(5, {5, 6}));        
    grammar.addProduction(9, Production(6, {19, 14, 7, 18}));
    grammar.addProduction(10, Production(6, {20, 15, 7, 16, 26,  5, 27, 23, 26, 5, 27}));
    grammar.addProduction(11, Production(6, {22, 15, 7, 16, 26, 5, 27}));
    grammar.addProduction(12, Production(7, {7, 10, 8}));
    grammar.addProduction(13, Production(7, {7, 11, 8}));
    grammar.addProduction(14, Production(7, {8}));
    grammar.addProduction(15, Production(8, {8, 12, 9}));
    grammar.addProduction(16, Production(8, {8, 13, 9}));
    grammar.addProduction(17, Production(8, {9}));
    grammar.addProduction(18, Production(9, {15, 7, 16}));
    grammar.addProduction(19, Production(9, {19}));
    grammar.addProduction(20, Production(9, {25}));   
    
}

void LR0::loadTable()
{
    ACC[0][12] = acc(shift, 5); ACC[0][15] = acc(shift, 6);
    ACC[1][0] = acc(acep, 0);
    ACC[2][12] = acc(shift, 5); ACC[2][15] = acc(shift, 5); ACC[2][10] = acc(shift, 10);   ACC[2][11] = acc(shift, 11); ACC[2][13] = acc(shift, 12);
    ACC[3][12] = acc(reduce, 2); ACC[3][15] = acc(reduce, 2); ACC[3][10] = acc(reduce, 2); ACC[3][11] = acc(reduce, 2); ACC[3][13] = acc(reduce, 2);
    ACC[4][10] = acc(shift, 14);
    ACC[5][10] = acc(reduce, 4);
    ACC[6][10] = acc(reduce, 5);
    ACC[7][10] = acc(shift, 10); ACC[7][11] = acc(shift, 11); ACC[7][13] = acc(shift, 12);
    ACC[8][12] = acc(reduce, 1); ACC[8][15] = acc(reduce, 1); ACC[8][10] = acc(reduce, 1); ACC[8][11] = acc(reduce, 1); ACC[8][13] = acc(reduce, 1);
    ACC[9][0] = acc(reduce, 9); ACC[9][18] = acc(reduce, 9);
    ACC[10][5] = acc(shift, 16);
    ACC[11][6] = acc(shift, 17);    
    ACC[12][6] = acc(shift, 18);
    ACC[13][8] = acc(shift, 20); ACC[13][9] = acc(shift, 19);
    ACC[14][8] = acc(reduce, 7); ACC[14][9] = acc(reduce, 7);
    ACC[15][18] = acc(reduce, 8); ACC[15][0] = acc(reduce, 8);
    ACC[16][10] = acc(shift, 25); ACC[16][6] = acc(shift, 24); ACC[16][16] = acc(shift, 26);
    ACC[17][10] = acc(shift, 25); ACC[17][6] = acc(shift, 24); ACC[17][16] = acc(shift, 26);
    ACC[18][10] = acc(shift, 25); ACC[18][6] = acc(shift, 24); ACC[18][16] = acc(shift, 26);
    ACC[19][12] = acc(reduce, 3); ACC[19][15] = acc(reduce, 3); ACC[19][10] = acc(reduce, 3); ACC[19][11] = acc(reduce, 3); ACC[19][13] = acc(reduce, 3);
    ACC[20][10] = acc(shift, 29);
    ACC[21][9] = acc(shift, 30); ACC[21][1] = acc(shift, 31); ACC[21][2] = acc(shift, 32);
    ACC[22][9] = acc(reduce, 15); ACC[22][7] = acc(reduce, 15); ACC[22][1] = acc(reduce, 15); ACC[22][2] = acc(reduce, 15);
    ACC[22][3] = acc(shift, 33); ACC[22][4] = acc(shift, 34);
    ACC[23][9] = acc(reduce, 18); ACC[23][7] = acc(reduce, 18); ACC[23][1] = acc(reduce, 18); 
    ACC[23][2] = acc(reduce, 18); ACC[23][3] = acc(reduce, 18); ACC[23][4] = acc(reduce, 18);
    ACC[24][10] = acc(shift, 25); ACC[24][6] = acc(shift, 24); ACC[24][16] = acc(shift, 26);
    ACC[25][9] = acc(reduce, 20); ACC[25][7] = acc(reduce, 20); ACC[25][1] = acc(reduce, 20); 
    ACC[25][2] = acc(reduce, 20); ACC[25][3] = acc(reduce, 20); ACC[25][4] = acc(reduce, 20);
    ACC[26][9] = acc(reduce, 21); ACC[26][7] = acc(reduce, 21); ACC[26][1] = acc(reduce, 21); 
    ACC[26][2] = acc(reduce, 21); ACC[26][3] = acc(reduce, 21); ACC[26][4] = acc(reduce, 21);
    ACC[27][17] = acc(shift, 36); ACC[27][1] = acc(shift, 31); ACC[27][2] = acc(shift, 32);
    ACC[28][17] = acc(shift, 37); ACC[28][1] = acc(shift, 31); ACC[28][2] = acc(shift, 32);
    ACC[29][8] = acc(reduce, 6); ACC[29][9] = acc(reduce, 6);
    ACC[30][18] = acc(reduce, 10); ACC[30][0] = acc(reduce, 10);
    ACC[31][10] = acc(shift, 25); ACC[31][6] = acc(shift, 24); ACC[31][16] = acc(shift, 26);
    ACC[32][10] = acc(shift, 25); ACC[32][6] = acc(shift, 24); ACC[32][16] = acc(shift, 26);
    ACC[33][10] = acc(shift, 25); ACC[33][6] = acc(shift, 24); ACC[33][16] = acc(shift, 26);
    ACC[34][10] = acc(shift, 25); ACC[34][6] = acc(shift, 24); ACC[34][16] = acc(shift, 26);
    ACC[35][1] = acc(shift, 31); ACC[35][2] = acc(shift, 32);
    ACC[36][17] = acc(shift, 43);
    ACC[37][17] = acc(shift, 44);
    ACC[38][9] = acc(reduce, 13); ACC[38][7] = acc(reduce, 13); ACC[38][1] = acc(reduce, 13); 
    ACC[38][2] = acc(reduce, 13); ACC[38][3] = acc(reduce, 13); ACC[38][4] = acc(reduce, 13);
    ACC[39][9] = acc(reduce, 14); ACC[39][7] = acc(reduce, 14); ACC[39][1] = acc(reduce, 14); 
    ACC[39][2] = acc(reduce, 14); ACC[39][3] = acc(reduce, 14); ACC[39][4] = acc(reduce, 14);
    ACC[40][9] = acc(reduce, 16); ACC[40][7] = acc(reduce, 16); ACC[40][1] = acc(reduce, 16); 
    ACC[40][2] = acc(reduce, 16); ACC[40][3] = acc(reduce, 16); ACC[40][4] = acc(reduce, 16);
    ACC[41][9] = acc(reduce, 17); ACC[41][7] = acc(reduce, 17); ACC[41][1] = acc(reduce, 17); 
    ACC[41][2] = acc(reduce, 17); ACC[41][3] = acc(reduce, 17); ACC[41][4] = acc(reduce, 17);
    ACC[42][9] = acc(reduce, 19); ACC[42][7] = acc(reduce, 19); ACC[42][1] = acc(reduce, 19); 
    ACC[42][2] = acc(reduce, 19); ACC[42][3] = acc(reduce, 19); ACC[42][4] = acc(reduce, 19);
    ACC[43][10] = acc(shift, 10);   ACC[43][11] = acc(shift, 11); ACC[43][13] = acc(shift, 12);
    ACC[44][10] = acc(shift, 10);   ACC[44][11] = acc(shift, 11); ACC[44][13] = acc(shift, 12);
    ACC[45][10] = acc(shift, 10);   ACC[45][11] = acc(shift, 11); ACC[45][13] = acc(shift, 12);
    ACC[46][10] = acc(shift, 10);   ACC[46][11] = acc(shift, 11); ACC[46][13] = acc(shift, 12);
    ACC[47][17] = acc(shift, 49);
    ACC[48][0] = acc(reduce, 12); ACC[48][18] = acc(reduce, 12);
    ACC[49][10] = acc(shift, 10);   ACC[49][11] = acc(shift, 11); ACC[49][13] = acc(shift, 12);
    ACC[50][10] = acc(shift, 10);   ACC[50][11] = acc(shift, 11); ACC[50][13] = acc(shift, 12);  ACC[50][17] = acc(shift, 51); 
    ACC[51][0] = acc(reduce, 11); ACC[51][18] = acc(reduce, 11);

    GOTO[0][0] = 1; GOTO[0][1] = 2; GOTO[0][2] = 3; GOTO[0][3] = 4; 
    GOTO[2][2] = 8; GOTO[2][3] = 4; GOTO[2][5] = 7; GOTO[2][6] = 8;
    GOTO[4][4] = 13; GOTO[7][6] = 15;
    GOTO[16][7] = 21; GOTO[16][8] = 22; GOTO[16][9] = 23;
    GOTO[17][7] = 27; GOTO[17][8] = 22; GOTO[17][9] = 23;
    GOTO[18][7] = 28; GOTO[18][8] = 22; GOTO[18][9] = 23;
    GOTO[24][7] = 35; GOTO[24][8] = 22; GOTO[24][9] = 23;
    GOTO[31][8] = 38; GOTO[31][9] = 23;
    GOTO[32][8] = 39; GOTO[32][9] = 23;
    GOTO[33][9] = 40;
    GOTO[34][9] = 41;
    GOTO[35][9] = 42;
    GOTO[43][5] = 45; GOTO[43][6] = 15;
    GOTO[44][5] = 45; GOTO[44][6] = 15;
    GOTO[45][6] = 15;
    GOTO[46][6] = 15;
    GOTO[49][5] = 50; GOTO[49][6] = 15;
    GOTO[50][6] = 15;
}

void LR0::initTokens()
{
    tokens[MAS] = "+";
    tokens[MENOS] = "-";
    tokens[MUL]="*";
    tokens[DIV]="/";
    tokens[ASIG]="=";
    tokens[LPAR]="(";
    tokens[RPAR]=")";
    tokens[COMA]=",";
    tokens[PYC]=";";
    tokens[ID]="id";
    tokens[IF]="if";
    tokens[INT]="int";
    tokens[WHILE]="while";
    tokens[ELSE]="else";
    tokens[FLOAT]="float";
    tokens[NUMERO]="num";
    tokens[LKEY]="{";
    tokens[RKEY]="}";

}