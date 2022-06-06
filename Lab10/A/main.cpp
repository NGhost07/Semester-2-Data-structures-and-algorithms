#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n, m;
    fin >> n >> m;
    vector<int> count;
    count.assign(n, 0);
    for (int i=0; i<m; i++) {
        int v1, v2;
        fin >> v1 >> v2;
        count[v1-1]++;
        count[v2-1]++;
    }
    for (auto i: count) {
        fout << i << "  ";
    }
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab10/lab10A/lab10A/input.txt
