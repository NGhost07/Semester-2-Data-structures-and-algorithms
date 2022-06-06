#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long n, res = 0;
vector<long long> arr, b, f, r;
 
int main(int argc, const char * argv[]) {
    cin >> n;
    for (long long i=0; i<n; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    b.assign(n+1, LLONG_MAX);
    b[0] = LLONG_MIN;
    for (long long i=0; i<n; i++) {
        long long k = lower_bound(b.begin(), b.end(), arr[i]) - b.begin();
        b[k] = arr[i];
        res = max(res, k);
        f.push_back(k);
    }
    cout << res << endl;
    while (n--) {
        if (f[n] == res) {
            r.push_back(arr[n]);
            res--;
        }
    }
    for (long long i=r.size()-1; i>=0; i--) {
        cout << r[i] << "   ";
    }
    return 0;
}
