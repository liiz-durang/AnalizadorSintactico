%{
	#include <iostream>
	#include <string>
	using namespace std;
	#include "tokens.h"
	#include "Lexer.h"

%}

%option c++
%option outfile = "Lexer.cpp"
%option yyclass = "Lexer"
%option case-insensitive
%option noyywrap


ENTERO [0-9]+
FLOTANTE [0-9]*"."[0-9]+([Ee]([+-])?[0-9]+)? 
ID [A-Za-z_][A-Za-z0-9_]*
ESP [ \t\n\r]

%%

"+"			{return MAS;}
"-"			{return MENOS;}
"*"			{return MUL;}
"/"			{return DIV;}
"="			{return ASIG;}
"("			{return LPAR;}
")"			{return RPAR;}
"{"			{return LKEY;}
"}"			{return RKEY;}

"int"		{return INT;}
"float"		{return FLOAT;}
"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
";"			{return PYC;}
","			{return COMA;}
{ENTERO}	{return NUMERO;}
{FLOTANTE}	{return NUMERO;}
{ID}		{return ID;}
{ESP}		{}

.		{cout<<"ERROR LEXICO " << yytext << endl;}

%%