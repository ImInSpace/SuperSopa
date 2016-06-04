#ifndef WORDSOLVER_H
#define WORDSOLVER_H

#include "solver.h"

class WordSolver : public Solver
{
private:
    vector<string> dictionary;
    vector<vector<char>> board;
    int n, k;

    vector<vector<vector<pair<int,int>>>> ap; // apperanances: ap[i] ap. of word i = list of sequences of positions in board to make word i

    int getContiguous(int i, int j, vector<pair<int,int>> &v);

public:
    WordSolver();

    WordSolver(vector<string> _dictionary, vector<vector<char>> _board);

    void initDictionary(vector<string> _dictionary);

    void initBoard(vector<vector<char>> _board);

    void solve();

    void printSolution();
};

#endif // WORDSOLVER_H
