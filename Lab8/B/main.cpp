#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int arr[n][n];
    bool a = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            fin >> arr[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((arr[i][j] == 1 && arr[j][i] == 0) ||
                (arr[i][j] == 1 && arr[j][i] == 1 && i==j)) {
                a = false;
                break;
            }
        }
    }
    a == true ? fout << "YES\n" : fout << "NO\n";
    return 0;
}
