#ifndef SymbolTable_H
#define SymbolTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure*/
/*************************************************************************************/
typedef struct Attribute
{   
    char *Name;
    char *value;
    struct Attribute *previous;
    struct Attribute *next;

} Attribute;

typedef struct Symbol
{
    char *nom;          
    char *type;          
    int size;                     
    int numLigne;          
    int adresse;
  
    struct Symbol *previous; 
    struct Symbol *next; 

    Attribute *head;      
    Attribute *tail;        

} Symbol;


typedef struct SymbolTable
{
    Symbol *head;
    Symbol *tail;
    int nbSymbol;

} SymbolTable;






/*Entetes*/
/*****************************************************************************************/
SymbolTable* createSymbolTable();
Symbol* createSymbol(char* nom, char* type, int size, int numLigne, int adresse);
void insertSymbolAtBeginning(SymbolTable* table, Symbol* newSymbol);
Symbol* symbolSearch(SymbolTable* table, char* symbolName);
void deleteSymbol(SymbolTable* table, Symbol* symbolToDelete);
Attribute* createAttribute(char* attributeName, char* attributeValue);
void insertAttribute(Symbol* symbol, Attribute* newAttribute);
Attribute* attributeSearch(Symbol* symbol, char* attributeName);
void deleteAttribute(Symbol* symbol, Attribute* attributeToDelete);
/*****************************************************************************************/
#endif


