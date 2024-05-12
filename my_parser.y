%{
    #include <stdio.h>
    #include <stdlib.h>

    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
%}


%union
{
char str[100];
char charv;
int intv ; 
float flt;
}

// vide  ACCES_STRUCT

%token COMMENT COMMENT_MULTILIGNE
%token  CARACTERE CHAR
%token  ENTIER FLOTTANT
%token  BOOLEAN_VRAI BOOLEAN_FAUX
%token  MAIN PROCEDURE
%token  TYPE_CONS TYPE_INT TYPE_FLT TYPE_CAR TYPE_STR TYPE_BLN
%token  RETURN READ WRITE WHILE FOR IF ELSE SWITCH CASE CASE_BREAK CASE_DEFAULT STRUCT
%token  ID FIN_INSTRUCTION INCREM DECREM PLUS DIV MOINS MUL MOD PUISS
%token  PAR_OUV PAR_FERM INF_EGAL INF SUPP SUPP_EGAL EGALE PASEGALE NEGATION ET OU
%token  DEB_TABLEAU FIN_TABLEAU AFFECTATION DEB_CORPS FIN_CORPS SEPARATEUR ACCES_STRUCT CASE_START
%token  ADRESSE  


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
    DeclarationFunctionMain DeclarationFunctions {printf("accept\n");}
    ;

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

Type :
    TYPE_INT
    | TYPE_FLT
    | TYPE_STR
    | TYPE_BLN
    | TYPE_CAR
    | TYPE_CONS
    ;

Tableau :
    Type ID DEB_TABLEAU ENTIER FIN_TABLEAU
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

statement:
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
    | expression INCREM  FIN_INSTRUCTION
    | expression DECREM  FIN_INSTRUCTION
    ;

declaration:
    Parameter FIN_INSTRUCTION
    ;

Parameter:
    Type ID
    | Tableau
    | Type_Struct
    ;

assignment:
     Parameter AFFECTATION expression FIN_INSTRUCTION
    | ID AFFECTATION expression FIN_INSTRUCTION
    ;

expression:
    ENTIER | FLOTTANT
    | CHAR | CARACTERE
    | ID DEB_TABLEAU ENTIER FIN_TABLEAU | ID ACCES_STRUCT ID
    | BOOLEAN_VRAI | BOOLEAN_FAUX
    | ID
    | expression PLUS expression
    | expression MOINS expression
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    | expression PUISS expression 
    | NEGATION expression 
    | expression INCREM 
    | expression DECREM
    | PAR_OUV expression PAR_FERM
    | expression INF expression
    | expression INF_EGAL expression
    | expression SUPP expression
    | expression SUPP_EGAL expression
    | expression EGALE expression
    | expression PASEGALE expression
    | expression ET expression
    | expression OU expression

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
    WHILE PAR_OUV expression PAR_FERM DEB_CORPS statements FIN_CORPS
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

int main(int argc, char *argv[]) {
    yyin = fopen("test.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}
