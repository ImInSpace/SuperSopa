#ifndef WORDSOLVER_H
#define WORDSOLVER_H

#include "solver.h"

class WordSolver : public Solver
{
public:
    WordSolver();

    WordSolver(vector<string> dictionary, vector<vector<char>> board);

    void initDictionary(vector<string> dictionary);

    void initBoard(vector<vector<char>> board);

    void solve();

    string printSolution();
};

#endif // WORDSOLVER_H
