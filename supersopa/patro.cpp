#include "patro.h"
<<<<<<< HEAD
#include <iostream>
=======
#include <algorithm>
>>>>>>> 3ae638b6a6399443661e5efd13efbc1524021e43

/*
Patro::Patro()
{
}

Patro::Patro(vector<string> dictionary, vector<vector<char> > board)
{

}*/

void Patro::initDictionary(vector<string> dictionary)
{
    sort(dictionary.begin(),dictionary.end());
    this->arrel.caracter = '-';
    for(string paraula : dictionary){
        insereix(paraula,this->arrel);

    }
}

void Patro::initBoard(vector<vector<char> > board)
{

}

void Patro::solve()
{

}

void Patro::printSolution()
{
    cout<<"hola"<<endl;
}

void Patro::insereix(string paraula, Patro::arbre arbre)
{

}
