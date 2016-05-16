#include <iostream>
#include <fstream>
#include <vector>
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




vector<int> english = {0,
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


void generate ()
{

    string file;
    int K, seed;
    cout<<"What file do you want to write to? ";
    cin>>file;
    cout<<"How many words do you want? ";
    cin>>K;
    cout<<"What seed do you want? (-1 to time) ";
    cin>>seed;
    if (seed==-1)srand(time(NULL));
    else srand(seed);

    ofstream ofs (file+".dict", ofstream::out);
    int total=118615;
    for (unsigned int i=0; i<english.size(); i++){
        for(int j=0; j<english[i]*K/total; j++){
            for (unsigned int k=0; k<i; k++){
                ofs<<rand()%10;
            }
            ofs<<endl;
        }
    }
    ofs.close();
}
int main()
{
    cout << "What do you want to do?" << endl;
    cout << "1-generate a dictionary file" << endl;
    cout << "2-call solver" <<endl;
    int initialOption;
    cin>>initialOption;
    if (initialOption==1){
        generate();
    }
    else{
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
        solver->solve();
    }
    return 0;
}








