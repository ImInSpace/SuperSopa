#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>

class Solver
{
public:
    Solver();

    virtual Solver(vector<string> dictionary, vector<vector<char>> board);

    virtual void initDictionary(vector<string> dictionary);

    virtual void initBoard(vector<vector<char>> board);

    virtual void solve();

    string printSolution();
};

#endif // SOLVER_H
