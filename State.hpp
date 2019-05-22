#include <iostream>
#include <stdlib.h>

using namespace std;

struct State{
    string name; //Nombre del Estado
    bool fin; //Comprobación de Estado Final
    State *next; //Puntero al siguiente Estado
}; typedef struct State state;