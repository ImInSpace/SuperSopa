#include "patro.h"
#include <algorithm>

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

string Patro::printSolution()
{
    return "hola";
}

void Patro::insereix(string paraula, Patro::arbre arbre)
{

}
