#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    int arr[n][n];
    int row, col;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j]=0;
        }
    }
    for (int i=0; i<m; i++) {
        fin >> row >> col;
        arr[row-1][col-1]=1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            fout << arr[i][j] << "  ";
        }
        fout << endl;
    }
    return 0;
}
