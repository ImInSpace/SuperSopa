#ifndef PATRO_H
#define PATRO_H

#include "solver.h"
#include <map>
class Patro: public Solver
{
public:
    Patro();

    Patro(vector<string> dictionary, vector<vector<char>> board);

    void initDictionary(const vector<string>& dictionary);

    void initBoard(const vector<vector<char>>& board);

    void solve();

    void printSolution();

    struct arbre{
        char caracter;
        map< char, arbre* > fills;
        arbre* pare;
        bool acaba = false;
        int utilitzen = 0;

    };

private:


    vector< vector < char> > _board;
    vector< string > _solucio;
    arbre arrel;


    void cercapatro(int i, int j, arbre* node);
    void insereix(string paraula, arbre* arbre);
    void guardaidestrueix(string paraula, arbre* arbre);

};

#endif // PATRO_H
