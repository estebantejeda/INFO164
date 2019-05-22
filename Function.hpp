#include <iostream>
#include <stdlib.h>

using namespace std;

struct Function{
    char letter; //Letra de la Función de Transición
    Function *next; //Puntero a la siguiente Función
}; typedef struct Function function;