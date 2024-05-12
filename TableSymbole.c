#include "TableSymbole.h"

/********************************************************************************/
int isIntOrfloat(int x){
    int result = 0 ; 
    if (x == 1 || x == 2){
        result = 1 ; 
    }
    return result ; 
}

int isInt(int x){
    int result = 0 ; 
    if (x == 1){
        result = 1 ; 
    }
    return result ; 
}


int isFlt(int x){
    int result = 0 ; 
    if (x == 2){
        result = 1 ; 
    }
    return result ; 
}



// création de la table des symboles
SymbolTable* createSymbolTable() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (table != NULL) {
        table->head = NULL;
        table->nbSymbol = 0;
    }
    return table;
}

// affichage table
void afficher(SymbolTable* table) {
    Symbol* current = table->head;
    printf("\nAffichage table des symboles :\n");
    while (current != NULL) {
        // Print symbol information
        printf("Nom: %s, Type: %d, Value: %s\n", current->nom, current->type, current->value);

        // Print attributes
        for (int i = 0; i < 20; i++) {
            if (current->attr[i].nom != NULL) {
                printf("  Attribute: %s, Value: %s, Type: %s\n", current->attr[i].nom,
                       current->attr[i].value, current->attr[i].type);
            }
        }

        current = current->next;
    }
}

// création d'un symbole
Symbol* createSymbol(char* nom, int type, char* value) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    if (symbol != NULL) {
        symbol->nom = strdup(nom);
        symbol->type = type;
        symbol->value = strdup(value);
        symbol->next = NULL;
        for (int i = 0; i < 20; i++) {
            symbol->attr[i].nom = NULL;
            symbol->attr[i].value = NULL;
            symbol->attr[i].type = NULL;
        }
    }
    return symbol;
}

// modify symbole
void SetTypeSymbol(Symbol* symbole, int type) {
    if (symbole != NULL) {
        symbole->type = type;
    }
}

void SetNomSymbol(Symbol* symbole, char* nom) {
    if (symbole != NULL) {
        free(symbole->nom);
        symbole->nom = strdup(nom);
    }
}

void SetValueSymbol(Symbol* symbole, char* value) {
    if (symbole != NULL) {
        free(symbole->value);
        symbole->value = strdup(value);
    }
}

// insertion symbole
void insertSymbol(SymbolTable* table, Symbol* newSymbol) {
    if (table != NULL && newSymbol != NULL) {
        newSymbol->next = table->head;
        table->head = newSymbol;
        table->nbSymbol++;
    }
}

// recherche
Symbol* symbolSearchNom(SymbolTable* table, char* symbolName) {
    Symbol* current = table->head;
    while (current != NULL) {
        if (strcmp(current->nom, symbolName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// supprimer symbole
void deleteSymbol(SymbolTable* table, Symbol* symbolToDelete) {
    if (table != NULL && symbolToDelete != NULL) {
        Symbol* current = table->head;
        Symbol* previous = NULL;

        while (current != NULL && current != symbolToDelete) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                table->head = current->next;
            }

            // Free memory
            free(current->nom);
            free(current->value);
            free(current);

            table->nbSymbol--;
        }
    }
}

// Pour les attributs
Attribute* createAttribute(char* attributeName, char* attributeValue, char* attributeType) {
    Attribute* attribute = (Attribute*)malloc(sizeof(Attribute));
    if (attribute != NULL) {
        attribute->nom = strdup(attributeName);
        attribute->value = strdup(attributeValue);
        attribute->type = strdup(attributeType);
    }
    return attribute;
}

void insertAttribute(Symbol* symbol, Attribute* newAttribute) {
    if (symbol != NULL && newAttribute != NULL) {
        int i = 0;
        while (i < 20 && symbol->attr[i].nom != NULL) {
            i++;
        }

        if (i < 20) {
            symbol->attr[i].nom = strdup(newAttribute->nom);
            symbol->attr[i].value = strdup(newAttribute->value);
            symbol->attr[i].type = strdup(newAttribute->type);
        }
    }
}

Attribute* attributeSearchNom(Symbol* symbol, char* attributeName) {
    if (symbol != NULL) {
        int i = 0;
        while (i < 20 && symbol->attr[i].nom != NULL) {
            if (strcmp(symbol->attr[i].nom, attributeName) == 0) {
                return &(symbol->attr[i]);
            }
            i++;
        }
    }
    return NULL;
}

void deleteAttribute(Symbol* symbol, Attribute* attributeToDelete) {
    if (symbol != NULL && attributeToDelete != NULL) {
        int i = 0;
        while (i < 20 && symbol->attr[i].nom != NULL) {
            if (&(symbol->attr[i]) == attributeToDelete) {
                // Free memory
                free(symbol->attr[i].nom);
                free(symbol->attr[i].value);
                free(symbol->attr[i].type);

                // Remove attribute
                symbol->attr[i].nom = NULL;
                symbol->attr[i].value = NULL;
                symbol->attr[i].type = NULL;
                return;
            }
            i++;
        }
    }
}




