#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin ("search1.in");
    ofstream fout ("search1.out");
    string p, t;
    fin >> p >> t;
    int m, n;
    m = (int)p.length();
    n = (int)t.length();
    vector<int> cmp;
    int count = 0;
    int i = 0, j = 0;
    while(i <= n - m){
        for (j = 0; j < m; j++){
            if (t[i + j] != p[j]){
                break;
            }
        }
        if (j == m){
            cmp.push_back(i);
            count++;
        }
        i++;
    }
    cout << count << endl;
    for (auto i: cmp)
        cout << i + 1 << " ";
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab13/lab13A/lab13A/search1.in
