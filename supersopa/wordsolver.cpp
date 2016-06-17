#include "wordsolver.h"
#include <iostream>


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
    // We look for this letter in the board
    map<char,bool> visited_children;
    for (pair<const char, WordSolver::arbre*> it : arrel.fills){
        visited_children[it.first] = false;
    }
    int num_visited_children(arrel.fills.size());

    // While not all board visited and we haven't visited all children
    while (i_to_check <= n && num_visited_children > 0){
        char c = board[i_to_check][j_to_check];

        // If this cell's character hadn't been found before, we add it
        if (not visited_children[c]){ // NOTA: si no existeix cap paraula q comenci amb un cert caracter aixo peta
            visited_children[c] = true;
            --num_visited_children;
            arrel.fills[c]->appearances = WordAppearances(0);
        }
        arrel.fills[c]->appearances.push_back(Appearance(1, make_pair(i_to_check, j_to_check)));
        ++j_to_check;
        if (j_to_check > n){
            j_to_check = 1;
            ++i_to_check;
        }
    }

    if (i_to_check > n){
        for (pair<const char, bool> it : visited_children){
            if (not it.second){
                arrel.fills[it.first]->in_board = false;
            }
        }
    }

    for (pair<const char, WordSolver::arbre*> it : arrel.fills){
        if (visited_children[it.first]){
            solve_rec(it.second);
        }
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

// Busca si la paraula del node està al board
void WordSolver::solve_rec(WordSolver::arbre* node)
{
    while (node->appearances.size() == 0 && node->in_board){
        // While we haven't found any appearance and we can't discard that it is not in the board
        if (node->parent_appearance_to_check < node->pare->appearances.size()){
            // If we haven't checked all of parents appearances, we look for contiguous positions
            // of parent's appearances' last position
            for (Pos cont : contiguous){
                Pos p = node->pare->appearances[node->parent_appearance_to_check].back();
                p.first += cont.first;
                p.second += cont.second;
                if (board[p.first][p.second] == node->caracter){
                    Appearance a = Appearance(node->pare->appearances[node->parent_appearance_to_check]);
                    a.push_back(p);
                    node->appearances.push_back(a);
                }
            }
            ++(node->parent_appearance_to_check);
        } else {
            // If we have checked all of parent's appearances, we demand parent to look for more
            // appearances. If it doesn't find any more, then this word is not in the board
            node->in_board = get_more_appearances(node->pare);
        }
    }


    for (pair<const char, WordSolver::arbre*> it : node->fills){
        solve_rec(it.second);
    }
}

// Searches more appearances of node. Returns false iff can't find any more appearances
bool WordSolver::get_more_appearances(WordSolver::arbre* node)
{
    if (node->completely_explored) return false;

    if (node->pare == &arrel){
        if (i_to_check > n) return false; // no cal

        // We look for this letter in the board
        while (i_to_check <= n){
            char c = board[i_to_check][j_to_check];
            arrel.fills[c]->appearances.push_back(Appearance(1, make_pair(i_to_check, j_to_check)));
            ++j_to_check;
            if (j_to_check > n){
                j_to_check = 1;
                ++i_to_check;
            }

            if (c == node->caracter) {
                return true;
            }
        }

        for (pair<const char, WordSolver::arbre*> it : arrel.fills){
            it.second->completely_explored = true;
        }
        return false;
    }

    else {
        int initial_appearances = node->appearances.size();
        while (node->appearances.size() == initial_appearances && not node->completely_explored){
            // While we haven't found any appearance and we can't discard that it is not in the board
            if (node->parent_appearance_to_check < node->pare->appearances.size()){
                // If we haven't checked all of parents' appearances, we look for contiguous positions
                // of parent's appearances' last position
                for (Pos cont : contiguous){
                    Pos p = node->pare->appearances[node->parent_appearance_to_check].back();
                    p.first += cont.first;
                    p.second += cont.second;
                    if (board[p.first][p.second] == node->caracter){
                        Appearance a = Appearance(node->pare->appearances[node->parent_appearance_to_check]);
                        a.push_back(p);
                        node->appearances.push_back(a);
                    }
                }
                ++(node->parent_appearance_to_check);
            } else {
                // If we have checked all of parent's appearances, we demand parent to look for more
                // appearances. If it doesn't find any more, then this word has no more appearances in board
                node->completely_explored = get_more_appearances(node->pare);
            }
        }

        return not node->completely_explored;
    }
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

