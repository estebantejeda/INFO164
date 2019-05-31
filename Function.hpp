#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Function{
    string name; //Nombre de Estado de Destino
    char symbol; //Letra de la Función de Transición
    Function *next; //Puntero a la siguiente Función
}; typedef struct Function function;

void createFunction(function **F, string name, char symbol){
    //Variables Iniciales
    function *p = new function;
    p->name = name;
    p->symbol = symbol;
    p->next = nullptr;
    
    //Creación de Función
    p->next = *F;
    *F = p;
}

bool searchSymbol(function *F, char symbol){
    while(F != nullptr && F->symbol != symbol) F = F->next;
    if(F == nullptr) return true;
    return false;
}