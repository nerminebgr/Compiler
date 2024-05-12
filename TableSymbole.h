#ifndef SymbolTable_H
#define SymbolTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure*/
/*************************************************************************************/
typedef struct Attribute
{   
    char *nom;
    char *value;
    char *type;

} Attribute;

typedef struct Symbol
{
    char *nom;          
    int type;                              
    char *value;         

    struct Attribute attr[20]; 

    struct Symbol *next;    

} Symbol;


typedef struct SymbolTable // LLC
{
    Symbol *head; // tete
    int nbSymbol; // longueur 

} SymbolTable;


/*Entetes*/
/*****************************************************************************************/
int isIntOrfloat(int x);
int isInt(int x);
int isFlt(int x);

/*****************************************************************************************/
// création de la table des symboles 
SymbolTable* createSymbolTable();  

// affichage table 
void afficher(SymbolTable* table); 

// création d'un symbole 
Symbol* createSymbol(char* nom, int type,char* value);


// modify symbole 
void SetTypeSymbol(Symbol* symbole, int type);
void SetNomSymbol(Symbol* symbole, char* nom);
void SetValueSymbol(Symbol* symbole, char* value);


// insertion symbole 
void insertSymbol(SymbolTable* table, Symbol* newSymbol);

// recherche 
Symbol* symbolSearchNom(SymbolTable* table, char* symbolName);

// supprimer symbole 
void deleteSymbol(SymbolTable* table, Symbol* symbolToDelete);

// Pour les attributs
Attribute* createAttribute(char* attributeName, char* attributeValue, char* attributeType);
void insertAttribute(Symbol* symbol, Attribute* newAttribute);
Attribute* attributeSearchNom(Symbol* symbol, char* attributeName);
void deleteAttribute(Symbol* symbol, Attribute* attributeToDelete);
/*****************************************************************************************/
#endif


