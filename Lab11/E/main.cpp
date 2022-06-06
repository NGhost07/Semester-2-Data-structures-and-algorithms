#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct edge{
    int v1, v2, w;
};

const int inf = pow(10, 9);
int n;
vector<edge> g;
vector<int> d;
vector<int> path;
vector<int> parent;

int main(int argc, const char * argv[]) {
    ifstream fin("/Users/tranhoangnam/Desktop/Algorithm/lab11/lab11E/lab11E/negcycle.in");
    ofstream fout ("/Users/tranhoangnam/Desktop/Algorithm/lab11/lab11E/lab11E/negcycle.out");
    fin >> n;
    d.assign(n, inf);
    parent.assign(n, -1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x;
            fin >> x;
            g.push_back(edge{i,j,x});
        }
    }
    int cycle_start = 0;
    d[0] = 0;
    for (int i=0; i<n; i++) {// //Bellman_Ford
        cycle_start = -1;
        for (int j=0; j<g.size(); j++) {
            int start = g[j].v1;
            int end = g[j].v2;
            int w = g[j].w;
            if (d[end] > d[start] + w) {
                d[end] = max(d[start] + w, -inf);
                parent[end] = start;
                cycle_start = end;
            }
        }
    }
    if (cycle_start == -1) {
        fout << "NO" << endl;
    }else{
        int cycle_end = cycle_start;
        for (int i=0; i<n; i++)
            cycle_end = parent[cycle_end];
        for (int j = cycle_end;; j=parent[j]) {
            path.push_back(j);
            if (j == cycle_end && path.size()>1)
                break;
        }
        reverse(path.begin(), path.end());
        fout << "YES" << endl;
        fout << path.size() << endl;
        for (auto i : path) {
            fout << i+1 << "    ";
        }
        fout << endl;
    }
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab11/lab11E/lab11E/negcycle.in
