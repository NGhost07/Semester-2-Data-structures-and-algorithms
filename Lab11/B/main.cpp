#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> grap;

int main(int argc, const char * argv[]) {
    ifstream fin("pathsg.in");
    ofstream fout ("pathsg.out");
    fin >> n >> m;
    grap.assign(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        fin >> v1 >> v2 >> w;
        grap[v1-1][v2-1] = w;
    }
    for (int k = 0; k < n; k++) { // алгоритм Флойда-Уоршелла
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i ==j) {
                    grap[i][j] = 0;// главная диагональ матрицы
                    continue;
                }
                if (grap[i][k] < INT_MAX && grap[k][j] < INT_MAX)
                    grap[i][j] = min(grap[i][j], grap[i][k] + grap[k][j]);
            }
        }
    }
    for (auto i : grap) {
        for (auto j : i) 
            fout << j << "  ";
        fout << endl;
    }
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab11/lab11B/lab11B/pathsg.in
