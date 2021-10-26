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
            | if (expresión) { sentencias } else { sentencias }
            | while(expresión)  { sentencias }
10 expresión → término expresión’
11 expresión’ → + término expresión’ | - término expresión’| 𝜀
12 término → factor término’
13 término' → * factor término’| / factor término’| 𝜀
14 factor → ( expresión )| identificador| número
*/

void Parser::loadSymbols(){
    grammar.addSymbol(0,Symbol("programa",noterminal,0,0));
    grammar.addSymbol(1,Symbol("declaraciones",noterminal,1,1));
    grammar.addSymbol(2,Symbol("declaraciones_",noterminal,2,2));
    grammar.addSymbol(3,Symbol("declaracion",noterminal,3,3));
    grammar.addSymbol(4,Symbol("tipo",noterminal,4,4));
    grammar.addSymbol(5,Symbol("lista_var",noterminal,5,5));
    grammar.addSymbol(6,Symbol("lista-var_",noterminal,6,6));
    grammar.addSymbol(7,Symbol("sentencias",noterminal,7,7));
    grammar.addSymbol(8,Symbol("sentencias_",noterminal,8,8));
    grammar.addSymbol(9,Symbol("sentencia",noterminal,9,9));
    grammar.addSymbol(10,Symbol("espresion",noterminal,10,10));
    grammar.addSymbol(11,Symbol("expresion_",noterminal,11,11);
    grammar.addSymbol(12,Symbol("termino",noterminal,12,12));
    grammar.addSymbol(13,Symbol("termino_",noterminal,13,13));
    grammar.addSymbol(14,Symbol("factor",noterminal,14,14));
    grammar.noTerm = 15;
    grammar.addSymbol(15,Symbol("$",terminal,15,0));
    grammar.addSymbol(16,Symbol("MAS",terminal,16,1));
    grammar.addSymbol(17,Symbol("MENOS",terminal,17,2));
    grammar.addSymbol(18,Symbol("MUL",terminal,18,3));
    grammar.addSymbol(19,Symbol("DIV",terminal,19,4));
    grammar.addSymbol(20,Symbol("ASIG",terminal,20,5));
    grammar.addSymbol(21,Symbol("LPAR",terminal,21,6));
    grammar.addSymbol(22,Symbol("RPAR",terminal,22,7));
    grammar.addSymbol(23,Symbol("COMA",terminal,23,8));
    grammar.addSymbol(24,Symbol("PYC",terminal,24,9));
    grammar.addSymbol(25,Symbol("ID",terminal,25,10));
    grammar.addSymbol(26,Symbol("IF",terminal,26,11));
    grammar.addSymbol(27,Symbol("INT",terminal,27,12));
    grammar.addSymbol(28,Symbol("WHILE",terminal,28,13));
    grammar.addSymbol(29,Symbol("ELSE",terminal,29,14));
    grammar.addSymbol(30,Symbol("FLOAT",terminal,30,15));
    grammar.addSymbol(31,Symbol("NUMERO",terminal,31,16));
    grammar.addSymbol(32,Symbol("LKEY",terminal,32,17));
    grammar.addSymbol(33,Symbol("RKEY",cadena,33,18));
    grammar.term = 19;
    gammar.addSymbol(34, Symbol("EPS", cadenaVacia, 34, 1000));
}


void Parser::loadProds(){
    //programa→ declaraciones sentencias
    grammar.addProd(0,)
    vector<int> s = {1, 7};
    grammar.addProd(0, Production(0,s));
    s.clear();

    //declaraciones → declaración declaraciones’
    s =  {3, 2};
    grammar.addProd(1,Production(1,s);
    s.clear();

    //declaraciones’ → declaración declaraciones’
    s = {3, 2};
    grammar.addProd(2,Production(2, s);
    s.clear();   

    //declaraciones’ →  𝜀
    s = {33};
    grammar.addProd(3,Production(2, s);
    s.clear(); 
    
    //declaración → tipo lista-var ;
    s = {4, 5, 29};
    grammar.addProd(4,Production(3,s);
    s.clear(); 

    //tipo → int
    s = {16};
    grammar.addProd(5,Production(4,s);
    s.clear();

    //tipo → float    
    s = {17};
    grammar.addProd(6,Production(4,s);
    s.clear();     

    //lista-var → identificador lista-var’
    s = {28, 6};
    grammar.addProd(7,Production(5,s);
    s.clear(); 

    //lista-var’ → , identificador lista-var’
    s = {30,28, 6};
    grammar.addProd(8,Production(6,s);
    s.clear();

    //lista-var’ → 𝜀
    s = {33};
    grammar.addProd(9,Production(6,s);
    s.clear();     

    //sentencias → sentencia sentencias’
    s = {9,8};
    grammar.addProd(10,Production(7,s);
    s.clear(); 

    //sentencias’ → sentencia sentencias’
    s = {9, 8};
    grammar.addProd(11,Production(8,s);
    s.clear();

    //sentencias’ → 𝜀
    s = {33};
    grammar.addProd(12,Production(8,s);
    s.clear();     

    //sentencia → identificador = expresión ;
    s = {28, 25, 10, 29};
    grammar.addProd(13,Production(9,s);
    s.clear(); 

    //sentencia → if (expresión) { sentencias } else { sentencias }
    s = {19, 26, 10, 27, 32, 7, 33, 18, 32, 7 , 33};
    grammar.addProd(14,Production(9,s);
    s.clear(); 

    //sentencia → while(expresión)  { sentencias }
    s = {20, 26, 10, 27, 7, 32, 33};
    grammar.addProd(15,Production(9,s);
    s.clear();     

    //expresión → término expresión’
    s = {12, 11};
    grammar.addProd(16,Production(10,s);
    s.clear();
    
    //expresión’ → + término expresión’
    s = {21,12,11};
    grammar.addProd(17,Production(11,s);
    s.clear(); 
    
    //expresión’ →  - término expresión’
    s = {22,12,11};
    grammar.addProd(18,Production(11,s);
    s.clear();
    
    //expresión’ → 𝜀
    s = {33};
    grammar.addProd(19,Production(11,s);
    s.clear(); 

    //término → factor término’
    s = {14,13};
    grammar.addProd(20,Production(12,s);
    s.clear();  

    //término' → * factor término’
    s = {23,14,13};
    grammar.addProd(21,Production(13,s);
    s.clear(); 
    
    // término' → / factor término’
    s = {24,14,13};
    grammar.addProd(22,Production(13,s);
    s.clear(); 

    // término' → 𝜀
    s = {33};
    grammar.addProd(23,Production(13,s);
    s.clear(); 

    //factor → ( expresión )
    s = {26,10,27};
    grammar.addProd(24,Production(14,s);
    s.clear();

    //factor → identificador
    s = {28};
    grammar.addProd(25,Production(14,s);
    s.clear();

    //factor → número
    s = {31};
    grammar.addProd(26,Production(14,s);
    s.clear();   
}

void Parser::loadTable(){
    //First de su primera producción, y si esta producción produce 𝜀,
    //entonces nos vamos con el follow del encabezado
    //si alpha es anulable entramos a la linea 5 del algoritmo de analisis descente.

    //programa→ declaraciones sentencias
    //Programa: First de declaraciones
    table[0][12] = 0;
    table[0][15] = 0;
    
    //declaraciones → declaración declaraciones’
    //Declaraciones: First de declaración
    table[1][12] = 1;
    table[1][15] = 1;


    //declaraciones’ → declaración declaraciones’
    //Declaraciones': First de declaración
    table[2][12] = 2;
    table[2][15] = 2;

    //declaraciones’ →  𝜀
    //Declaraciones': Follow de Declaraciones'
    table[2][10] = 3;
    table[2][11] = 3;
    table[2][13] = 3;

    //declaración → tipo lista-var ;
    //Declaración: First de tipo
    table[3][12] = 4;
    table[3][15] = 4;

    //tipo → int
    //tipo → float
    //tipo: First de int y float 
    table[4][12] = 5;
    table[4][15] = 6;

    //lista-var → identificador lista-var’
    //lista_var: firts de identificador
    table[5][10] = 7;
    
    
    //lista-var’ → , identificador lista-var’
    //lista-var': First de ,
    table[6][8] = 8;

    //lista-var’ → 𝜀
    //lista-var':Follo de lista-var'
    table[6][9] = 9;

    //sentencias → sentencia sentencias’
    //sentencias: first de sentencia
    table[7][10] = 10;
    table[7][11] = 10;
    table[7][13] = 10;

    //sentencias’ → sentencia sentencias’
    //sentencias': First de sentencia
    table[8][10] = 11;
    table[8][11] = 11;
    table[8][13] = 11;

    //sentencias’ → 𝜀
    //sentencias': sollow de sentencias'
    table[8][0] = 12;
    table[8][18] = 12;

    //sentencia → identificador = expresión ;
    //sentencia: first identificador
    table[9][10] = 13;
    
    //sentencia → if (expresión) { sentencias } else { sentencias }
    //sentencia: first de IF
    table[9][11] = 14;
    
    //sentencia → while(expresión)  { sentencias }
    //senticia: first de while
    table[9][13] = 15;

    //expresión → término expresión’
    //expresion: first de termino
    table[10][6] = 16
    table[10][10] = 16;
    table[10][16] = 16;

    //expresión’ → + término expresión’
    //expresion: first de +
    table[11][1] = 17;

    //expresión’ → - término expresión’
    //expresion': first de -
    table[11][2] = 18;
    
    //expresión’ → 𝜀
    //expresion': follow de expresion'
    table[11][9] = 19;
    table[11][7] = 19;

    //término → factor término’
    //termino: first de factor
    table[12][6] = 20;
    table[12][10] = 20;
    table[12][16] = 20;

    //término' → * factor término’
    //termino':First de *
    table[13][3] = 21;

    // término' → / factor término’
    //termino':First de /
    table[13][4] = 22;

    // término' → 𝜀
    //termino':follow de Termino'
    table[13][1] = 23;
    table[13][2] = 23;
    table[13][9] = 23;
    table[13][7] = 23;

    //factor → ( expresión )
    //factor: first de (
    table[14][6] = 24;
    
    //factor → identificador    
    //factor: first de identificador
    table[14][10] = 25;

    //factor → número
    //factor: first de numero
    table[14][16] = 26;
}

int Parser::parse(){
    //Sigma son los terminales
    stack<Symbol> pila;
    int p;
    p = lexer -> yylex(); // p es el apuntador al primer caracter de la cadena.
    pila.push(grammar.getSym(15)); //metemos el fin de archivo a la pila.
    pila.push(grammar.getSym(grammar.start)); //metemos simbolo inicial a la pila
    
    while(pila.top().getId() != 15 ){
        if(pila.top().getType() == terminal){ //Linea 6
            if(pila.top.getIdx == p){         //Linea 6
                pila.pop();                   //Linea 7
                p = lexer -> yylex();         //Linea 7
            }
        }
        else if(pila.top().getType() == terminal && pila.top().getIdx != p){//Linea 8
            error("El token no coincide con la cima de la pila"); //Linea 9
        }
        else if(pila.top().getType() == noterminal){ //Linea 10
            if(table[pila.top().getIdx()][]){
                
            }
        }
    }

void Parser::error(string msg){
    cout<<"ERROR DE SINTAXIS "<< msg <<endl;
    exit(-1);
}

    

/*
int Parser::parse(){
    stack<Symbol>  pila;
    map<int,int>::iterator prod; //para consultar la producción
    map<int, int> row;
    vector<int> syms;
    loadSymbols();
    loadProds();
    loadTable();

    token = lexer->yylex();
    pila.push(grammar.getSym(15));
    pila.push(grammar.getSym(grammar.start));

    while(pila.top().getName()!="$"){
        if(pila.top().getType()==noterminal){ 
            row = table[pila.top().getIdx()]; //Agarra todas las producciones. 
            prod = row.find(token); //Buscamos la producción por su primer simbolo
            if(prod!= row.end()){
                syms = grammar.getProd(prod->second).getBody();
                pila.pop();
                if(syms[0]==34) continue;
                for(vector<int>::reverse_iterator it = syms.rbegin(); it != syms.rend(); it++)
                {
                    pila.push(grammar.getSym(*it));
                }
            }else{
                error("No existe ninguna acción sintáctica con el token actual");
            }
        }else if(pila.top().getType() == terminal){
            if(pila.top().getIdx() == token){
                pila.pop();
                token = lexer->yylex();
            }else{
                error("El token esperado no coincide con el actual");
            }
        }
    }
    if( pila.top().getName()=="$" && token ==0)
    {
        cout<<"La cadena es aceptada" <<endl;
        return 1;
    }else{
        cout<<"La cadena no es aceptada"<<endl;
        return -1;
    }*/
    
}
