#include  <iostream>
#include "Lexer.h"
#include "Parser.h"
#include <fstream>

using namespace std;
using namespace COMP;

int main(int argc, char *argv[]){
    

    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    
    filebuf FB;
    FB.open(string(argv[1]), ios::in);
    istream in(&FB);
    Lexer lexer(&in);
    Parser parser(&lexer);
    parser.parse();    
    FB.close();
    //lexer.printTable();
    return 0;
}