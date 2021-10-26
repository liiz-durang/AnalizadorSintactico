#include  <iostream>
#include <fstream>
#include "Lexer.h"
#include "tokens.h"
#include "LR0.h"

using namespace std;



int main(int argc, char *argv[]){
    

    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    filebuf fb;
    fb.open(string(argv[1]), ios::in);
    istream in(&fb);    
    Lexer lexer(&in);
    LR0 lr(&lexer);
    lr.parse();
    
    return 0;
}