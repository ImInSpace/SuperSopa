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

void generate_dictionary ()
{
    string file;
    int K, seed;
    cout<<"What file do you want to write to? (without extension) ";
    cin>>file;
    cout<<"How many words do you want? (K) ";
    cin>>K;
    cout<<"What seed do you want? (-1 to time) ";
    cin>>seed;
    if (seed==-1)srand(time(NULL));
    else srand(seed);

    ofstream ofs (file+".dict");
    ofs<<K<<endl;
    int printed=0, total=118615;//precalculado
    for (unsigned int i=0; i<english.size(); i++){
        for(int j=0; j<english[i]*K/total; j++){
            for (unsigned int k=0; k<i; k++){
                ofs<<rand()%10;
            }
            ofs<<endl;
            printed++;
        }
    }
    while (printed<K){
        for (unsigned int k=0; k<8; k++){
            ofs<<rand()%10;
        }
        ofs<<endl;
        printed++;
    }
    ofs.close();
}

vector<string> get_dictionary()
{
    cout << "What dictionary file do you want to open? (without extension) ";
    string file;
    cin>>file;
    ifstream ifs (file+".dict");
    int K;
    ifs>>K;
    vector<string> dictionary (K);
    string aux;
    for (unsigned int i=0; i<dictionary.size(); i++) ifs>>dictionary[i];
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
    cout << "What do you want to do?" << endl;
    cout << "1-generate a dictionary file" << endl;
    cout << "2-call solver" <<endl;
    int initialOption;
    cin>>initialOption;
    if (initialOption==1){
        generate_dictionary();
    }
    else{
        //bool calculate_time=ask_question("Do you want to calculate time?");
        Solver* solver=get_solver();

        vector<string> dictionary=get_dictionary();
        solver->initDictionary(dictionary);

        vector<vector<char>> board=get_board();
        solver->initBoard(board);
        print_board(board);

        solver->solve();
        solver->printSolution();
        /*
        clock_t begin_time;
        vector<vector<char>> board;
        for (int N=3000; N<13000; N+=2000){
                srand(0);
                board = vector<vector<char>> (N, vector<char> (N));
                for (int i=0; i<N; i++){
                    for (int j=0; j<N; j++)board[i][j]='0'+(rand()%10);
                }
                solver->initDictionary(dictionary);
                solver->initBoard(board);
                begin_time = clock();
                solver->solve();
                solver->printSolution();
                cout<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<endl;
                
        }*/
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
    }
    return 0;
}








