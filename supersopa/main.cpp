#include <iostream>
#include "wordsolver.cpp"
using namespace std;

int main(int argc, char *argv[])
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


/*
 *
 *

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

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


int main ()
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

    ofstream ofs (file, ofstream::out);
    int total=118615;
    for (uint i=0; i<english.size(); i++){
        for(int j=0; j<english[i]*K/total; j++){
            for (int k=0; k<i; k++){
                ofs<<rand()%10;
            }
            ofs<<endl;
        }
    }
    ofs.close();
    return 0;
}

*/
