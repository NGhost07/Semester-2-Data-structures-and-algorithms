#include <iostream>
#include <string>

using namespace std;
    
string lcs(string a, string b){
    if (a.empty() || b.empty()) {
        return {};
    }
    string cur_lcs = "";
    for (int i=0; i<a.length(); i++) {
        size_t fpos = b.find(a[i], 0);
        while (fpos != string::npos) {
            string tmp_lcs = "";
            tmp_lcs += a[i];
            for (int x=(int)fpos+1; x<b.length(); x++) {
                tmp_lcs += b[x];
                size_t spos = a.find(tmp_lcs, 0);
                if (spos == string::npos) {
                    break;
                }
                else{
                    if (tmp_lcs.length() > cur_lcs.length()) {
                        cur_lcs = tmp_lcs;
                    }
                }
            }
            fpos = b.find(a[i], fpos+1);
        }
    }
    return cur_lcs;
}

int main(int argc, const char * argv[]) {
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
    return 0;
}
