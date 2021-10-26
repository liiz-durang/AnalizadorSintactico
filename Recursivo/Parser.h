#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <string>
#include <iostream>
using namespace std;

namespace COMP{
    class Parser
    {
    private:
        Lexer *lexer;
        int token;
    public:
	map<int, string> TOKENS;
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
        void parse();

    };
}
#endif
