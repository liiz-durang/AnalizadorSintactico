#ifndef LEXER_H
#define LEXER_H
#include <fstream> //Para manejo de archivos
#include <string> //Manejo de cadenas

#include <map>    //Manejo de map 
#include <sstream>
#include<iostream>
#include<stdlib.h>

using namespace std;

namespace COMP{    
    class Lexer
    {
    private:        
        const int ERROR = -1; //Solo dejamos error, los tokens estan en Tokens.h
        ifstream yyin; //Objeto para el archivo de entrada
        int **transiciones;
        bool *acc;      //Indica si el ultimo estado visitado es de aceptación o no 
        string yytext;  //buffer de caracteres leídos.
        int yyline;     //contador de líneas.
        char c;         //Caracter actual.
        map<char, int> simbolos; //Sustituye a la función charToColumn

    public:
        Lexer(/* args */); //Constructor
        Lexer (string file);
        ~Lexer(); //Destructor
        
        bool readAFD(string file);  //Función para llenar tabla de transiciones a partir de un archivo.
        bool crearEdoAcept();
        bool crearSimbolos();
        char getChar();             // Leer el siguiente caracter 'puede ser desde un arhivo'
        bool openFile(string file); //método para leer archivos
        bool closeFile();           //Metodo para cerrar el archivo 
        int yylex();                //método que retorna tokens
        int token(int q);           //
        string getYytext();         // Devuelve Yytext
        bool imprimirTransiciones(); //Imprime tabla de transiciones
    };     
}
#endif