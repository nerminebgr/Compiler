%{

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "scanner.h"


 int lignenum =1;
 

%}

 

 

chiffre     [0-9]

lettre      [a-zA-Z]

char         [']{lettre}[']|["]{lettre}["]

ID          [a-zA-Z_][a-zA-Z0-9_]* 

int         {chiffre}+

float        {int}+"."+{int} 
cst        {float}|{int}

blancs      [ \t]+

string         \"(\\.|[^"\\])*\"

type        [“int”|”float”|”string”|”bool”]

struct      {ID}
 
%%
"//"	    return COMMENT;
"/*"  	      return DEB_COMMENT; 
"*/"          return FIN_COMMENT;
\n         return FIN_LIGNE;

{char}       return CARACTERE; 

{string}        return CHAR;

{int}       return ENTIER;


{float}      return FLOTTANT;

"vrai"      return BOOLEAN_VRAI;

"faux"      return BOOLEAN_FAUX;

"$Prog"     return MAIN;

"$"       return PROCEDURE; 


"cst"     return TYPE_CONS;

"int"       return TYPE_INT;

"float"      return TYPE_FLT;

"char"       return TYPE_CAR;

"string"        return TYPE_STR;

"bool"        return TYPE_BLN;

"return"    return RETURN;

"read"      return READ;

"write"    return WRITE;

"while"        return REPEAT;

"for"      return ITERATOR;

"if"        return IF;

"else"     return ELSE;

"else if"     return ELSEIF;

"switch"    return CASE;

"case"      return CASE_NUM;

"struct"     return STRUCT;

{ID}        return ID;

{blancs}   return VIDE;

";"        return FIN_INSTRUCTION;

"++"	    return INCREM;

"--"	    return DECREM;

"+"         return PLUS;

"/"         return DIV;

"-"         return MOINS;

"*"         return MUL;

"%"         return MOD;

"^"         return PUISS;

"("         return PAR_OUV;

")"         return PAR_FERM;

"<="       return INF_EGAL;

"<"         return INF;

">"         return SUPP;

">="       return SUPP_EGAL;

"=="       return EGALE;

"!="       return PASEGALE;

"!"         return NEGATION;

"&"         return ET;

"|"         return OU;

"["         return DEB_TABLEAU;

"]"          return FIN_TABLEAU;

"="         return AFFECTATION;

"{"         return DEB_CORPS;

"}"         return FIN_CORPS;

","         return SEPARATEUR;

"."          return ACCES_STRUCT;






.   {
    printf("Erreur %s  ligne %d \n",yytext, lignenum);
   
}

 

%%


static void skip_single_line_comment(void)
{
  int c;

  while((c = input()) != '\n' && c != EOF)

    ;

  if(c == EOF)

    unput(c);
}

int yywrap(){
    return 1;
}

int main(int argc, char *argv[]){

    FILE *input_file = fopen(argv[1], "r");
        if (!input_file) {
        perror("Error opening input file");
        return 1;
        }
    yyin = input_file;
    int token = yylex();
    while (token)
    {
        switch (token)
            {
                case 1 :
                    // entier
                     
                    printf("%s est un entier, ligne = %d\n",yytext,lignenum);
                break;

                case 2  :
                    //caractere
                     
                    printf("%s est un caractere, ligne = %d\n",yytext,lignenum); 
                break;

                case 3 :
                    // float
                     
                    printf("%s est un flottant, ligne = %d\n",yytext,lignenum);
                break;

                case 4 :
                    // fin ligne
                    lignenum++;
                   
             

                break;

                case 5 :
                    // vrai
                     
                    printf("%s est un boolean de type vrai, ligne = %d\n",yytext,lignenum);
                break;

                case 6 :
                    //faux
                     
                    printf("%s est un boolean de type faux, ligne = %d\n",yytext,lignenum);
                break;

                case 7 :
                // commenataire
                     printf("%s est le debut d'un commentaire, ligne = %d\n",yytext,lignenum);

                break;
		
		case 8 :
		//Puissance
		     printf("%s est un operateur arithmetique de puissance, ligne = %d\n",yytext,lignenum);

                case 9 :
                    // sep
                     
                    printf("%s est un separateur, ligne %d\n",yytext, lignenum);
                break;

                case 10 :
                    // id
                     
                    printf("%s est un Identifiant, ligne %d\n",yytext, lignenum);    
                break;

                case 11 :
                    //char
                    printf("%s est une chaine de caracteres, ligne  = %d\n",yytext, lignenum);
                break;

                case 12 :
                    // main
                     
                    printf("%s est un mot cle concernant le programme principal, ligne = %d\n",yytext, lignenum);
                break;

                case 13 :
                    //procedure
                     
                    printf("%s est un mot cle qui indique la déclaration d'une procedure, ligne = %d\n",yytext, lignenum);
                break;

                case 14 :
                    //deb-corps
                    printf("%s indique le debut du corps, ligne = %d\n",yytext, lignenum);
                break;

                case 15 :
                    //fin-corps
                    printf("%s indique la fin du corps, ligne = %d\n",yytext, lignenum);
                break;

                case 16 :
                    //si
                     
                    printf("%s est un mot cle equivalant a IF, ligne = %d\n",yytext, lignenum);
                break;

                case 17 :
                    // sinon
                     
                    printf("%s est un mot cle equivalant a ELSE, ligne = %d\n",yytext, lignenum);
                break;

                

                case 18 :
                    // repeat
                     
                    printf("%s est un mot cle  equivalant a WHILE, ligne = %d\n",yytext, lignenum);
                break;

                case 19 :
                    //iterator
                     
                    printf("%s est un mot cle  equivalant a FOR, ligne = %d\n",yytext, lignenum);
                break;

                

                case 20 :
                    //write
                     
                    printf("%s est un mot cle concernant la fonction d'ecriture, ligne = %d\n",yytext, lignenum);
                break;

                case 21 :
                    //read
                     
                    printf("%s est un mot cle concernant la fonction de lecture, ligne = %d\n",yytext, lignenum);
                break;

                
                case 22 :
                    //t_cons
                     
                    printf("%s est un mot cle indiquant une constante, ligne = %d\n",yytext, lignenum);
                break;

                

                case 23 :
                    //T_int
                     
                    printf("%s est un mot cle indiquant un entier, ligne = %d\n",yytext, lignenum);
                break;

                case 24 :
                    //T_flt
                     
                    printf("%s est un mot cle indiquant un flottant,ligne = %d\n",yytext, lignenum);
                break;

                case 25 :
                    //T_car
                     
                    printf("%s est un mot cle indiquant un caractere, ligne = %d\n",yytext, lignenum);
                break;

                case 26 :
                    //T_str
                     
                    printf("%s est un mot cle indiquant une chaine de caracteres, ligne = %d\n",yytext, lignenum);
                break;

                case 27 :
		    // ++
                     
                    printf("%s est un operateur arithmetique d'incrementation, ligne = %d\n",yytext, lignenum);
                break;

                case 28 :
                    // /
                     
                    printf("%s est un operateur arithmetique de division, ligne = %d\n",yytext, lignenum);
                break;

                case 29 :
		    // --
                     
                    printf("%s est un operateur arithmetique de decrementation, ligne = %d\n",yytext, lignenum);
                break;

                case 30 :
                    // *
                     
                    printf("%s est un operateur arithmetique de multiplication, ligne = %d\n",yytext, lignenum);
                break;

                case 31 :
                    // mod
                     
                    printf("%s est un operateur arithmetique de modulo, ligne = %d\n",yytext, lignenum);
                break;

                case 32 :
                    // (
                     
                    printf("%s est une parenthese ouvrante, ligne = %d\n",yytext, lignenum);
                break;

                case 33 :
                    // )
                     
                    printf("%s est une parenthese fermante, ligne = %d\n",yytext, lignenum);
                break;

                case 34 :
                    // <=
                     
                    printf("%s est un operateur de comparaison : inferieur ou egal, ligne = %d\n",yytext, lignenum);
                break;

                case 35 :
                    // <
                     
                    printf("%s est un operateur de comparaison : inferieur, ligne = %d\n",yytext, lignenum);
                break;

                case 36 :
                    // >
                     
                    printf("%s est un operateur de comparaison : supérieur, ligne = %d\n",yytext, lignenum);
                break;

                case 37 :
                    // >=
                     
                    printf("%s est un operateur de comparaison : supérieur ou egal, ligne = %d\n",yytext, lignenum);
                break;

                case 38 :
                // =
                     
                    printf("%s est un operateur de comparaison d'egalite, ligne = %d\n",yytext, lignenum);
                break;

                case 39 :
                // !=
                     
                    printf("%s est un operateur de comparaison d'inegalite, ligne = %d\n",yytext, lignenum);
                break;

                case 40 :
                // !
                     
                    printf("%s est un operateur logique NOT, ligne = %d\n",yytext, lignenum);
                break;

                case 41 :
                    // et
                     
                    printf("%s est un operateur logique AND, ligne = %d\n",yytext, lignenum);
                break;

                case 42 :
                    //ou
                     
                    printf("%s est un operateur logique OR, ligne = %d\n",yytext, lignenum);
                break;

                case 43 :
                    // <-
                     
                    printf("%s est une affectation, ligne = %d\n",yytext, lignenum);
                break;

                

                case 44 :
                // deb tab
                printf("%s est le debut d'un tableau, ligne = %d\n",yytext, lignenum);
                break;

                case 45 :
                // fin tab
                 printf("%s est la fin d'un tableau, ligne = %d\n",yytext, lignenum);
                break;

                case 46 :
                    //struct
                     
                    printf("%s est un mot cle pour definir une structure , ligne = %d\n",yytext, lignenum);
                break;
                case 49 :
                    //FIN_COMMENT
                     
                    printf("%s est la fin d'un commentaire , ligne = %d\n",yytext, lignenum);
                break;
                case 50 :
                    //TYPE_BLN
                     
                    printf("%s est un mot cle indiquant un boolean , ligne = %d\n",yytext, lignenum);
                break;

             case 51 :
                    //ELSEIF
                     
                    printf("%s est un mot cle equivalent a ELSEIF , ligne = %d\n",yytext, lignenum);
                break;
                case 52 :
                    //RETURN
                     
                    printf("%s est un mot cle qui indique le retour d'une fonction, ligne = %d\n",yytext, lignenum);
                break;
                case 53:
                    //CASE
                     
                    printf("%s est un mot cle equivalent a SWITCH, ligne = %d\n",yytext, lignenum);
                break;
                case 54:
                    //CASE_NUM
                     
                    printf("%s est un mot cle equivalent a CASE, ligne = %d\n",yytext, lignenum);
                break;
		case 56:
		    // Commentaire sur une ligne
			printf("%s est un commentaire , ligne = %d\n", yytext, lignenum);;
		break;
		case 57 :
                    //+
                     
                    printf("%s est un operateur arithmetique d'addition, ligne = %d\n",yytext, lignenum);
                break;
		case 58 :
                    // -
                     
                    printf("%s est un operateur arithmetique de soustraction, ligne = %d\n",yytext, lignenum);
                break;
                

            }
        token= yylex();
    }

    
    return 0;

}

 

 




