#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>
using namespace std;

class Solver
{
public:
    Solver();

    Solver(vector<string> dictionary, vector<vector<char>> board);

    virtual void initDictionary(vector<string> dictionary)=0;

    virtual void initBoard(vector<vector<char>> board)=0;

    virtual void solve()=0;

    virtual void printSolution()=0;
};

#endif // SOLVER_H
