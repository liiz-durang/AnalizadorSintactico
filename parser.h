#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include <string>
#include <iostream>
using namespace std;
#include "tokens.h"

namespace COMP{
    class Parser
    {
    private:
        Lexer *lexer;
        int token;
    public:
        Parser(/* args */);
        Parser(Lexer *lexer);
        ~Parser();
        void programa();
        void declaraciones();
        void declaraciones_();
        void declaracion();
        void tipo();
        void lista_var();
        void lista_var_();
        void sentencias();
        void sentencias_();
        void sentencia();
        void expresion();
        void expresion_();
        void termino();
        void termino_();
        void factor();
        void eat(int t);
        void error(string msg);

    };
}
#endif