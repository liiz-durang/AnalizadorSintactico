#include "lexer.h"
#include "tokens.h"

/*Programa que realiza el analisis lexico */

namespace COMP{

    Lexer::Lexer(/*args*/){

    }

    Lexer::Lexer(string file)
    {
        
        // TODO(1)  Completar la tabla de transiciones o llamar a la función para leer el archivo del AFD 
        readAFD(file);

        //Completar estados de aceptación
        crearEdoAcept();
         
        //Simbolos usados 
        crearSimbolos();
        
    }
    
    Lexer::~Lexer()
    {
        //Liberar la memoria que fue asignada
        for (size_t i = 0; i < 36; i++)
        {
            delete transiciones[i];
        }
        delete transiciones;
        delete acc; 
    }

    /**
     * // TODO(3) Función que lea los renglones de la matriz de transiciones y los guarde en dicha matriz
     **/
    bool Lexer::readAFD(string file){
        string linea;
        string fragmento;
         //Reservación de memoria de las transiciones.
        //36 filas
        //25 columnas -> revisar que coincida con nuestra tabla de transiciones.
        transiciones =  new int*[36];
        for(int i=0; i<36; i++) 
            transiciones[i] = new int[25];
        
        // TODO(1)  Completar la tabla de transiciones o llamar a la función para leer el archivo del AFD 

          ifstream archivo(file);
          //int transiciones [36][25];
          int filas=0, columnas=0,numero=0;

          if(archivo.fail()){
            cout<<"Error al abrir el archivo";
            exit(1);
          }
          while(!archivo.eof()){
            getline(archivo, linea);
            //cout<<linea<<"\n";
            stringstream input_stringstream(linea); 
            while (getline(input_stringstream, fragmento, ' ')){
              if(columnas==26) {
                columnas=0;
                filas=filas+1;
                transiciones[filas][columnas]=stoi(fragmento);
                columnas=columnas+1;
              }else{
              transiciones[filas][columnas]=stoi(fragmento);
              columnas=columnas+1;
              }
            }  
          }
          archivo.close();

       
    }
    
    /**
     *  // TODO(2) Completar el arreglo de estados de aceptación
     **/
    bool Lexer::crearEdoAcept(){
       
        acc = new bool[36];
        acc[0] =false;
        acc[1] =true;
        acc[2] =true;
        acc[3] =true;
        acc[4] =true;
        acc[5] =true;
        acc[6] =true;
        acc[7] =true;
        acc[8] =true;
        acc[9] =true;
        acc[10] =true;
        acc[11] =false;
        acc[12] =true;
        acc[13] =true; 
        acc[14] =true; 
        acc[15] =true; 
        acc[16] =true; 
        acc[17] =true; 
        acc[18] =true; 
        acc[19] =true; 
        acc[20] =true; 
        acc[21] =true; 
        acc[22] =true; 
        acc[23] =true; 
        acc[24] =true; 
        acc[25] =true; 
        acc[26] =true; 
        acc[27] =true; 
        acc[28] =true; 
        acc[29] =true; 
        acc[30] =true; 
        acc[31] =true; 
        acc[32] =true; 
        acc[33] =false; 
        acc[34] =false; 
        acc[35] =true;
    }

    /*
    * //TODO(5)
        //Se agregan los simbolos de las columnas con sus respectivos valores (sustituye la función charToColum)
    **/
    bool Lexer::crearSimbolos(){
        
        simbolos['+']       = 0;
        simbolos['-']       = 1;
        simbolos['*']       = 2;
        simbolos['/']       = 3;
        simbolos['\n']      = 4;
        simbolos[' ']       = 4;
        simbolos['\t']      = 4;
        simbolos['\r']      = 4;
        simbolos['0']       = 5;
        simbolos['1']       = 5;
        simbolos['2']       = 5;
        simbolos['3']       = 5;
        simbolos['4']       = 5;
        simbolos['5']       = 5;
        simbolos['6']       = 5;
        simbolos['7']       = 5;
        simbolos['8']       = 5;
        simbolos['9']       = 5;
        simbolos['i']       = 6;
        simbolos['f']       = 7;
        simbolos['e']       = 8;
        simbolos['w']       = 9;
        simbolos['l']       = 10;
        simbolos['s']       = 11;
        simbolos['h']       = 12;
        simbolos['n']       = 13;
        simbolos['t']       = 14;
        simbolos['o']       = 15;
        simbolos['a']       = 16;
        simbolos['E']       = 17;

        simbolos['b']       = 18;
        simbolos['c']       = 18;
        simbolos['d']       = 18;
        simbolos['g']       = 18;
        simbolos['j']       = 18;
        simbolos['k']       = 18;
        simbolos['m']       = 18;
        simbolos['p']       = 18;
        simbolos['q']       = 18;
        simbolos['r']       = 18;
        simbolos['u']       = 18;
        simbolos['v']       = 18;
        simbolos['x']       = 18;
        simbolos['y']       = 18;
        simbolos['z']       = 18;

        simbolos['A']       = 18;
        simbolos['B']       = 18;
        simbolos['C']       = 18;
        simbolos['D']       = 18;
        simbolos['F']       = 18;
        simbolos['G']       = 18;
        simbolos['H']       = 18;
        simbolos['I']       = 18;
        simbolos['J']       = 18;
        simbolos['K']       = 18;
        simbolos['L']       = 18;
        simbolos['M']       = 18;
        simbolos['N']       = 18;
        simbolos['O']       = 18;
        simbolos['P']       = 18;
        simbolos['Q']       = 18;
        simbolos['R']       = 18;
        simbolos['S']       = 18;
        simbolos['T']       = 18;
        simbolos['U']       = 18;
        simbolos['V']       = 18;
        simbolos['W']       = 18;
        simbolos['X']       = 18;
        simbolos['Y']       = 18;
        simbolos['Z']       = 18;

        simbolos['.']       = 19;
        simbolos[',']       = 20;
        simbolos[';']       = 21;
        simbolos['(']       = 22;
        simbolos[')']       = 23;
        simbolos['_']       = 24;
        simbolos['=']       = 25;
    }

    /*
    * // TODO(4) implentar la función que permita regresar solo 1 caracter
    */
    
    char Lexer::getChar(){
        
        yyin.get(c);
        //cout << "C es: " << c <<endl;
    }

    /**
     * Abrir archivo a leer
     **/
    bool Lexer::openFile(string file){
        yyin.open(file,ios::in); //(archivo,modo_de_apertura)
        if (!yyin.is_open())
        {
            cerr << "No se pudo abrir el archivo" << file << endl;
            return EXIT_FAILURE;
        }
        //Lee el primer caracter. 
        getChar();
        
    }

    /**
     * Cerrar archivo que se leyó
     */
    bool Lexer::closeFile(){
        yyin.close();
    }


  
    /**
     *   //Funcion de análisis léxico
     **/ 
    int Lexer::yylex(){
        int q=0;        //q es el estado actual. -> inicia en el estado 0
        int cc;         //valor del estado
        yytext = "";    //buffer inicia en cadena vacía      
        map<char,int> :: iterator it;
        if(yyin.eof()) return 0;


        while(true){
            //cc = charToColumn(c); //pasamos el caracter a estad. -> Se sustituyo por map simbolos
            //Existe la transición
            cc = simbolos[c];
            //cout << "c: " << c << endl;
            //cout << "CC: " << cc << endl;

            it = simbolos.find(c);
            if(it == simbolos.end()){
                    cout << "caracter no reconocido" << endl;
                    return(0);
            }else{
                cc = it->second;
            }

            if(transiciones[q][cc]!=-1){ 
                q=transiciones[q][cc];  //Actualizamos el estado actual.
                //cout << "q: " << q << endl;
                yytext+=c; 
                getChar();           //Obtenemos el siguiente caracter.
                //if(yyin.eof()) return token(q);

            }else{

                //Si hay caracter
                if(acc[q]){
                    // TODO(6) Agregar el código para que la función ignore los espacios en blanco.
                    if (q == 17 )   {
                        q = 0;
                        yytext = "";
                    }
                    else{
                        return token(q);
                    }  
                }else{
                    
                    cout << "caracter no reconocido" << endl;
                    return(0);
                    
                    
                }
            }

            //Si ya acabo el archivo
            if(yyin.eof()) return 0;
       
        }
        

    }

    int Lexer::token(int q){
        // TODO(7) Completar la función para que pueda retornar los tokens. 
        //De acuerdo a su estado de aceptación.
        switch(q){
            case 1:
                return MAS;
            case 2:
                return MENOS;
            case 3: 
                return MUL;
            case 4: 
                return DIV;
            case 5: 
                return ASIG;
            case 6: 
                return LPAR;
            case 7: 
                return RPAR;
            case 8: 
                return PYC; 
            case 9: 
                return COMA; 
            case 10: case 32: case 35: 
                return NUMERO; 
            case 12: case 13: case 14: case 15: case 16: case 19: case 21: case 22: case 23: case 25: case 26: case 28: case 29: case 30:   
                return ID;
            case 17: 
                return ESP;
            case 18: 
                return IF; 
            case 20: 
                return INT; 
            case 24: 
                return FLOAT; 
            case 27: 
                return ELSE; 
            case 31:
                return WHILE;
        }
    }

    string Lexer::getYytext(){
        return yytext;
    }

    bool Lexer::imprimirTransiciones(){
        for(int i=0; i<36; i++) {
        for (int j = 0; j < 25; j++)
        {
            cout << "Fila: " << i << endl; 
            cout << "Columna: " << j << endl; 

            cout << transiciones[i][j] << endl;
        }
        
    }
    }

}