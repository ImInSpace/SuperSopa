#include "patro.h"
#include <iostream>
#include <algorithm>

int costat[8][2]={{0,1}, {0,-1},
                  {1,0},{-1,0},
                 {1,-1},{-1,1},{-1,-1},{1,1}};

Patro::Patro()
{
}

Patro::Patro(vector<string> dictionary, vector<vector<char> > board)
{
    this->_board =  vector<vector<char>>( board.size()+2 , vector<char> ( board.size()+2 , '-') );
    for(int i =0; i<board.size();++i){
        for(int j=0; j<board.size(); ++j ){
            _board[i+1][j+1]= board[i][j];
        }
    }
    initDictionary(dictionary);

}


//Crear l'arble a partir de l'arrel,te cost O(#lletres) que es O(K)
void Patro::initDictionary(const vector<string> &dictionary)
{
    //indirectament al crear l'arbre ja ho estarem ordenant en temps O(#lletres)
    this->arrel.caracter = '+';
    arrel.acaba= false;
    arrel.fills.clear();
    for(string paraula : dictionary){
        insereix(paraula,&this->arrel);
    }
    this->_solucio = vector< string >(0);
}

//Envoltem el board amb el signe O(N^2)
void Patro::initBoard(const vector<vector<char> > &board)
{
    this->_board =  vector<vector<char>>( board.size()+2 , vector<char> ( board.size()+2 , '-') );
    for(int i =0; i<board.size();++i){
     for(int j=0; j<board.size(); ++j ){
             _board[i+1][j+1]= board[i][j];
         }
     }
     this->_solucio = vector< string >(0);
}

//cost = NxNx cost(cercapatro)
void Patro::solve()
{
    for(int i =0; i<_board.size()-2;++i){
        for(int j=0; j<_board.size()-2; ++j ){
            cercapatro(i+1,j+1,arrel.fills[_board[i+1][j+1]]);
        }
    }
}


//Funcio recursiva per a fer el dfs, cost es O del nombre de nodes que explorem,
// que en cas pitjor es O(8^profunditat dels fills).
//La profunditat dels fills depen de K lleugerament com es pot veure a la taula del main
//Pero es pot considerar una constant per K grans
void Patro::cercapatro(int i, int j, Patro::arbre* node){
    if (node != NULL){
        if(node->acaba)guardaidestrueix("",node);
        for(int k=0; k<8; ++k){
            cercapatro( i+costat[k][0] , j+costat[k][1] ,node->fills[ _board[i+costat[k][0]][j+costat[k][1]] ]);
        }
    }
}

//Treu un mot del diccionari i el guarda a la solució O (profunditat dels fills)
void Patro::guardaidestrueix(string paraula, Patro::arbre* node){
    (node->utilitzen)--;
    vector<char> borrar = vector<char> (0);
    for(pair<const char, Patro::arbre*> fill : node->fills){
        if(fill.second == NULL or fill.second->utilitzen == 0) borrar.push_back(fill.first);
    }
    for(char b : borrar) node->fills.erase(node->fills.find(b));
    if (node->caracter == '+'){
        this->_solucio.push_back(paraula);
    } else {
        guardaidestrueix(node->caracter+paraula, node->pare);
    }

}

void Patro::printSolution()
{
    for(string sol : this->_solucio){
        cout << sol << endl;
    }
}

void Patro::insereix(string paraula, Patro::arbre* node)
{
    (node->utilitzen)++;
    if (paraula.size() > 0) {
        char inici = paraula.front();
        paraula.erase(0,1);
        auto it = node->fills.find(inici);
        if ( it == node->fills.end() ){
           //el node no esta creat
           arbre* nou = new arbre();
           nou->caracter = inici;
           nou->pare = node;
           nou->acaba = false;
           nou->utilitzen = 0;
           node->fills[inici] = nou;
           it = node->fills.find(inici);
        }
        arbre* fill = it->second;
        insereix(paraula,fill);
    } else node->acaba = true;
}
