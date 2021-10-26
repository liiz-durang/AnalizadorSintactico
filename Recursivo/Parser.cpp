//Análisis Sintáctico
#include "Parser.h"
#include <iostream>

namespace COMP{

    Parser::Parser(/* args */){

    }   

    Parser::Parser(Lexer *lexer){
        this -> lexer = lexer;
        TOKENS[INT   ] = "int";
        TOKENS[FLOAT ] = "float";
        TOKENS[ELSE  ] = "else";
        TOKENS[IF    ] = "if";
        TOKENS[WHILE ] = "while";
        TOKENS[MAS   ] = "+";
        TOKENS[MENOS ] = "-";
        TOKENS[MUL   ] = "*";
        TOKENS[DIV   ] = "/";
        TOKENS[ASIG  ] = "=";
        TOKENS[LPAR  ] = "(";
        TOKENS[RPAR  ] = ")";
        TOKENS[ID    ] = "id"; 
        TOKENS[PYC   ] = ";";
        TOKENS[COMA  ] = ",";
        TOKENS[NUMERO] = "numero"; //Entero o flotante
        TOKENS[ESP   ] = "espacio";            
        }

    Parser::~Parser(){

    }

    void Parser::programa(){
        cout << "programa" << endl;
        declaraciones();
        sentencias();
        cout << "SALIMOS programa" << endl;
        
    }
    
    void Parser::declaraciones(){
        cout << "declaraciones" << endl;
        declaracion();
        declaraciones_();
        cout << "SALIMOS declaraciones" << endl;
        
    }

    void Parser::declaraciones_(){
        cout << "declaraciones_" << endl;
        while(token == INT || token == FLOAT){
            declaracion();    
        }
        cout << "SALIMOS declaraciones_" << endl;
    }

    void Parser::declaracion(){
        cout << "declaracion" << endl;
        tipo();
        lista_var();
        eat(PYC);        
        cout << "SALIMOS declaracion" << endl;
    }

    void Parser::tipo(){
        cout << "tipo" << endl;
        switch (token){
            case INT:
                eat(INT);
                break;
            case FLOAT:
                eat(FLOAT);
                break;
            default:
                error("Se esperaba el token INT o FLOAT");
                break;
        }
        cout << "SALIMOS tipo" << endl;
    }
    
    void Parser::lista_var(){
        cout << "lista_var" << endl;
        eat(ID);
        lista_var_();
        cout << "SALIMOS lista_var" << endl;
        
    }

    void Parser::lista_var_(){
        cout << "lista_var_" << endl;
        while(token == COMA){
            eat(COMA);
            eat(ID);
        }
        cout << "SALIMOS lista_var_" << endl;
        
    }

    void Parser::sentencias(){
        cout << "sentencias" << endl;
        sentencia();
        sentencias_();
        cout << "SALIMOS sentencias" << endl;
    }
    void Parser::sentencias_(){
        cout << "sentencias_" << endl;
        while( token == ID  || token == IF || token == WHILE ){
            sentencia();
        }
        cout << "SALIMOS sentencias_" << endl;
        
    }
    void Parser::sentencia(){
        cout << "sentencia" << endl;
        switch(token){
            case ID:
                eat(ID);
                eat(ASIG);
                expresion();
                eat(PYC);
                break;
            case IF:
                eat(IF);
                eat(LPAR);
                expresion();
                eat(RPAR);
                sentencias();
                eat(ELSE);
                sentencias();
                break;
            case WHILE:
                eat(WHILE);
                eat(LPAR);
                expresion();
                eat(RPAR);
                sentencias();
                break;
            default:
                error("Se esperaba el token ID, IF O WHILE");
                break;
        }
        cout << "SALIMOS sentencia" << endl;
        
    }
    void Parser::expresion(){
        cout << "expresion" << endl;
        termino();
        expresion_();
        cout << "SALIMOS expresion" << endl;
    }

    void Parser::expresion_(){
        cout << "expresion_" << endl;
        while(token == MENOS || token == MAS){
            if(token == MAS) {
                eat(MAS);//token=lexer->yylex();
            }
            else if(token==MENOS){
                eat(MENOS);//token=lexer->yylex();
            } 
            termino();
        }
        cout << "SALIMOS expresion_" << endl;
        
    }
    void Parser::termino(){
        cout << "termino" << endl;
        factor();
        termino_();
        cout << "SALIMOS termino" << endl;
    }
    void Parser::termino_(){
        cout << "termino_" << endl;
        while(token == MUL || token == DIV){
            if(token == MUL) {
                eat(MUL);//token=lexer->yylex();
            }
            else if(token == DIV){
                eat(DIV);//token=lexer->yylex();
            } 
            factor();
        }
        cout << "SALIMOS termino_" << endl;
        
    }
    void Parser::factor(){
        cout << "factor" << endl;
        switch (token){
            case LPAR:
                eat(LPAR);
                expresion();
                eat(RPAR);
                break;
            case ID:
                eat(ID);
                break;
            case NUMERO:
                eat(NUMERO);
                break;
            default:
                error("Se esperaba el token LPAR, ID O NUMERO");
                break;
        }
        cout << "SALIMOS factor" << endl;
        
    }
    /*
    void Parser::eat(int t){
        token = lexer->yylex();
        if(token != -1){
            cout << "token correcto: " << token << "," << lexer->getYytext() << endl;
        }
    }
    */
    void Parser::eat(int t){        
        if(token == t){
            cout << "token correcto: " << token << "," << lexer->getYytext() << endl;
            token = lexer->yylex();     
            cout << token << endl;
            cout << t << endl;    
        }
        else {
            cout << token << endl;
            cout << t << endl;
            error("Token no esperado: " + lexer->getYytext() + " se esperaba el token " + TOKENS[t]);
        }    
    }

    void Parser::error(string msg){
        //cout<<"ERROR DE SINTAXIS "<<msg<< " en la línea "<< lexer->getLine()<<endl;
        cout<<"ERROR DE SINTAXIS "<< msg <<endl;
        exit(-1);
    }

    void Parser::parse(){
        token = lexer->yylex();
        programa();
        if(token != -1 && lexer->yyin.eof()){
            cout<<"No hay errores lexicos"<<endl;
        }else{
            cout<<"La cadena no pertenece " << lexer->getYytext() << " al lenguaje generado por la gramática"<<endl;
        }
    }

  
}
