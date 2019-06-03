#include <iostream>
#include <cstdlib>
#include <string>
#include "State.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    /* VARIABLES INICIALES
    * Se crean las variables previas para la creación de los estados. 
    * La descripción de cada variables será anexada a la derecha ellos.
    */

    string nameI; //Nombre de Estado de Inicio
    string nameD; //Nombre de Estado de Destino
    char symbol; //Símbolo de Transición
    state *p = nullptr; //Estructura de datos que almacena los estados
    bool bucle = true; //VARIABLE TEMPORAL
    char letter; // VARIABLE TEMPORAL

    /* INGRESO DE ESTADO INICIAL Q0
    * Se pide al usuario el ingreso del nombre del estado inicial, el cuál será
    * el inicio de la estructura de datos.
    */

    cout << "Ingrese nombre Estado Inicial Q0" << endl;
    cout << "> ";
    cin >> nameI;
    createState(&p, nameI);

    /* INGRESO DE TRANSICIONES
    * Se pide al usuario el ingreso de los estados Qn, Qm y el símbolo para
    * la Función de Transición.
    * Cada vez que el usuario ingresa un nombre para el estado Qn/Qm, este hace
    * una comprobación por medio de searchState(state *S, string name) para
    * ver si el estado existe. En caso de que el estado no exista, este lo
    * creará, en caso contrario pasará al siguiente paso hasta llegar a
    * addFunction(state **S, string nameI, string nameD, char symbol), el 
    * cual agrega el símbolo y estado de destino dentro del estado de Inicio.
    */

    while(bucle){
        cout << "Ingrese nombre del Estado de Inicio Qn" << endl;
        cout << "> ";
        cin >> nameI;
        if(searchState(p, nameI)) createState(&p, nameI);
        cout << "Ingrese nombre del Estado de Destino Qm" << endl;
        cout << "> ";
        cin >> nameD;
        if(searchState(p, nameD)) createState(&p, nameD);
        cout << "Ingrese el símbolo para la función de Transición" << endl;
        cout << "> ";
        cin >> symbol;
        if(searchSymbol(p, nameI, symbol)) addFunction(&p, nameI, nameD, symbol);
        cout << "\nFinalizar? [s/n] ";
        cin >> letter;
        if(letter == 's') bucle = false;
        cout << endl;
    } printAllInformation(p); //Imprime los estados y sus funciones de transición
    bucle = true;

    /* INGRESO DE ESTADOS FINALES
    * Se pide al usuario el ingreso de los estados que serán estados finales, una vez
    * que sea ingresado, se llamará a la función changeFinalState(state *S, string name)
    * la cual busca el estado con el nombre ingresado y cambia su variable booleana "fin"
    * a "true".
    */

    while(bucle){
        cout << "\nIngrese el nombre del estado que quiera hacer final" << endl;
        cout << "> ";
        cin >> nameI;
        if (searchState(p, nameI)) cout << "No existe el Estado" << endl;
        else changeFinalState(p, nameI);
        cout << "Finalizar? [s/n] ";
        cin >> letter;
        if(letter == 's') bucle = false;
        cout << endl;
    }
    

    /* INGRESO DE LA PALABRA
    * Se pide al usuario el ingreso de una palabra. Una vez sea almacenado, se creará un arreglo
    * con el largo de la palabra ingresada y finalmente será almacenado cada caracter de la palabra
    * dentro de una posición del arreglo por medio del método stringToArray(char *A, string word).
    */

    string wordString = inputWord();
    char *Word = new char[wordString.length()-1];
    stringToArray(Word, wordString);

    //Inicio de Autómata

    if (checkWord(p, Word, wordString.length())) cout << "Aceptada"; else cout << "Rechazada";

}

/* string inputWord()
* 
* Recibe: No tiene parámetros de entrada.
*
* Entrega: Un string ingresado por el usuario.
*
* Explicación: Este método le pide al usuario el ingreso de una palabra y lo almacena dentro de 
* la variable "word". Una vez almacenado lo retorna.
*/

string inputWord(){
    string word;
    cout << "Ingrese la palabra" << endl;
    cin >> word;
    return word;
}

/* void stringToArray(char *A, string word)
*
* Recibe: Un arreglo de char (*A) y la palabra de entrada como string (word).
*
* Entrega: Al ser un método void no retorna nada, pero lo que realiza es
* tomar la palabra ingresada (word) y transformarla cada caracter a una 
* posición i del arreglo *A
*
* Explicación: Se recorre cada componente de la palabra y se va agregando cada
* caracter al arreglo de char (*A).
*/

void stringToArray(char *A, string word){
    for (int i = 0; i < word.length(); i++){
        A[i] = word[i];
    }
}