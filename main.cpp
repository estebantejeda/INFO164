#include <iostream>
#include <cstdlib>
#include "State.hpp"
#include "Function.hpp"

using namespace std;

string inputWord();
void stringToArray(char *A, string word);

int main(){

    //Ingreso de estado inicial (PENDIENTE)
     state *p = nullptr;

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