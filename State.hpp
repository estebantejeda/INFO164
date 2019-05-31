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

/* void createState(state **S, string name){
* 
* Recibe: El puntero de Estado (**S) y el nombre del estado que se
* quiere crear
*
* Entrega: Al ser un método void no retorna nada, pero lo que realiza
* es crear un estado con las variables preestablecidad y los agrega a
* la estructura de datos
*
* Explicación: Se crea un puntero nulo (*p) al cuál se le agregan las
* variables iniciales como el nombre, el estado final en falso (fin = false)
* y un puntero al siguiente estado que sea nulo.
* Una vez realizado esto, comprueba si el puntero *p está vacío. En caso de que
* lo esté, lo deja en primera posición, en caso contrario, recorre la estructura
* hasta llegar al último estado y hace que este estado apunte al que se ha
* creado recién.
*/

void createState(state **S, string name){
    //Variables Iniciales
    state *p = new state;
    p->name = name;
    p->fin = false;
    p->next = nullptr;
    //Creación de Estados
    if(*S==nullptr) *S = p;
    else{
        state *q = *S;
        while(q->next != nullptr) q = q->next;
        q->next = p;
    }
}

/* void addFunction(state **S, string nameI, string nameD, char symbol) PENDIETE
*
* Recibe: El puntero de la estructura, el nombre del estado al cuál se le
* quiere añadir la función de transición (nameI), el nombre del estado
* al que se quiere llegar (nameD) y el símbolo de la función de transición
*
* Entrega: Al ser un método void no retorna nada, pero lo que hace es
* copiar la estructura de datos por medio de un nuevo puntero *p (Esto, para
* que la estructura original no se vea afectada), y recorrerla hasta encontrar
* el nombre el estado nameI dentro de la estructura.
* Una vez que encuentra la posición de nameI, llama al método 
* createFunction(function **F, string name, char symbol), el cuál
* toma el nombre del estado de déstino (nameD) y el símbolo de la función
* de transición (symbol) y lo agrega a la estructura de datos Function
*/

void addFunction(state **S, string nameI, string nameD, char symbol){
    state *p = *S;
    while(p->name != nameI) p = p->next;
    //createFunction(f, nameD, symbol);
}

/* void changeFinalState(state *S, string name)
*
* Recibe: El puntero del estado (*S) y el nombre del estado al cuál se le
* quiere dejar como final
*
* Entrega: Al ser un método void no retorna nada, pero la función cambia el
* estado "fin" a "true" para demostrar que el estado es un estado final
*
* Explicación: El método recibe el el nombre del estado el cual
* se quiere dejar como final. Se recorre la estructura para
* buscar el estado, y una vez que lo encuentra cambia la
* variable "fin" como true.
*/

void changeFinalState(state *S, string name){
    while(S != nullptr && S->name != name) S = S->next;
    S->fin = true;
}

/* bool searchState(state *S, string name)
*
* Recibe: El puntero del estado (*S) y el nombre del estado al cuál se quiera
* buscar
*
* Entrega: Al ser un método void no retorna nada, pero la función busca si el
* estado de nombre "name" existe
*
* Explicación: El método recibe el el nombre del estado el cual
* se quiere buscar. Con esto, empieza a recorrer la estructura.
* Si el método no encuentra la estructura, entonces retorna
* un "true", mientras que si no lo encuentra, retorna un "false"
*/

bool searchState(state *S, string name){
    while(S != nullptr && S->name != name) S = S->next;
    if(S == nullptr) return true;
    return false;
}

//Métodos de Desarrollo. Serán eliminados una vez se finalice el programa

void print(state *S){
    while(S->next != nullptr){
        cout << S->name << endl;
        S = S->next;
    }
    cout << S->name << endl;
}