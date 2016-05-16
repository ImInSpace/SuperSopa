#include "wordsolver.h"

WordSolver::WordSolver()
{

}

WordSolver::WordSolver(vector<string> _dictionary, vector<vector<char>> _board)
{
    dictionary = _dictionary;
    board = _board;
    n = board.size();
    k = dictionary.size();
}

void WordSolver::initDictionary(vector<string> _dictionary)
{
    dictionary = _dictionary;
    k = dictionary.size();
}

void WordSolver::initBoard(vector<vector<char>> _board)
{
    board = _board;
    n = board.size();
}

void WordSolver::solve()
{
    for (int l=0; l<k; ++l){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                vector<pair<int,int>> seq;
                //bool
            }
        }
    }
}

/* Pre
 * i,j posicio del board
 * w paraula del dictionary
 * l <= w.length()
 *
 * Post
 * v conte les sequencies de posicions que cal visitar per construir el submot de w w[l]..w[w.length()]
 */
bool findword(string w, int l, int i, int j, vector<vector<pair<int,int>>> &v)
{

}

string WordSolver::printSolution()
{

}

int WordSolver::getContiguous(int i, int j, vector<pair<int,int>> &v)
{
    int c=0;
    for (int x = max(0,i-1); x < min(n, i+2); ++x){
        for (int y = max(0, j-1); y < min(n, j+2); ++y){
            if (x != i or y != j){
                v.push_back(make_pair(x,y));
                ++c;
            }
        }
    }
    return c;
}

/* MAIN FOR DEBUGGING
 *
 * cout << "Hello World!" << endl;

    vector<string> d (2);
    d[0] = "papa"; d[1] = "mama";
    vector<vector<char>> b(2, vector<char> (2));
    b[0][0] = 'p'; b[0][1] = 'm';
    b[1][0] = 'o'; b[1][1] = 'a';
    WordSolver ws(d, b);
    ws.solve();
    ws.printSolution();
*/
