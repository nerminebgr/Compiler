#include "TableSymbole.h"

/********************************************************************************/
/** Création d'une table de symboles **/
SymbolTable* createSymbolTable() {
    SymbolTable* newTable = (SymbolTable*)malloc(sizeof(SymbolTable));
    newTable->head = NULL;
    newTable->tail = NULL;
    newTable->nbSymbol = 0;
    return newTable;
}

/** Création d'un symbole **/
Symbol* createSymbol(char* nom, char* type, int size, int numLigne, int adresse) {
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    newSymbol->nom = nom;
    newSymbol->type = type;
    newSymbol->size = size;
    newSymbol->numLigne = numLigne;
    newSymbol->adresse = adresse;
    newSymbol->previous = NULL;
    newSymbol->next = NULL;
    newSymbol->head = NULL;
    newSymbol->tail = NULL;
    return newSymbol;
}

/** Insertion d'un symbole au début de la table **/
void insertSymbolAtBeginning(SymbolTable* table, Symbol* newSymbol) {
    if (table->head == NULL) {
        table->head = newSymbol;
        table->tail = newSymbol;
    } else {
        newSymbol->next = table->head;
        table->head->previous = newSymbol;
        table->head = newSymbol;
    }
    table->nbSymbol++;
}

/** Recherche d'un symbole de la table **/
Symbol* symbolSearch(SymbolTable* table, char* symbolName) {
    Symbol* currentSymbol = table->head;

    while (currentSymbol != NULL) {
        if (strcmp(currentSymbol->nom, symbolName) == 0) {
            return currentSymbol;  // Symbol found
        }
        currentSymbol = currentSymbol->next;
    }

    return NULL;  // Symbol not found
}

/** Suppression d'un symbole de la table **/
void deleteSymbol(SymbolTable* table, Symbol* symbolToDelete) {
    
    if (symbolToDelete->previous == NULL) // symbol to delete is the head 
    { 
        table->head = symbolToDelete->next; 
        if (table->head != NULL) { // symbol to delete is not the only symbol in the table
            table->head->previous = NULL; 
        }
    } 
    else 
    {
        symbolToDelete->previous->next = symbolToDelete->next;
        if (symbolToDelete->next != NULL) {
            symbolToDelete->next->previous = symbolToDelete->previous;
        } else { // symbol to delete is the tail
            table->tail = symbolToDelete->previous;
        }
    }
    free(symbolToDelete);
    table->nbSymbol--;
}


/*******************************************************************************************/
/** Création d'un attribut **/
Attribute* createAttribute(char* attributeName, char* attributeValue) {
    Attribute* newAttribute = (Attribute*)malloc(sizeof(Attribute));
    newAttribute->Name = attributeName;
    newAttribute->value = attributeValue;
    newAttribute->previous = NULL;
    newAttribute->next = NULL;
    return newAttribute;
}

/** Insertion d'un attribut dans la liste des attributs associée à un symbole de la table **/
void insertAttribute(Symbol* symbol, Attribute* newAttribute) {
    if (symbol->head == NULL) {
        symbol->head = newAttribute;
        symbol->tail = newAttribute;
    } else {
        newAttribute->previous = symbol->tail;
        symbol->tail->next = newAttribute;
        symbol->tail = newAttribute;
    }
}

/** Recherche d'un attribut dans la liste des attributs associée à un symbole de la table **/
Attribute* attributeSearch(Symbol* symbol, char* attributeName) {
    Attribute* currentAttribute = symbol->head;

    while (currentAttribute != NULL) {
        if (strcmp(currentAttribute->Name, attributeName) == 0) {
            return currentAttribute;  // Attribute found
        }
        currentAttribute = currentAttribute->next;
    }

    return NULL;  // Attribute not found
}

/** Suppression d'un attribut de la liste des attributs associée à un symbole de la table **/
void deleteAttribute(Symbol* symbol, Attribute* attributeToDelete) {
    if (attributeToDelete->previous == NULL) {
        symbol->head = attributeToDelete->next;
        if (symbol->head != NULL) {
            symbol->head->previous = NULL;
        }
    } else {
        attributeToDelete->previous->next = attributeToDelete->next;
        if (attributeToDelete->next != NULL) {
            attributeToDelete->next->previous = attributeToDelete->previous;
        } else {
            symbol->tail = attributeToDelete->previous;
        }
    }
    free(attributeToDelete);
}



