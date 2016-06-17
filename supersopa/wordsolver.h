#ifndef WORDSOLVER_H
#define WORDSOLVER_H

#include "solver.h"
#include <map>

typedef pair<int,int> Pos;
typedef vector<Pos> Appearance;
typedef vector<Appearance> WordAppearances;

class WordSolver : public Solver
{

public:

    WordSolver();

    WordSolver(vector<string> _dictionary, vector<vector<char>> _board);

    void initDictionary(const vector<string>& _dictionary);

    void initBoard(const vector<vector<char> > &_board);

    void solve();

    void printSolution();


private:

    struct arbre{
        char caracter;
        int parent_appearance_to_check = 0; // number of parent appearances checked
        map <char, arbre*> fills;
        arbre* pare;
        bool in_dictionary = false;
        bool in_board = true;
        bool completely_explored = false;
        WordAppearances appearances;
    };

    vector<string> dictionary;
    vector<vector<char>> board;
    int n, k;

    int num_sols;

    arbre arrel;
    int i_to_check = 1;
    int j_to_check = 1;

    vector<WordAppearances> solution;
    // solution[i] = list of sequences of positions in board to make i-th word of the dictionary

    int count_sol(WordSolver::arbre* node);
    void solve_rec(arbre* node);
    void print_rec(arbre* node, string word);
    bool get_more_appearances(WordSolver::arbre* node);
    void insereix(string paraula, WordSolver::arbre* node);

    Pos contiguous[8] =
        {
            make_pair(-1,-1), make_pair(-1, 0), make_pair(-1, 1),
            make_pair( 0,-1),                   make_pair( 0, 1),
            make_pair( 1,-1), make_pair( 1, 0), make_pair( 1, 1),
        };

};

#endif // WORDSOLVER_H
