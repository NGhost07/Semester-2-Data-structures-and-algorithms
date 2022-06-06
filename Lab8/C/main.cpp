#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    int arr[n][n];
    bool k = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i=0; i<m; i++) {
        int ver1, ver2;
        fin >> ver1 >> ver2;
        if (arr[ver1-1][ver2-1] == 0) {
            arr[ver1-1][ver2-1] = 1;
        }else{
            k = true;
            break;
        }if (arr[ver1-1][ver2-1] == 1 && arr[ver2-1][ver1-1] == 1) {
            k = true;
            break;
        }
    }
    k == true ? fout << "YES\n" : fout << "NO\n";
    return 0;
}
