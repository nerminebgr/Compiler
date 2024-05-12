%{

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "my_parser.tab.h"

YYSTYPE yylval;

#include "TableSymbole.c"



int lignenum = 1 ;

int linecol = 0 ; 

int yyerror(const char *s);
    int cptLigne;
%}

%option noyywrap 



chiffre     [0-9]

lettre      [a-zA-Z]

char        [']{lettre}[']|["]{lettre}["]

ID          [a-zA-Z_][a-zA-Z0-9_]* 

int         {chiffre}+

float       {int}+"."+{int} 

cst         {float}|{int}

blancs      [ \t]+

string      \"(\\.|[^"\\])*\"  

type        [“int”|”float”|”string”|”bool”]

struct      {ID}
 
%%
"//".* {
    linecol = 1;
    return COMMENT;
}

"/*"(.|\n)*"*/" {
    linecol=1;
    return COMMENT_MULTILIGNE;
}
	  

{char}  {	      
    linecol=linecol+yyleng;
    yylval.charv = yytext[0];
	return CARACTERE;
} 

{string}  {	      
    linecol=linecol+yyleng;
    strcpy(yylval.str,yytext);
	return CHAR;
}    

{int}   {
    linecol=linecol+yyleng;
    yylval.intv = atoi(yytext);
    return ENTIER;
}

{float} {
    linecol=linecol+yyleng;
    yylval.flt = atof(yytext);
    return FLOTTANT;
}     

"vrai"  {
    linecol=linecol+4;  
    return BOOLEAN_VRAI;
}

"faux"  {
    linecol=linecol+4;  
    return BOOLEAN_FAUX;
}

"$Prog" {
    linecol=linecol+5;  
    return MAIN;
}   

"$"  {
    linecol=linecol+1;  
    return PROCEDURE; 
}     


"cst" {
    linecol=linecol+3;  
    return TYPE_CONS;
}   

"int"  {
    linecol=linecol+3;  
    return TYPE_INT;
}    

"float" {
    linecol=linecol+5;  
    return TYPE_FLT;
}    

"char" {
    linecol=linecol+4;  
    return TYPE_CAR;
}      

"string" {
    linecol=linecol+5;  
    return TYPE_STR;
}      

"bool"  {
    linecol=linecol+4;  
    return TYPE_BLN;
}     

"return" {
    linecol=linecol+6;  
    return RETURN;
}  

"read"  {
    linecol=linecol+4;  
    return READ;
}   

"write" {
    linecol=linecol+5;  
    return WRITE;
}  

"while" {
    linecol=linecol+5;  
    return WHILE;

}     

"for"  {
    linecol=linecol+3;  
    return FOR;
}   

"if" {
    linecol=linecol+2;  
    return IF;
}      

"else" {
    linecol=linecol+4;  
    return ELSE;
}   


"switch" {
    linecol=linecol+6;  
    return SWITCH;
}  

"case"  {
    linecol=linecol+4;  
    return CASE;
}   

"break"  {
    linecol=linecol+5;
    return CASE_BREAK; 
}    

"default" {
    linecol=linecol+7;  
    return CASE_DEFAULT; 
}  

"struct"  {
    linecol=linecol+6;  
    return STRUCT;
}  

{ID}     {
    linecol=linecol+yyleng;
    strcpy(yylval.str,yytext);
    return ID;
}      

{blancs} {
    linecol=linecol+yyleng;
}

"&"    {
    linecol=linecol+1;
    return ADRESSE;
}

";"    {
    linecol=linecol+1;
    return FIN_INSTRUCTION;
}    

"++"	 {
    linecol=linecol+2;
    return INCREM;
}      

"\n"   { 
   lignenum++; /* ignore lines */ };

"--"	 {
    linecol=linecol+2;
    return DECREM;
}     

"+"    {
    linecol=linecol+1;
    return PLUS;
}       

"/"    {
    linecol=linecol+1;
    return DIV;
}       

"-"     {
    linecol=linecol+1;
    return MOINS;
}      

"*"    {
    linecol=linecol+1;
    return MUL;
}       

"%"     {
    linecol=linecol+1;
    return MOD;
}      

"^"     {
    linecol=linecol+1;
    return PUISS;
}      

"("    {
    linecol=linecol+1;
    return PAR_OUV;
}       

")"    {
    linecol=linecol+1;
    return PAR_FERM;
}       

"<="    {
    linecol=linecol+2;
    return INF_EGAL;
}     

"<"     {
    linecol=linecol+1;
    return INF;
}      

">"    {
    linecol=linecol+1;
    return SUPP;
}       

">="     {
    linecol=linecol+2;
    return SUPP_EGAL;
}    

"=="    {
    linecol=linecol+2;
    return EGALE;
}     

"!="    {
    linecol=linecol+2;
    return PASEGALE;
}     

"!"    {
    linecol=linecol+1;
    return NEGATION;
}       

"&&"    {
    linecol=linecol+1;
    return ET;
}       

"|"    {
    linecol=linecol+1;
    return OU;
}       

"["      {
    linecol=linecol+1;
    return DEB_TABLEAU;
}    

"]"    {
    linecol=linecol+1;
    return FIN_TABLEAU;
}        

"="     {
    linecol=linecol+1;
    return AFFECTATION;
}      

"{"    {
    linecol=linecol+1;
    return DEB_CORPS;
}       

"}"    {
    linecol=linecol+1;
    return FIN_CORPS;
}       

","      {
    linecol=linecol+1;
    return SEPARATEUR;
}     

"."      {
    linecol=linecol+1;
    return ACCES_STRUCT;
}      

":"     {
    linecol=linecol+1;
    return CASE_START;
}       



.   {
    printf("Erreur %s  ligne %d  col %d \n",yytext, lignenum,linecol);
    exit(1);
}

 

%%
