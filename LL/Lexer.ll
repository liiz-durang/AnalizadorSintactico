%{
	#include <iostream>
	#include <string>
	using namespace std;

	#include "tokens.h"
	#include "lexer.h"

%}

%option c++
%option outfile = "Lexer.cpp"
%option yyclass = "Lexer"
%option case-insensitive
%option noyywrap


DIG [0-9]+ 
ID [a-zA-Z][A-Za-z0-9_]*
ESP [ \t\n\r]
ENT {DIG}+
FLOTANTE {ENT}?"."{ENT}([eE][+-]?{ENT})?

%%

"+"			{return MAS;}
"-"			{return MENOS;}
"*"			{return MUL;}
"/"			{return DIV;}
"="			{return ASIG;}
"("			{return LPAR;}
")"			{return RPAR;}
","			{return COMA;}
";"			{return PYC;}
"{"         {return LKEY;}
"}"         {return RKEY;}

"if"		{return IF;}
"int"		{return INT;}
"float"		{return FLOAT;}
"else"		{return ELSE;}
"while"		{return WHILE;}

{ID}		{return ID;}
{ENTERO}	{return NUMERO;}
{FLOTANTE}	{return NUMERO;}
{ESP}		{}

.		{cout<<"ERROR LEXICO " << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}