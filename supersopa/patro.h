#ifndef PATRO_H
#define PATRO_H

#include "solver.h"
#include <map>
class Patro: public Solver
{
public:
    Patro();

    Patro(vector<string> dictionary, vector<vector<char>> board);

    void initDictionary(vector<string> dictionary);

    void initBoard(vector<vector<char>> board);

    void solve();

    string printSolution();

    struct arbre{
        char caracter;
        map< char, arbre > fills;
        arbre* pare;

    };

private:


    vector< vector < char> > _board;
    arbre arrel;

    void insereix(string paraula, arbre arbre);

};

#endif // PATRO_H
