
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>

    #include "TableSymbole.h"
    #include "quadruplet.h"
    #include "pile.h"

    SymbolTable *TS;
    qTable *TQ;
    qPile *P;

    qNoeud* quad;
    Symbol* node;

    int sauvLabel;

    int qC = 0;

    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    void yyerrorSemantic(char *s);
%}


%union
{
    int type;
    char str[255];
    char charv;
    int intv ; 
    float flt;
    bool boolean ; 
   
    struct {
            char* valeur;
            char* nom;
            int type;
        } structure;
}

// vide  ACCES_STRUCT

%token COMMENT COMMENT_MULTILIGNE
%token<charv> CARACTERE 
%token<str> CHAR
%token<intv>  ENTIER 
%token<flt> FLOTTANT
%token<boolean> BOOLEAN_VRAI BOOLEAN_FAUX

%token  MAIN PROCEDURE

%token<type> TYPE_CONS TYPE_INT TYPE_FLT TYPE_CAR TYPE_STR TYPE_BLN // those 

%token<str>  ID 
%token  RETURN READ WRITE WHILE FOR IF ELSE SWITCH CASE CASE_BREAK CASE_DEFAULT STRUCT
%token  FIN_INSTRUCTION INCREM DECREM PLUS DIV MOINS MUL MOD PUISS
%token  PAR_OUV PAR_FERM INF_EGAL INF SUPP SUPP_EGAL EGALE PASEGALE NEGATION ET OU
%token  DEB_TABLEAU FIN_TABLEAU AFFECTATION DEB_CORPS FIN_CORPS SEPARATEUR ACCES_STRUCT CASE_START
%token  ADRESSE IMPORT

%type<type> Type
%type<structure> expression
%type<structure> assignment
%type<structure> statement
%type<structure> Parameter


%left OU
%left ET
%left NEGATION INCREM DECREM
%left INF INF_EGAL SUPP SUPP_EGAL EGALE PASEGALE
%left PLUS MOINS
%left MUL DIV MOD PUISS 
%right PAR_OUV DEB_TABLEAU DEB_CORPS
%left PAR_FERM FIN_TABLEAU FIN_CORPS

%start Program 

%%

Program:
    {
        // initialisation des table des symboles et table des quadruplets 
        // et la pile de manipulation des quadruplets
        TS = createSymbolTable() ;  
        TQ = initialiserTQ() ;
        P = initialiserP();

    }

    imports DeclarationFunctions DeclarationFunctionMain {
        qC++;
        quad = creer_Q("fin", "", "", "", qC); // creer le quadruplet pour la fin 
        inserer_TQ(TQ, quad); 
        
        
        afficher(TS); // afficher TS pour confirmé 
        afficherTQ(TQ);  // afficher TQ pour confirmé 

        afficherTQDansFichier(TQ, "output.txt");

        printf("\nProgramme accepte.");
        }
    ;


imports: 
    /* empty */
    | imports import
    ;

import:
    IMPORT CHAR FIN_INSTRUCTION

DeclarationFunctionMain:
    MAIN DEB_CORPS statements FIN_CORPS 
    ;

DeclarationFunctions:
    /* empty */
    | DeclarationFunctions DeclarationFunction
    ;

DeclarationFunction:
    PROCEDURE Entete  
    ;

Entete: 
    Type ID PAR_OUV Parameters PAR_FERM DEB_CORPS statements RETURN expression FIN_INSTRUCTION FIN_CORPS
    | ID PAR_OUV Parameters PAR_FERM DEB_CORPS statements FIN_CORPS
    ;

Parameters:
    /* empty */
    | Parameters Parameter
    ;



// Type ayant le type int <type> 
// Chaque numéro concerne un type (de 0 à 5)
Type : 
    TYPE_INT {$$ = 1;} 
    | TYPE_FLT {$$ = 2;}
    | TYPE_STR {$$ = 4;}
    | TYPE_BLN {$$ = 5;}
    | TYPE_CAR {$$ = 3;}
    | TYPE_CONS {$$ = 0;}
    ;

Tableau :
    Type ID  DEB_TABLEAU ENTIER FIN_TABLEAU
    ;

Type_Struct : 
    STRUCT ID DEB_CORPS declarations FIN_CORPS
    ;

declarations:
    /* empty */
    | declarations declaration 
    ;


statements:
    /* empty */
    | statements statement 
    ;

signatureProcedure : 
    ID PAR_OUV ids PAR_FERM FIN_INSTRUCTION

statement:
    signatureProcedure
    | declaration 
    | assignment 
    | COMMENT
    | COMMENT_MULTILIGNE
    | ifStatement
    | whileStatement
    | forStatement
    | switchStatement
    | readStatement 
    | writeStatement 
    | expression INCREM FIN_INSTRUCTION  {
        printf("test x++;\n");
        if( isIntOrfloat($1.type)){
             char bff[255]; 
            if(isInt($1.type)){
                int result = atoi($1.valeur) + 1 ;
                $$.type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else {
                float result = atof($1.valeur) + 1 ;
                $$.type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff); 
            }

             qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("++", $1.nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("++", $1.valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
    | expression DECREM  FIN_INSTRUCTION {
       
        if( isIntOrfloat($1.type)){
             char bff[255]; 
            if(isInt($1.type)){
                int result = atoi($1.valeur) - 1 ;
                $$.type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else {
                float result = atof($1.valeur) - 1 ;
                $$.type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff); 
            }

             qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("--", $1.nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("--", $1.valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
    ;

declaration:
    Parameter FIN_INSTRUCTION
    ;

Parameter:
    Type ID {  
        node = createSymbol($2, $1, NULL); // creer le Symbol de ID id et type Type 
        insertSymbol(TS, node); 
        char bff[255]; 
        strcpy(bff,$2);

        $$.nom = strdup(bff); // passer à parameter le nom et le type 
        $$.type = $1;
    }
    | Tableau
    | Type_Struct
    ;

assignment:
    Parameter AFFECTATION expression {
    
        if (node = symbolSearchNom(TS, $1.nom)){ 
           
            // test for constante first 
            if($1.type == 0){
                qC++;
                SetValueSymbol(node,$3.valeur ); // màj valeur de node 
                quad = creer_Q(":=", $1.nom ," " , $3.valeur, qC);
                inserer_TQ(TQ,quad);
            }
            // test if compatible types 
            else if($1.type == $3.type){
                qC++;
                SetValueSymbol(node,$3.valeur ); // màj valeur de node 
                quad = creer_Q(":=", $1.nom ," " , $3.valeur, qC);
                inserer_TQ(TQ,quad);
            }
            else {
                yyerrorSemantic("\nType incompatible dans l'affectation. ");
               
            }
        }
        else{
            yyerrorSemantic("\nid non declare"); 
            //juste pour tester la partie de parameter 
            // on ne rentre jamais ici
        }

    } FIN_INSTRUCTION
    | ID AFFECTATION expression FIN_INSTRUCTION {
        if (node = symbolSearchNom(TS, $1)){ // is declared

            int type = node->type ;
        
            // test if compatible types 
            if(type == $3.type){
                qC++;
                SetValueSymbol(node,$3.valeur ); // màj valeur de node 
                quad = creer_Q(":=", $1 ," " , $3.valeur, qC);
                inserer_TQ(TQ,quad);
            }
            else {
                 yyerrorSemantic("\nType incompatible dans l'affectation. ");
            }
        }else{
            yyerrorSemantic("\nid non declare");
        }

    }
    ;

signatureFonction : 
    ID PAR_OUV ids PAR_FERM 

ids : 
    /* empty */
    | ids ID 
    ;


expression:
    // affecter le type et la valeur correspondante 
    ENTIER { 
        char bff[255]; 
        sprintf(bff, "%d", $1); 
        $$.valeur = strdup(bff);
        $$.type = 1;
    }
    | FLOTTANT {
        char bff[255]; 
        sprintf(bff, "%f", $1); 
        $$.valeur = strdup(bff);
        $$.type = 2;
    }
    | CHAR {
        $$.valeur = strdup($1);
        $$.type = 4;
    }
    | CARACTERE {
        char bff[255]; 
        sprintf(bff, "%c", $1); 
        $$.valeur = strdup(bff);
        $$.type = 3;
    }
    | BOOLEAN_VRAI {
        $$.valeur = strdup("vrai");
        $$.type = 5;
    }
    | BOOLEAN_FAUX {
        $$.valeur = strdup("faux");
        $$.type = 5;
    }


    | ID DEB_TABLEAU ENTIER FIN_TABLEAU | ID ACCES_STRUCT ID

    | ID {
        $$.nom = strdup($1);
        
        if (node = symbolSearchNom(TS, $1)){ // rechercher id dans TS
            $$.valeur = strdup(node->value);
            $$.type = node->type ;
        }else{
            yyerrorSemantic("\nid non declare");
        }
    }

    | signatureFonction 

    | expression PLUS expression  { 
        
        if( isIntOrfloat($1.type) & isIntOrfloat($3.type))  // addition de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt($1.type) & isInt($3.type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi($1.valeur) + atoi($3.valeur);
                $$.type = 1 ; // int

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof($1.valeur) + atof($3.valeur);
                $$.type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff);
            }


            qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ($3.nom != NULL){ 
                        node = symbolSearchNom(TS, $3.nom);
                        if(node==NULL){
                             yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("+", $1.nom , $3.nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("+", $1.nom , $3.valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ($3.nom != NULL){  // is id
                    node = symbolSearchNom(TS, $3.nom);
                    if(node==NULL){
                         yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("+", $1.valeur , $3.nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("+", $1.valeur , $3.valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);

          
        }
    }
    | expression MOINS expression {
        if( isIntOrfloat($1.type) & isIntOrfloat($3.type))  // soustraction de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt($1.type) & isInt($3.type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi($1.valeur) - atoi($3.valeur);
                $$.type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof($1.valeur) - atof($3.valeur);
                $$.type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff);
            }

            qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ($3.nom != NULL){ 
                        node = symbolSearchNom(TS, $3.nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("-", $1.nom , $3.nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("-", $1.nom , $3.valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ($3.nom != NULL){  // is id
                    node = symbolSearchNom(TS, $3.nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("-", $1.valeur , $3.nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("-", $1.valeur , $3.valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
        }
    }
    | expression MUL expression {
        if( isIntOrfloat($1.type) & isIntOrfloat($3.type))  // multiplication de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt($1.type) & isInt($3.type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi($1.valeur) * atoi($3.valeur);
                $$.type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof($1.valeur) * atof($3.valeur);
                $$.type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff);
            }

            qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ($3.nom != NULL){ 
                        node = symbolSearchNom(TS, $3.nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("*", $1.nom , $3.nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("*", $1.nom , $3.valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ($3.nom != NULL){  // is id
                    node = symbolSearchNom(TS, $3.nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("*", $1.valeur , $3.nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("*", $1.valeur , $3.valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
        }

    }
    | expression DIV expression {
        
        if( isIntOrfloat($1.type) & isIntOrfloat($3.type))  // division de 2 nombres int or float 
        {
            if ( atoi($3.valeur) == 0 || atof($3.valeur) == 0 ){
                yyerrorSemantic("\nDivision par Zero");
            }
            else {
            char bff[255]; 
            if (isInt($1.type) & isInt($3.type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi($1.valeur) / atoi($3.valeur);
                $$.type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof($1.valeur) / atof($3.valeur);
                $$.type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff);
            }

            qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ($3.nom != NULL){ 
                        node = symbolSearchNom(TS, $3.nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("/", $1.nom , $3.nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("/", $1.nom , $3.valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ($3.nom != NULL){  // is id
                    node = symbolSearchNom(TS, $3.nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("/", $1.valeur , $3.nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("/", $1.valeur , $3.valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
            }
        }

    }
    | expression MOD expression {
        if( isIntOrfloat($1.type) & isIntOrfloat($3.type))  // division de 2 nombres int or float 
        {
            if ( atoi($3.valeur) == 0 || atof($3.valeur) == 0 ){
                yyerrorSemantic("\nModulo Zero");
            }
            else {
            char bff[255]; 
            if (isInt($1.type) & isInt($3.type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi($1.valeur) % atoi($3.valeur);
                $$.type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else { // sinon ==> result float
                double result = fmod(atof($1.valeur), atof($3.valeur));
                $$.type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff);
            }

            qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ($3.nom != NULL){ 
                        node = symbolSearchNom(TS, $3.nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("%", $1.nom , $3.nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("%", $1.nom , $3.valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ($3.nom != NULL){  // is id
                    node = symbolSearchNom(TS, $3.nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("%", $1.valeur , $3.nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("%", $1.valeur , $3.valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
            }
        }
    }
    | expression PUISS expression 
    | NEGATION expression   {
        if ($2.type == 5) {  // Check if the expression is of boolean type
            char op[255];
            if ($2.nom != NULL) {
                strcpy(op, $2.nom);
            } else {
                strcpy(op, $2.valeur);
            }

            char result[255];
            if (strcmp($2.valeur,"vrai") == 0) {
                strcpy(result, "faux");
            } else {
                strcpy(result, "vrai");
            }

            // Update semantic values
            $$.type = 5;  // boolean type
            $$.valeur = strdup(result);
            qC++;
            // Insert the quadruplet
            quad = creer_Q("!", op, "", $$.valeur, qC);
            inserer_TQ(TQ, quad);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerrorSemantic("Error: Logical negation applied to non-boolean type");
        }
    }
    
    | expression INCREM  {
       
        if( isIntOrfloat($1.type)){
             char bff[255]; 
            if(isInt($1.type)){
                int result = atoi($1.valeur) + 1 ;
                $$.type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else {
                float result = atof($1.valeur) + 1 ;
                $$.type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff); 
            }

             qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("++", $1.nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("++", $1.valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
    | expression DECREM {
       
        if( isIntOrfloat($1.type)){
             char bff[255]; 
            if(isInt($1.type)){
                int result = atoi($1.valeur) - 1 ;
                $$.type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy($$.valeur,bff);
            }
            else {
                float result = atof($1.valeur) - 1 ;
                $$.type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy($$.valeur,bff); 
            }

             qC++ ; //// increment qC

            if ($1.nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("--", $1.nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("--", $1.valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
    | PAR_OUV expression PAR_FERM
    {   $$.nom = $2.nom;
        $$.valeur = $2.valeur;
        $$.type = $2.type;
    }
    | expression INF expression {
            if(isIntOrfloat($1.type) && isIntOrfloat($3.type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if($1.nom != NULL){strcpy(op1, $1.nom); } else {strcpy(op1, $1.valeur);}
                if($3.nom != NULL){strcpy(op2, $3.nom);} else {strcpy(op2, $3.valeur);}

                float val1 = atof($1.valeur);
                float val2 = atof($3.valeur);

                char result[255];
                if(val1 < val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                $$.type = 5;
               
                $$.valeur = strdup(result);

                quad = creer_Q("<", op1, op2, $$.valeur, qC++);
                inserer_TQ(TQ, quad);
               
                $$.nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
    | expression INF_EGAL expression {
            if(isIntOrfloat($1.type) && isIntOrfloat($3.type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if($1.nom != NULL){strcpy(op1, $1.nom); } else {strcpy(op1, $1.valeur);}
                if($3.nom != NULL){strcpy(op2, $3.nom);} else {strcpy(op2, $3.valeur);}

                float val1 = atof($1.valeur);
                float val2 = atof($3.valeur);

                char result[255];
                if(val1 < val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                $$.type = 5;
               
                $$.valeur = strdup(result);

                quad = creer_Q("<=", op1, op2, $$.valeur, qC++);
                inserer_TQ(TQ, quad);
               
                $$.nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
    | expression SUPP expression {
            if(isIntOrfloat($1.type) && isIntOrfloat($3.type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if($1.nom != NULL){strcpy(op1, $1.nom); } else {strcpy(op1, $1.valeur);}
                if($3.nom != NULL){strcpy(op2, $3.nom);} else {strcpy(op2, $3.valeur);}

                float val1 = atof($1.valeur);
                float val2 = atof($3.valeur);

                char result[255];
                if(val1 > val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                $$.type = 5;
               
                $$.valeur = strdup(result);

                quad = creer_Q(">", op1, op2, $$.valeur, qC++);
                inserer_TQ(TQ, quad);
               
                $$.nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
    | expression SUPP_EGAL expression {
            if(isIntOrfloat($1.type) && isIntOrfloat($3.type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if($1.nom != NULL){strcpy(op1, $1.nom); } else {strcpy(op1, $1.valeur);}
                if($3.nom != NULL){strcpy(op2, $3.nom);} else {strcpy(op2, $3.valeur);}

                float val1 = atof($1.valeur);
                float val2 = atof($3.valeur);

                char result[255];
                if(val1 >= val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                $$.type = 5;
               
                $$.valeur = strdup(result);

                quad = creer_Q(">=", op1, op2, $$.valeur, qC++);
                inserer_TQ(TQ, quad);
               
                $$.nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }

    | expression EGALE expression {
        if(isIntOrfloat($1.type) && isIntOrfloat($3.type)){
            char op1[255];
            char op2[255]; 
            if($1.nom != NULL){ // id 
                node = symbolSearchNom(TS, $1.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else {
                    strcpy(op1, $1.nom);
                }   
            }
            else {
                strcpy(op1, $1.valeur);
            }

            if($3.nom != NULL){ // id 
                node = symbolSearchNom(TS, $3.nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else {
                    strcpy(op2, $3.nom);

                }   
            }
            else {
                strcpy(op2, $3.valeur);

            }

            float val1 = atof($1.valeur);
            float val2 = atof($3.valeur);

            char result[255];
            if(val1 == val2) {
                    strcpy(result, "true");
            }

       
 
            $$.type = 5; // expression.type = bool
              
            $$.valeur = strdup(result); // la valeur de la comparaison

            qC++;
            quad = creer_Q("==", op1, op2, $$.valeur, qC);
            inserer_TQ(TQ, quad);
            
            $$.nom = NULL;
            
        }

    }
    | expression PASEGALE expression {
        if(isIntOrfloat($1.type) && isIntOrfloat($3.type)){
            char op1[255];
            char op2[255];
            if($1.nom != NULL){ // id 
                    Symbol* symbole = symbolSearchNom(TS, $1.nom);
                    if(symbole==NULL){
                        printf("\n id %s not declared before !\n",$1.nom); yyerrorSemantic("error sem");
                    }
                    else {
                        strcpy(op1, $1.nom);
                        printf("nom1 = %s",op1) ; 
                    }   
                }
                else {
                    strcpy(op1, $1.valeur);
                    printf("valeur1 = %s",op1) ; 
                }

                if($3.nom != NULL){ // id 
                    Symbol* symbole = symbolSearchNom(TS, $3.nom);
                    if(symbole==NULL){
                        printf("\n id %s not declared before !\n",$3.nom); yyerrorSemantic("error sem");
                    }
                    else {
                        strcpy(op2, $3.nom);
                    
                    printf("nom2 = %s",op2) ; 
                    }   
                }
                else {
                    strcpy(op2, $3.valeur);
                    printf("valeur = %s",op2) ; 
                }


            float val1 = atof($1.valeur);
            float val2 = atof($3.valeur);

            char result[255];
             if(val1 != val2) {
                    //expression is true
                    strcpy(result, "true");
            } 

            $$.type = 5;
            $$.valeur = strdup(result);


            quad = creer_Q("!=", op1, op2, $$.valeur, qC++);
            inserer_TQ(TQ, quad);
            
            $$.nom = NULL;
        }
    }
    | expression ET expression {
    if ($1.type == 5 && $3.type == 5) {
        char op1[255];
        char op2[255];
        
        // Gérer le premier opérande
        if ($1.nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, $1.nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", $1.nom); 
                yyerrorSemantic("error sem");
            } else {
                strcpy(op1, $1.nom);
            }
        } else {
            strcpy(op1, $1.valeur);
        }

        // Gérer le deuxième opérande
        if ($3.nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, $3.nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", $3.nom);
                yyerrorSemantic("error sem");
            } else {
                strcpy(op2, $3.nom);
            }
        } else {
            strcpy(op2, $3.valeur);
        }

        char result[255];
        if (strcmp($1.valeur, "faux") == 0 || strcmp($3.valeur, "faux") == 0) {
            strcpy(result, "faux");
        } else {
            strcpy(result, "vrai");
        }

        $$.type = 5;
        $$.valeur = strdup(result);

        quad = creer_Q("&&", op1, op2, $$.valeur, qC++);
        inserer_TQ(TQ, quad);

        $$.nom = NULL;
    } else {
        printf("Erreur Semantique : Type incompatible\n");
        yyerrorSemantic("Error: Logical AND applied to non-boolean type");
    }
}
    | expression OU expression {
    if ($1.type == 5 && $3.type == 5) {
        char op1[255];
        char op2[255];
        
        // Gérer le premier opérande
        if ($1.nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, $1.nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", $1.nom); 
                yyerrorSemantic("error sem");
            } else {
                strcpy(op1, $1.nom);
            }
        } else {
            strcpy(op1, $1.valeur);
        }

        // Gérer le deuxième opérande
        if ($3.nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, $3.nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", $3.nom);
                yyerrorSemantic("error sem");
            } else {
                strcpy(op2, $3.nom);
            }
        } else {
            strcpy(op2, $3.valeur);
        }

        char result[255];
        if (strcmp($1.valeur, "vrai") == 0 || strcmp($3.valeur, "vrai") == 0) {
            strcpy(result, "vrai");
        } else {
            strcpy(result, "faux");
        }

        $$.type = 5;
        $$.valeur = strdup(result);
         qC++;
        quad = creer_Q("|", op1, op2, $$.valeur, qC);
        inserer_TQ(TQ, quad);

    } else {
        printf("Erreur Semantique : Type incompatible\n");
    
    }
}


    ;

    ;

ifStatement:
    IF PAR_OUV expression PAR_FERM DEB_CORPS statements FIN_CORPS elseBlock
    ;


elseBlock:
    /* empty */
    | ELSE DEB_CORPS statements FIN_CORPS
    ;

whileStatement:
    while_part1 while_part2 while_part3 ;

while_part1:
    WHILE PAR_OUV 
         {
            // debut while 
            // Sauvegarde de l'@ deb, avant la condition
            sauvLabel = qC+1 ; 
         } 

        ;

while_part2:
expression 
         {
            if($1.type != 5) {
                yyerrorSemantic("\nCondition dans while de type non boolean");
            }

            // Apres l'evaluation de la cond, on fait un branchement si cond == faux vers fin 
            qC++ ; 
            quad = creer_Q("BZ", "finWhile", " ",$1.valeur, qC);
            inserer_TQ(TQ, quad);
            push(P, quad);

         }
    ;

while_part3 :
          PAR_FERM DEB_CORPS statements FIN_CORPS 
         {
            // R3 

            qC++ ;  
            quad = pop(P);
            updateLabel(quad, qC+1); // MAJ l'@ defin "finWhile"

            // branchement vers l'@ du debut
            char etiq[255];
            itoa(sauvLabel, etiq, 10);
            quad = creer_Q("BR", etiq, "" , "", qC);
            inserer_TQ(TQ, quad);
    
        }
    ;

forStatement:
    FOR PAR_OUV expression FIN_INSTRUCTION expression FIN_INSTRUCTION expression PAR_FERM DEB_CORPS statements FIN_CORPS
    ;

switchStatement:
    SWITCH PAR_OUV expression PAR_FERM DEB_CORPS caseBlocks defaultBlock FIN_CORPS
    ;

caseBlocks:
    /* empty */
    | caseBlocks CASE expression CASE_START statements CASE_BREAK FIN_INSTRUCTION
    ;

defaultBlock:
    /* empty */
    | CASE_DEFAULT CASE_START statements 
    ;

readStatement:
    READ PAR_OUV CHAR SEPARATEUR ADRESSE ID PAR_FERM FIN_INSTRUCTION
    ;

writeStatement: 
    WRITE PAR_OUV CHAR SEPARATEUR expression PAR_FERM FIN_INSTRUCTION
    | WRITE PAR_OUV CHAR PAR_FERM FIN_INSTRUCTION
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(EXIT_FAILURE);
}

void yyerrorSemantic(char *s){
    printf("\nErreur semantique : %s",s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    yyin = fopen("final_test.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}
