#include "wordsolver.h"
#include <iostream>

/*int contiguous[8][2] =
    {{-1,-1}, {-1, 0}, {-1, 1},
     { 0,-1},          { 0, 1},
     { 1,-1}, { 1, 0}, { 1, 1}};
*/
int contiguous_x[8] =
    {-1, -1, -1,
      0,      0,
      1,  1,  1};

int contiguous_y[8] =
    {-1,  0,  1,
     -1,      1,
     -1,  0,  1};

Pos contiguous[8] =
    {
        make_pair(-1,-1), make_pair(-1, 0), make_pair(-1, 1),
        make_pair( 0,-1),                   make_pair( 0, 1),
        make_pair( 1,-1), make_pair( 1, 0), make_pair( 1, 1),
    };

WordSolver::WordSolver()
{

}

WordSolver::WordSolver(vector<string> _dictionary, vector<vector<char>> _board)
{
    initBoard(_board);
    initDictionary(_dictionary);
}

void WordSolver::initDictionary(const vector<string> &_dictionary)
{
    dictionary = _dictionary;
    k = dictionary.size();

    arrel.caracter = '+';
    arrel.fills.clear();
    for(string paraula : dictionary){
        insereix(paraula, &arrel);
    }
    solution = vector<WordAppearances> (0);
}

void WordSolver::initBoard(const vector<vector<char>>& _board)
{
    n = _board.size();
    board =  vector<vector<char>>( n+2 , vector<char> ( n+2 , '-') );
    for(int i = 1; i<=n;++i){
        for(int j= 1; j<=n; ++j ){
            board[i][j]= _board[i-1][j-1];
        }
    }
}

void WordSolver::solve()
{
    for(pair<const char, WordSolver::arbre*> it : arrel.fills){
        it.second->appearances = WordAppearances(0);
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (board[i][j] == it.first){
                    it.second->appearances.push_back(Appearance(1, make_pair(i,j)));
                }
            }
        }

        solve_rec(it.second);
    }
}
/*
struct arbre{
    char caracter;
    map <char, arbre*> fills;
    arbre* pare;
    bool in_dictionary = false;
    WordAppearances appearances;
};
*/

// Es crida O(k * llargada-mitja-paraules) vegades
// Cost funció: O(num-appearances * num-fillls * nuc-caselles-contigues) = O(num-appearances * 10 * 8)
//            = O(num-appearances)
void WordSolver::solve_rec(WordSolver::arbre* node)
{
    for (Appearance a : node->appearances){
        for (pair<const char, WordSolver::arbre*> it : node->fills){
            for (Pos cont : contiguous){
                Pos p = make_pair(a.back().first + cont.first, a.back().second + cont.second);
                if (board[p.first][p.second] == it.first){
                    Appearance a2 = Appearance(a);
                    a2.push_back(p);
                    it.second->appearances.push_back(a2);
                }
            }
        }
    }

    //if (not node->in_dictionary)
        //node->appearances
        // eliminar appearances

    for (pair<const char, WordSolver::arbre*> it : node->fills){
        solve_rec(it.second);
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

void WordSolver::printSolution()
{
    cout << "Solutions:" << endl;
    for (pair<const char, WordSolver::arbre*> it : arrel.fills){
        print_rec(it.second, "" + it.first);
    }
}

void WordSolver::print_rec(WordSolver::arbre* node, string word)
{
    if (node->in_dictionary){
        cout << "WORD: " << word << endl;
        for (Appearance a : node->appearances){
            cout << " ";
            for (Pos p : a){
                cout << " (" << p.first << "," << p.second << ")";
            }
            cout << endl;
        }
    }

    for (pair<const char, WordSolver::arbre*> it : node->fills){
        print_rec(it.second, word + it.first);
    }
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

void WordSolver::insereix(string paraula, WordSolver::arbre* node)
{
    if (paraula.size() > 0) {
        char inici = paraula.front();
        paraula.erase(0,1);
        auto it = node->fills.find(inici);
        if ( it == node->fills.end() ){
            //el node no esta creat
            arbre* nou = new arbre();
            nou->caracter = inici;
            nou->pare = node;
        //  nou->appearances = WordAppearances(0);
            node->fills[inici] = nou;
            it = node->fills.find(inici);
        }
        arbre* fill = it->second;
        insereix(paraula,fill);
    } else node->in_dictionary = true;
}
