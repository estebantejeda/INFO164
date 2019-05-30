#include <iostream>
#include <stdlib.h>
#include "Function.hpp"

using namespace std;

struct State{
    string name; //Nombre del Estado
    bool fin; //Comprobación de Estado Final
    function *fun; //Puntero hacia la Transición
    State *next; //Puntero al siguiente Estado
}; typedef struct State state;

void createState(state **S, string name){
    //Variables Iniciales
    state *p = new state;
    function *f = new function;
    p->name = name;
    p->fin = false;
    p->fun = f;
    p->next = nullptr;

    //Creación de Estados
    if(*S==nullptr){
        *S = p;
    }
    else{
        state *q = *S;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }
}

void addFunction(state **S, string nameI, string nameD, char symbol){
    
}

bool searchState(state *S, string name){
    while(S != nullptr && S->name != name){
        S = S->next;
    }
    if(S == nullptr) return true;
    return false;
}

void print(state *S){
    while(S->next != nullptr){
        cout << S->name << endl;
        S = S->next;
    }
    cout << S->name << endl;
}