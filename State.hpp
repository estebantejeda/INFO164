#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct State{
    string name; //Nombre del Estado
    vector<string> nameD; // Vector que almacena el nombre de los estados de destino
    vector<char> symbol; // Vector que almacena el símbolo de transición
    bool fin; //Comprobación de Estado Final
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

/* void addFunction(state **S, string nameI, string nameD, char symbol)
*
* Recibe: El puntero de la estructura, el nombre del estado al cuál se le
* quiere añadir la función de transición (nameI), el nombre del estado
* al que se quiere llegar (nameD) y el símbolo de la función de transición
*
* Entrega: Al ser un método void no retorna nada, pero lo que hace es
* almacenar dentro de un vector el nombre del estado de destino (nameD)
* y su símbolo (symbol) para su función de transición
*
* Explicación: La función recibe el puntero que almacena la estructura de datos,
* luego de esto, comienza a recorrer la estructura hasta que encuentra el nombre
* del estado que estamos buscando (nameI). Una vez hecho lo anterior, procede a
* almacenar dentro de este el estado al que quiere llegar (nameD) y el símbolo
* (symbol) dentro de sus respectivos vectores.
*
*/

void addFunction(state **S, string nameI, string nameD, char symbol){
    state *p = *S;
    while(p->name != nameI) p = p->next;
    p->nameD.push_back(nameD);
    p->symbol.push_back(symbol);
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

/* searchSymbol(state *S, string nameI, char symbol)
* 
* Recibe: El puntero del estado (*S), el nombre del estado (name) al cual se
* le quiere buscar el símbolo (symbol)
*
* Entrega: Al ser un método void no retorna nada, pero la función busca si el
* estado tiene algún símbolo repetido
*
* Explicación: Primero, el método busca la ubicación del estado "name". Una vez
* la obtiene, busca si el vector de símbolos (S->symbol) está vacío. 
* Si el vector está vacío, entonces retorna un true, en caso contrario creo una
* variable auxiliar para recorrer todos los elementos del arreglo con el fin
* de buscar si el símbolo está repetido.
* Si el símbolo no es encontrado, entonces el contador será mayor que la cantidad
* de elementos del vector. Si esto ocurre, retorna un true. En caso contrario,
* retorna un false (El elemento sí se encuentra).
*/

bool searchSymbol(state *S, string name, char symbol){
    while(S != nullptr && S->name != name) S = S->next;
    if (S->symbol.empty()) return true;
    int i = 0;
    while(i < S->symbol.size() && S->symbol.at(i) != symbol) i++;
    if(i >= S->symbol.size()) return true;
    return false;
}

/* symbolPosition(state *S, char symbol)
*
* Recibe: El puntero del estado (*S) y el símbolo que se quiere buscar.
*
* Entrega: Retorna la posición (i) del símbolo dentro del venctor symbol. En
* caso de que no lo encuentre, retorna un -1.
*
* Explicación: Primero verifica si el vector symbol está vacío y retorna un -1.
* En caso contrario, realiza un contador con la búsqueda de la posición dentro
* del vector. En caso de que no se encuentre retorna un -1, caso contrario
* retorna la posición.
*/

int symbolPosition(state *S, char symbol){
    if (S->symbol.empty()) return -1;
    int i = 0;
    while(i < S->symbol.size() && S->symbol.at(i) != symbol) i++;
    if(i >= S->symbol.size()) return -1;
    return i;
}

/* checkWord(state *S, char *A, int largo)
* 
*/

bool checkWord(state *S, char *A, int largo){
    state *p = S;
    state *q = S;
    int i = 0;
    while(i < largo){
        if(symbolPosition(p, A[i]) != -1){
            string destState = p->nameD[symbolPosition(p, A[i])];
            while(q->name != destState) q = q->next;
            p = q;
            q = S;
        }
        else return false;
        i++;
    }
}

/****************************************************************************
* MÉTODOS DE DESARROLLO. SERÁN BORRADOS UNA VEZ EL PROGRAMA HAYA FINALIZADO *
*****************************************************************************/

void print(state *S){ //Imprime los estados
    while(S->next != nullptr){
        cout << S->name << endl;
        S = S->next;
    }
    cout << S->name << endl;
}

void printAllInformation(state *S){ //Imprime los estados junto a su función de transición
    while(S != nullptr){
        cout << S->name << endl;
        for(int i = 0; i < S->nameD.size(); i++){
            cout << S->symbol[i];
            cout << "->";
            cout << S->nameD[i] << endl;
        }
        S = S->next;
        cout << endl;
    }
}