#include <iostream>
#include <cstdlib>
#include <string>
#include "State.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    //Variables
    string nameI; //Nombre de Estado de Inicio
    string nameD; //Nombre de Estado de Destino
    char symbol; //Símbolo de Transición
    state *p = nullptr; //Estructura

    //Ingreso de estado inicial
    cout << "Ingrese nombre Estado Inicial Q0" << endl;
    cin >> nameI;
    createState(&p, nameI);

    //Ingreso de Transiciones (PENDIENTE)

    for(int i = 0; i < 4; i++){
        cout << "\nIngrese nombre del Estado de Inicio Qn" << endl;
        cin >> nameI;
        if(searchState(p, nameI)) createState(&p, nameI);
        cout << "\nIngrese nombre del Estado de Destino Qm" << endl;
        cin >> nameD;
        if(searchState(p, nameD)) createState(&p, nameD);
    }
    cout << "" <<endl;
    print(p);
    return 0;

    //Ingreso Estados Finales (PENDIENTE)

    //Ingreso de la palabra (PENDIENTE)
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