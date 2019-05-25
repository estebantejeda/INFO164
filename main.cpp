#include <iostream>
#include <cstdlib>
#include "State.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    //Variables
    string name; //Nombre de Estado Inicial
    string e1; //Nombre Inicio de Estado
    string e2; //Nombre Destino de Estado
    char val; //Letra de función de Transición
    state *p = nullptr;

    //Ingreso de estado inicial (PENDIENTE)
    cout << "Ingrese nombre Estado Inicial" << endl;
    cin >> name;
    createInitialState(&p, name);

    //Ingreso de Transiciones (PENDIENTE)
    cout << "Ingrese nombre Inicio de Estado" << endl;
    cin >> e1;
    cout << "Ingrese función de transición" << endl;
    cin >> val;
    cout << "Ingrese nombre Destino de Estado" << endl;
    cin >> e2;

    //Ingreso Estados Finales (PENDIENTE)
    cout << "Ingrese estados finales" << endl;
    cin >> name;

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