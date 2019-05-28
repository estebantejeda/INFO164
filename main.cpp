#include <iostream>
#include <cstdlib>
#include "State.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    //Variables
    string nameI; //Nombre de Estado de Inicio
    string nameD; //Nombre de Estado de Destino
    char val; //Letra de Transición
    state *p = nullptr; //Estructura

    //Ingreso de estado inicial
    cout << "Ingrese nombre Estado Inicial Q0" << endl;
    cin >> nameI;
    createState(&p, nameI);

    //Ingreso de Transiciones (PENDIENTE)
    bool repeat = true;
    /*while (repeat){
        cout << "Ingrese nombre Estado Qn" << endl;
        cin >> nameI;
        searchState(p, name);
        cout << "Ingrese nombre Estado Qm" << endl;
        cin >> nameD;
        cout << "Ingrese letra para función de Transición" << endl;
        cin >> val;
        cout << "Ingresar otro? [s/n]" << endl;
        char c;
        cin >> c;
        if(c == 'n') repeat = false;
    }*/
    for (int i = 0; i < 2; i++){
        cout << "Ingrese nombre Estado Qn" << endl;
        cin >> nameI;
        createState(&p, nameI);
    }
    for (int i = 0; i < 5; i++){
        cout << "Buscar Qn" << endl;
        cin >> nameI;
        if(searchState(p, nameI)) cout << "Existe\n" << endl; else cout << "No existe\n" << endl;
    }
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