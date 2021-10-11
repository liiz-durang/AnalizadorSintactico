#include  <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "tokens.h"

using namespace std;
using namespace COMP;


int main(int argc, char *argv[]){
    

    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    
    Lexer lexer("tablaTrans.txt");
    lexer.openFile(string(argv[1]));
    Parser parser(&lexer);
    parser.parse();    
    lexer.closeFile();
    //lexer.printTable();
    return 0;
}