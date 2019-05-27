#include <iostream>
#include <cstdlib>
#include "State.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    //Variables
    string name; //Nombre de Estado
    char val; //Letra de Transición
    state *p = nullptr; //Estructura

    //Ingreso de estado inicial
    cout << "Ingrese nombre Estado Inicial Q0" << endl;
    cin >> name;
    createState(&p, name);

    //Ingreso de Transiciones (PENDIENTE)
    bool repeat = true;
    while (repeat){
        cout << "Ingrese nombre Estado Qn" << endl;
        cin >> name;
        cout << "Ingrese nombre Estado Qm" << endl;
        cin >> name;
        cout << "Ingrese letra para función de Transición" << endl;
        cin >> val;
        cout << "Ingresar otro? [s/n]" << endl;
        char c;
        cin >> c;
        if(c == 'n') repeat = false;
    }

    //Ingreso Estados Finales (PENDIENTE)

    //Ingreso de la palabra
    string wordString = inputWord();
    char *Word = new char[wordString.length()-1];
    stringToArray(Word, wordString);

}

string inputWord(){
    string word;
    cout << "Ingrese la palabra" << endl;
    cin >> word;
    return word;
}

void stringToArray(char *A, string word){
    for (int i = 0; i < word.length(); i++){
        A[i] = word[i];
    }
}