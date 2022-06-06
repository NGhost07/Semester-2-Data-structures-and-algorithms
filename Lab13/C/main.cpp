#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrefix(string s) {
    vector<int> PFI(s.length(), 0);
    for (int i = 1; i < s.length(); ++i) {
        int j = PFI[i - 1];
        while (j > 0 && s[i] != s[j])
            j = PFI[j - 1];
        if (s[i] == s[j])
            j++;
        PFI[i] = j;
    }
    return PFI;
}

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    string s;
    fin >> s;
    vector<int> prefix = getPrefix(s);
    for (int i: prefix)
        fout << i << " ";
    return 0;
}
