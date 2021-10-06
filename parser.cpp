//Análisis Sintáctico
#include "parser.h"
#include "lexer.h"
#include <iostream>

namespace COMP{

    Parser::Parser(/* args */){

    }   

    Parser::Parser(Lexer *lexer){
        this -> lexer = lexer;
    }

    Parser::~Parser(){

    }

    void Parser::programa(){
        declaraciones();
        sentencias();
    }
    
    void Parser::declaraciones(){
        declaracion();
        declaraciones_();
    }

    void Parser::declaraciones_(){
        declaracion();
    }

    void Parser::declaracion(){
        tipo();
        lista_var();
    }

    void Parser::tipo(){
        switch (token){
            case INT:
                eat(INT);
                break;
            case FLOAT:
                eat(FLOAT);
            default:
                error("El token debe ser int o float");
                break;
        }
    }
    
    void Parser::lista_var(){
        switch (token){
            case ID:
                eat(ID);
                lista_var_();
                break;
            
            default:
                error("El token debe ser int o float");
                break;
        }
    }

    void Parser::lista_var_(){
        switch(token){
            case COMA:
                eat(COMA);
                eat(ID);
                break;
            default:
                error("El token debe ser ID");
                break;
        }

    }

    void Parser::sentencias(){
        sentencia();
        sentencias_();
    }
    void Parser::sentencias_(){
        sentencia();

    }
    void Parser::sentencia(){
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
                error("El token debe ID, IF o WHILE");
                break;
        }
    }
    void Parser::expresion(){
        termino();
        expresion_();
    }

    void Parser::expresion_(){

        /*
        whilr(token==MENOS||token==MAS){
            if(token==MAS) eat(MAS);//token=lexer->yylex();
            else if(token==MENOS) eat(MENOS);//token=lexer->yylex();
            factor();
        }
        */
        switch (token){
        case MAS:
            eat(MAS);
            factor();
            break;
        case MENOS:
            eat(MENOS);
            factor();        
        default:
            error("El token debe ser + o -");
            break;
        }    
    }
    void Parser::termino(){
        factor();
        termino_();
    }
    void Parser::termino_(){

        /*
        whilr(token==MUL||token==DIV){
            if(token==DIV) eat(DIV);//token=lexer->yylex();
            else if(token==MUL) eat(MUL);//token=lexer->yylex();
            factor();
        }
        */
        switch(token){
            case MUL:
                eat(MUL);            
                factor();
                break;
            case DIV:
                eat(DIV);
                factor();
            default:
                error("El token debe ser ID");
                break;
        }
    }
    void Parser::factor(){
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
            default:
                error("El token debe ser LPAR, ID o NUMERO");
                break;
        }
        
    }
    void Parser::eat(int t){
        token = lexer->yylex();
        programa();
        if(token == 0){
            cout<<"La cadena es aceptada"<<endl;
        }else{
            cout<<"La cadena no pertenece al lenguaje generado por la gramática"<<endl;
        }
    }
    void Parser::error(string msg){
         cout<<"ERROR DE SINTAXIS "<<msg<< " en la línea "<< lexer->getLine()<<endl;
        exit(-1);
    }

  
}
