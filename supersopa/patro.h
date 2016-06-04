#ifndef PATRO_H
#define PATRO_H

#include "solver.h"

class Patro: public Solver
{
public:
    Patro();

    Patro(vector<string> dictionary, vector<vector<char>> board);

    void initDictionary(vector<string> dictionary);

    void initBoard(vector<vector<char>> board);

    void solve();

    void printSolution();
};

#endif // PATRO_H
