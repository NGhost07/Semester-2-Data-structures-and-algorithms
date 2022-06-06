#include <iostream>
#include <fstream>
#include <vector>
const int size = 250000;

using namespace std;

vector<int> gra[size];
int n, m;
int com_num[size], usd[size];

void DFS(int t){
    usd[t] = true;
    for (int i=0; i<gra[t].size(); i++) {
        int nxt = gra[t][i];
        if (!usd[nxt]) {
            com_num[nxt] = com_num[t];
            DFS(nxt);
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin("/Users/tranhoangnam/Desktop/Algorithm/lab8/labD/labD/components.in");
    ofstream fout("/Users/tranhoangnam/Desktop/Algorithm/lab8/labD/labD/components.out");
    fin >> n >> m;
    int first, last;
    for (int i=0; i<m; i++) {
        fin >> first >> last;
        first = first - 1;
        last = last - 1;
        gra[first].push_back(last);
        gra[last].push_back(first);
    }
    int k=0;
    for (int i=0; i<n; i++) {
        if (!usd[i]) {
            k++;
            com_num[i] = k;
            DFS(i);
        }
    }
    fout << k << endl;
    for (int i=0; i<n; i++) 
        fout << com_num[i] << ' ';
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab8/labD/labD/
