#include "Parser.h"
/*
0 programa → declaraciones sentencias
1 declaraciones → declaración declaraciones’
2 declaraciones’ → declaración declaraciones’ | 𝜀
3 declaración → tipo lista-var ;
4 tipo → int | float
5 lista-var → identificador lista-var’
6 lista-var’ → , identificador lista-var’ | 𝜀

7 sentencias → sentencia sentencias’
8 sentencias’ → sentencia sentencias’ | 𝜀
9 sentencia→ identificador = expresión ;
            | if (expresión) sentencias else sentencias
            | while(expresión) sentencias
10 expresión → término expresión’
11 expresión’ → + término expresión’ | - término expresión’| 𝜀
12 término → factor término’
13 término' → * factor término’| / factor término’| 𝜀
14 factor → ( expresión )| identificador| número
*/

void Parser::loadSymbols(){
    syms[0]=Symbol("programa",noterminal,0);
    syms[1]=Symbol("declaraciones",noterminal,1);
    syms[2]=Symbol("declaraciones_",noterminal,2);
    syms[3]=Symbol("declaracion",noterminal,3);
    syms[4]=Symbol("tipo",noterminal,4);
    syms[5]=Symbol("lista_var",noterminal,5);
    syms[6]=Symbol("lista-var_",noterminal,6);
    syms[7]=Symbol("sentencias",noterminal,7);
    syms[8]=Symbol("sentencias_",noterminal,8);
    syms[9]=Symbol("sentencia",noterminal,9);
    syms[10]=Symbol("espresion",noterminal,10);
    syms[11]=Symbol("expresion_",noterminal,11);
    syms[12]=Symbol("termino",noterminal,12);
    syms[13]=Symbol("termino_",noterminal,13);
    syms[14]=Symbol("factor",noterminal,14);
    syms[15]=Symbol("$",terminal,0);
    syms[16]=Symbol("INT",terminal,1);
    syms[17]=Symbol("FLOAT",terminal,2);
    syms[18]=Symbol("ELSE",terminal,3);
    syms[19]=Symbol("IF",terminal,4);
    syms[20]=Symbol("WHILE",terminal,5);
    syms[21]=Symbol("MAS",terminal,6);
    syms[22]=Symbol("MENOS",terminal,7);
    syms[23]=Symbol("MUL",terminal,8);
    syms[24]=Symbol("DIV",terminal,9);
    syms[25]=Symbol("ASIG",terminal,10);
    syms[26]=Symbol("LPAR",terminal,11);
    syms[27]=Symbol("RPAR",terminal,12);
    syms[28]=Symbol("ID",terminal,13);
    syms[29]=Symbol("PYC",terminal,14);
    syms[30]=Symbol("COMA",terminal,15);
    syms[31]=Symbol("NUMERO",terminal,16);
    syms[32]=Symbol("ESP",terminal,17);
    syms[33]=Symbol("EPS",cadena,0);
}


void Parser::loadProds(){
    //programa→ declaraciones sentencias
    vector<int> s = {1, 7};
    prods[0]= Production(0,s);
    s.clear();

    //declaraciones → declaración declaraciones’
    s =  {3, 2};
    prods[1] = Production(1,s);
    s.clear();

    //declaraciones’ → declaración declaraciones’
    s = {3, 2};
    prods[2] = Production(2, s);
    s.clear();   

    //declaraciones’ →  𝜀
    s = {33};
    prods[3] = Production(2, s);
    s.clear(); 
    
    //declaración → tipo lista-var ;
    s = {4, 5, 29};
    prods[4] = Production(3,s);
    s.clear(); 

    //tipo → int
    s = {16};
    prods[5] = Production(4,s);
    s.clear();

    //tipo → float    
    s = {17};
    prods[6] = Production(4,s);
    s.clear();     

    //lista-var → identificador lista-var’
    s = {28, 6};
    prods[7] = Production(5,s);
    s.clear(); 

    //lista-var’ → , identificador lista-var’
    s = {30,28, 6};
    prods[8] = Production(6,s);
    s.clear();

    //lista-var’ → 𝜀
    s = {33};
    prods[9] = Production(6,s);
    s.clear();     

    //sentencias → sentencia sentencias’
    s = {9,8};
    prods[10] = Production(7,s);
    s.clear(); 

    //sentencias’ → sentencia sentencias’
    s = {9, 8};
    prods[11] = Production(8,s);
    s.clear();

    //sentencias’ → 𝜀
    s = {33};
    prods[12] = Production(8,s);
    s.clear();     

    //sentencia → identificador = expresión ;
    s = {28, 25, 10, 29};
    prods[13] = Production(9,s);
    s.clear(); 

    //sentencia → if (expresión) sentencias else sentencias
    s = {19, 26, 10, 27, 7, 18, 7};
    prods[14] = Production(9,s);
    s.clear(); 

    //sentencia → while(expresión) sentencias
    s = {20, 26, 10, 27, 7};
    prods[15] = Production(9,s);
    s.clear();     

    //expresión → término expresión’
    s = {12, 11};
    prods[16] = Production(10,s);
    s.clear();
    
    //expresión’ → + término expresión’
    s = {21,12,11};
    prods[17] = Production(11,s);
    s.clear(); 
    
    //expresión’ →  - término expresión’
    s = {22,12,11};
    prods[18] = Production(11,s);
    s.clear();
    
    //expresión’ → 𝜀
    s = {33};
    prods[19] = Production(11,s);
    s.clear(); 

    //término → factor término’
    s = {14,13};
    prods[20] = Production(12,s);
    s.clear();  

    //término' → * factor término’
    s = {23,14,13};
    prods[21] = Production(13,s);
    s.clear(); 
    
    // término' → / factor término’
    s = {24,14,13};
    prods[22] = Production(13,s);
    s.clear(); 

    // término' → 𝜀
    s = {33};
    prods[23] = Production(13,s);
    s.clear(); 

    //factor → ( expresión )
    s = {26,10,27};
    prods[24] = Production(14,s);
    s.clear();

    //factor → identificador
    s = {28};
    prods[25] = Production(14,s);
    s.clear();

    //factor → número
    s = {31};
    prods[26] = Production(14,s);
    s.clear();   
}

void Parser::loadTable(){
    //First de su primera producción, y si esta producción produce 𝜀,
    //entonces nos vamos con el follow del encabezado
    //si alpha es anulable entramos a la linea 5 del algoritmo de analisis descente.

    //Programa: First de declaraciones
    table[0][16] = 0;
    table[0][17] = 0;
    
    //Declaraciones: First de declaración
    table[1][16] = 1;
    table[1][17] = 1;

    //Declaraciones': First de declaración
    table[2][16] = 2;
    table[2][17] = 2;

    //Declaraciones': Follow de Declaraciones'
    table[2][28] = 3;
    table[2][19] = 3;
    table[2][20] = 3;

    //Declaración: First de tipo
    table[3][16] = 4;
    table[3][17] = 4;

    //tipo: First de int y float 
    table[4][16] = 5;
    table[4][17] = 5;

    //lista_var: firts de identificador
    table[5][28] = 6;

}

