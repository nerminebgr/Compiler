/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MY_PARSER_TAB_H_INCLUDED
# define YY_YY_MY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COMMENT = 258,                 /* COMMENT  */
    COMMENT_MULTILIGNE = 259,      /* COMMENT_MULTILIGNE  */
    CARACTERE = 260,               /* CARACTERE  */
    CHAR = 261,                    /* CHAR  */
    ENTIER = 262,                  /* ENTIER  */
    FLOTTANT = 263,                /* FLOTTANT  */
    BOOLEAN_VRAI = 264,            /* BOOLEAN_VRAI  */
    BOOLEAN_FAUX = 265,            /* BOOLEAN_FAUX  */
    MAIN = 266,                    /* MAIN  */
    PROCEDURE = 267,               /* PROCEDURE  */
    TYPE_CONS = 268,               /* TYPE_CONS  */
    TYPE_INT = 269,                /* TYPE_INT  */
    TYPE_FLT = 270,                /* TYPE_FLT  */
    TYPE_CAR = 271,                /* TYPE_CAR  */
    TYPE_STR = 272,                /* TYPE_STR  */
    TYPE_BLN = 273,                /* TYPE_BLN  */
    ID = 274,                      /* ID  */
    RETURN = 275,                  /* RETURN  */
    READ = 276,                    /* READ  */
    WRITE = 277,                   /* WRITE  */
    WHILE = 278,                   /* WHILE  */
    FOR = 279,                     /* FOR  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    SWITCH = 282,                  /* SWITCH  */
    CASE = 283,                    /* CASE  */
    CASE_BREAK = 284,              /* CASE_BREAK  */
    CASE_DEFAULT = 285,            /* CASE_DEFAULT  */
    STRUCT = 286,                  /* STRUCT  */
    FIN_INSTRUCTION = 287,         /* FIN_INSTRUCTION  */
    INCREM = 288,                  /* INCREM  */
    DECREM = 289,                  /* DECREM  */
    PLUS = 290,                    /* PLUS  */
    DIV = 291,                     /* DIV  */
    MOINS = 292,                   /* MOINS  */
    MUL = 293,                     /* MUL  */
    MOD = 294,                     /* MOD  */
    PUISS = 295,                   /* PUISS  */
    PAR_OUV = 296,                 /* PAR_OUV  */
    PAR_FERM = 297,                /* PAR_FERM  */
    INF_EGAL = 298,                /* INF_EGAL  */
    INF = 299,                     /* INF  */
    SUPP = 300,                    /* SUPP  */
    SUPP_EGAL = 301,               /* SUPP_EGAL  */
    EGALE = 302,                   /* EGALE  */
    PASEGALE = 303,                /* PASEGALE  */
    NEGATION = 304,                /* NEGATION  */
    ET = 305,                      /* ET  */
    OU = 306,                      /* OU  */
    DEB_TABLEAU = 307,             /* DEB_TABLEAU  */
    FIN_TABLEAU = 308,             /* FIN_TABLEAU  */
    AFFECTATION = 309,             /* AFFECTATION  */
    DEB_CORPS = 310,               /* DEB_CORPS  */
    FIN_CORPS = 311,               /* FIN_CORPS  */
    SEPARATEUR = 312,              /* SEPARATEUR  */
    ACCES_STRUCT = 313,            /* ACCES_STRUCT  */
    CASE_START = 314,              /* CASE_START  */
    ADRESSE = 315,                 /* ADRESSE  */
    IMPORT = 316                   /* IMPORT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "my_parser.y"

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

#line 140 "my_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MY_PARSER_TAB_H_INCLUDED  */
