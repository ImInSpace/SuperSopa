#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
#include <solver.h>
#include <patro.h>
#include <wordsolver.h>

using namespace std;

/*
int main()
{
    cout << "Hello World!" << endl;

    vector<string> d (2);
    d[0] = "papa"; d[1] = "mama";
    vector<vector<char>> b(2, vector<char> (2));
    b[0][0] = 'p'; b[0][1] = 'm';
    b[1][0] = 'o'; b[1][1] = 'a';
    WordSolver ws(d, b);
    ws.solve();
    ws.printSolution();

}
*/




vector<int> english = {0, //distribución de las palabras segun su tamaño en ingles
                       0,
                       93,
                       754,
                       3027,
                       6110,
                       10083,
                       14424,
                       16624,
                       16551,
                       14888,
                       12008,
                       8873,
                       6113,
                       3820,
                       2323,
                       1235,
                       707,
                       413,
                       245,
                       135,
                       84,
                       50,
                       23,
                       16,
                       9,
                       4,
                       2,
                       1,
                       0,
                       0};

void generate_dictionary (int K)
{
    /*string file;
    int seed;
    cout<<"What file do you want to write to? (without extension) ";
    cin>>file;
    cout<<"How many words do you want? (K) ";
    cin>>K;
    cout<<"What seed do you want? (-1 to time) ";
    cin>>seed;
    if (seed==-1)srand(time(NULL));
    else srand(seed);*/

}

vector<string> get_dictionary(int K)
{
    vector<string> dictionary (K);
    int printed=0, total=118615;//precalculado
    for (unsigned int i=0; i<english.size(); i++){
        for(int j=0; j<english[i]*K/total; j++){
            string aux = "";
            for (unsigned int k=0; k<i; k++){
                aux.push_back('0'+rand()%10);
            }
            dictionary[printed]=aux;
            printed++;
        }
    }
    while (printed<K){
        string aux = "";
        for (unsigned int k=0; k<8; k++){
            aux.push_back('0'+rand()%10);
        }
        dictionary[printed]=aux;
        printed++;
    }
    return dictionary;
}

Solver* get_solver()
{
    cout << "What solver do you want to use?" << endl;
    cout << "1-Pattern search" << endl;
    cout << "2-Word search" <<endl;
    Solver* solver;
    int solverOption;
    cin>>solverOption;
    if (solverOption==1){
        solver=new Patro();
    }
    else solver=new WordSolver();
    return solver;
}

vector<vector<char>> get_board(){
    int N, seed;
    cout<<"What size do you want the next board to be? (N) ";
    cin>>N;
    cout<<"What seed do you want? (-1 to time) ";
    cin>>seed;
    if (seed==-1)srand(time(NULL));
    else srand(seed);
    vector<vector<char>> board (N, vector<char> (N));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)board[i][j]='0'+(rand()%10);
    }
    return board;
}

bool ask_question(string question){
    string answer;
    cout<<question<<' ';
    cin>>answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer=="yes" or answer=="y";
}

void print_board(vector<vector<char>> board){
    cout<<"Board: "<<endl;
    for (vector<char> line : board){
        for (char c : line)cout<<c;
        cout<<endl;
    }
}

int main()
{
        //bool calculate_time=ask_question("Do you want to calculate time?");
        Solver* solver=get_solver();
        vector<string> dictionary;
        //vector<vector<char>> board=get_board();
        //solver->initBoard(board);
        //print_board(board);
        
        clock_t begin_time;
        srand(0);
        vector<vector<char>> board;
        for (int N=3000; N<13000; N+=2000){

                board = vector<vector<char>> (N, vector<char> (N));
                for (int i=0; i<N; i++){
                    for (int j=0; j<N; j++)board[i][j]='0'+(rand()%10);
                }

                for (int K=3000; K<13000; K+=2000){
                    dictionary=get_dictionary(K);
                    solver->initDictionary(dictionary);
                    solver->initBoard(board);
                    begin_time = clock();
                    solver->solve();
                    cout<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<" ";
                }
                cout<<endl;
        }
        /*
        if (calculate_time)begin_time = clock();
        solver->solve();
        if (calculate_time)cout << "Time spent solving: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC;
        solver->printSolution();

        while (ask_question("Do you want to solve another board?")){
            board=get_board();
            solver->initBoard(board);
            print_board(board);
            if (calculate_time)begin_time = clock();
            solver->solve();
            if (calculate_time)cout << "Time spent solving: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC;
            solver->printSolution();
        }*/

    return 0;
}


2.956 3.587 4.441 5.408 5.726
5.563 6.227 8.184 8.351 9.76
9.654 10.438 11.702 12.56 12.811
14.415 15.672 16.118 17.62 18.444
20.517 21.269 22.527 23.086 24.226





