%{

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>
#include <ctype.h>
#include "my_parser.tab.h"

YYSTYPE yylval;

#include "TableSymbole.c"
#include "quadruplet.c"
#include "pile.c"

int lignenum = 1 ;

int colnum = 0 ; 
int current_column = 0; 
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

type        ["int"|"float"|"string"|"bool"]

struct      {ID}
 
%%
"//".* {
    colnum = 1;
    return COMMENT;
}

"/*"(.|\n)*"*/" {
    colnum=colnum+2; // ajoute 2 pour les caractères '/*'
    int len = strlen(yytext)-2;
    for (int i = 0; i < len; i++) {
        if (yytext[i] == '\n') {
            colnum = 1; // Réinitialise la colonne pour chaque nouvelle ligne
            lignenum++;
        } else {
            colnum++;
        }
    }
    return COMMENT_MULTILIGNE;
}
	  
{char}  {	      
    colnum=colnum+yyleng;
    yylval.charv = yytext[1];
	return CARACTERE;
} 

{string}  {	      
    colnum=colnum+yyleng;
    strcpy(yylval.str,yytext);
	return CHAR;
}    

{int}   {
    colnum=colnum+yyleng;
    yylval.intv = atoi(yytext);
    return ENTIER;
}

{float} {
    colnum=colnum+yyleng;
    yylval.flt = atof(yytext);
    return FLOTTANT;
}     

"vrai"  {
    colnum=colnum+4;  
    yylval.boolean = true;
    return BOOLEAN_VRAI;
}

"faux"  {
    colnum=colnum+4;
    yylval.boolean = false;  
    return BOOLEAN_FAUX;
}

"$Prog" {
    colnum=colnum+5;  
    return MAIN;
}   

"$"  {
    colnum=colnum+1;  
    return PROCEDURE; 
}     


"cst" {
    colnum=colnum+3; 
    yylval.type = 0; 
    return TYPE_CONS;
}   

"int"  {
    colnum=colnum+3; 
    yylval.type = 1; 
    return TYPE_INT;
}    

"float" {
    colnum=colnum+5; 
    yylval.type = 2; 
    return TYPE_FLT;
}    

"char" {
    colnum=colnum+4;
    yylval.type = 3;  
    return TYPE_CAR;
}      

"string" {
    colnum=colnum+5;  
    yylval.type = 4;
    return TYPE_STR;
}      

"bool"  {
    colnum=colnum+4;  
    yylval.type = 5;
    return TYPE_BLN;
}     

"return" {
    colnum=colnum+6;  
    return RETURN;
}  

"read"  {
    colnum=colnum+4;  
    return READ;
}   

"write" {
    colnum=colnum+5;  
    return WRITE;
}  

"while" {
    colnum=colnum+5;  
    return WHILE;

}     

"for"  {
    colnum=colnum+3;  
    return FOR;
}   

"if" {
    colnum=colnum+2;  
    return IF;
}      

"else" {
    colnum=colnum+4;  
    return ELSE;
}   


"switch" {
    colnum=colnum+6;  
    return SWITCH;
}  

"case"  {
    colnum=colnum+4;  
    return CASE;
}   

"break"  {
    colnum=colnum+5;
    return CASE_BREAK; 
}    

"default" {
    colnum=colnum+7;  
    return CASE_DEFAULT; 
}  

"struct"  {
    colnum=colnum+6;  
    return STRUCT;
}  

"import" {
    colnum=colnum+6;
    return IMPORT;
}

{ID}     {
    colnum=colnum+yyleng;
    strcpy(yylval.str,yytext);
    return ID;
}      

{blancs} {
    colnum=colnum+yyleng;
}

"&"    {
    colnum=colnum+1;
    return ADRESSE;
}

";"    {
    colnum=colnum+1;
    return FIN_INSTRUCTION;
}    

"++"	 {
    colnum=colnum+2;
    return INCREM;
}      

"\n"    { 
    colnum = 0;
   lignenum++; /* ignore lines */ };

"--"	 {
    colnum=colnum+2;
    return DECREM;
}     

"+"    {
    colnum=colnum+1;
    return PLUS;
}       

"/"    {
    colnum=colnum+1;
    return DIV;
}       

"-"     {
    colnum=colnum+1;
    return MOINS;
}      

"*"    {
    colnum=colnum+1;
    return MUL;
}       

"%"     {
    colnum=colnum+1;
    return MOD;
}      

"^"     {
    colnum=colnum+1;
    return PUISS;
}      

"("    {
    colnum=colnum+1;
    return PAR_OUV;
}       

")"    {
    colnum=colnum+1;
    return PAR_FERM;
}       

"<="    {
    colnum=colnum+2;
    return INF_EGAL;
}     

"<"     {
    colnum=colnum+1;
    return INF;
}      

">"    {
    colnum=colnum+1;
    return SUPP;
}       

">="     {
    colnum=colnum+2;
    return SUPP_EGAL;
}    

"=="    {
    colnum=colnum+2;
    return EGALE;
}     

"!="    {
    colnum=colnum+2;
    return PASEGALE;
}     

"!"    {
    colnum=colnum+1;
    return NEGATION;
}       

"&&"    {
    colnum=colnum+1;
    return ET;
}       

"|"    {
    colnum=colnum+1;
    return OU;
}       

"["      {
    colnum=colnum+1;
    return DEB_TABLEAU;
}    

"]"    {
    colnum=colnum+1;
    return FIN_TABLEAU;
}        

"="     {
    colnum=colnum+1;
    return AFFECTATION;
}      

"{"    {
    colnum=colnum+1;
    return DEB_CORPS;
}       

"}"    {
    colnum=colnum+1;
    return FIN_CORPS;
}       


","      {
    colnum=colnum+1;
    return SEPARATEUR;
}     

"."      {
    colnum=colnum+1;
    return ACCES_STRUCT;
}      

":"     {
    colnum=colnum+1;
    return CASE_START;
}       



.   {
    current_column = colnum+1;
    printf("Erreur  Lexical Unexpected token%s  ligne %d  colonne %d \n",yytext, lignenum,current_column);
    
    exit(1);
}

 

%%
