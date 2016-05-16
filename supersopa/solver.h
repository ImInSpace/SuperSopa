#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>
using namespace std;

class Solver
{
public:
    Solver();

    //Solver(vector<string> dictionary, vector<vector<char>> board);

    virtual void initDictionary(vector<string> dictionary);

    virtual void initBoard(vector<vector<char>> board);

    virtual void solve();

    virtual string printSolution();
};

#endif // SOLVER_H
