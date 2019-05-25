#include <iostream>
#include <stdlib.h>
#include "Function.hpp"

using namespace std;

struct State{
    string name; //Nombre del Estado
    int ei; //Estado Inicio
    int ef; //Estado Llegada
    bool fin; //Comprobación de Estado Final
    function *fun; //Puntero hacia la Transición
    State *next; //Puntero al siguiente Estado

    State(){ //Constructor
        fin = false; //Estado final se inicializa como falso
    }

}; typedef struct State state;

void createInitialState(state **S, string name){
    state *p = new state;
    p->name = name;
    p->next = *S;
    *S = p;
}