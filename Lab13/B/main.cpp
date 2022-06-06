#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> prefix;
vector<int> res;

void getPrefix(string s){
    prefix[0] = 0;
    int j = 0, i = 1;
    while(i < s.length() && j < s.length()){
        if(s[i] == s[j]){
            prefix[i] = j + 1;
            i++;
            j++;
        } else if (j == 0){
            prefix[i] = 0;
            i++;
        } else {
            j = prefix[j - 1];
        }
    }
}

int kmp(string temp, int s1L, int s2L){
    int count = 0;
    getPrefix(temp);
    for (int i = 0; i < s2L; i++){
        if (prefix[s1L + i + 1] == s1L){
            res.push_back(i - s1L + 2);
            count++;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    ifstream fin ("search2.in");
    ofstream fout ("search2.out");
    string p, t, temp;
    fin >> p >> t;
    temp = p + "#" + t;
    int s1L = (int)p.length(), s2L = (int)t.length();
    prefix.resize(temp.length());
    fout << kmp(temp, s1L, s2L) << endl;
    for(auto i : res)
        fout << i << ' ';
    return 0;
}
