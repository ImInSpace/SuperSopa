#ifndef WORDSOLVER_H
#define WORDSOLVER_H

#include "solver.h"
#include <map>

typedef pair<int,int> Pos;
typedef vector<Pos> Appearance;
typedef vector<Appearance> WordAppearances;

class WordSolverAllAppearances : public Solver
{

public:

    WordSolverAllAppearances();

    WordSolverAllAppearances(vector<string> _dictionary, vector<vector<char>> _board);

    void initDictionary(const vector<string>& _dictionary);

    void initBoard(const vector<vector<char> > &_board);

    void solve();

    void printSolution();


private:

    struct arbre{
        char caracter;
        map <char, arbre*> fills;
        arbre* pare;
        bool in_dictionary = false;
        WordAppearances appearances;
    };

    vector<string> dictionary;
    vector<vector<char>> board;
    int n, k;

    arbre arrel;

    vector<WordAppearances> solution;
    // solution[i] = list of sequences of positions in board to make i-th word of the dictionary

    void solve_rec(arbre* node);
    void print_rec(arbre* node, string word);
    void insereix(string paraula, WordSolverAllAppearances::arbre* node);

};

#endif // WORDSOLVER_H
