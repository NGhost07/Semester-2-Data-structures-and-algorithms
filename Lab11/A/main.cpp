#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const long long inf = pow(10, 12);
long long n;
vector<vector<long long>> grap;
vector<long long> d; // distance
vector<bool> visited; // mark

void dijkstra(long long vertex_start){
    d[vertex_start] = 0;
    for (auto i=0; i<n; i++) {
        long long ver = -1;
        for (auto j=0; j<n; j++)
            if (!visited[j] && (ver == -1 || d[j] < d[ver]))
                ver = j;
        if (d[ver] == inf)
            break;
        visited[ver] = true;
        for (auto j=0; j<n; j++){
            d[j] = min(d[j], d[ver]+grap[ver][j]);
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin("pathmgep.in");
    ofstream fout ("pathmgep.out");
    long long vStart, vFinal;
    fin >> n >> vStart >> vFinal;
    grap.assign(n, vector<long long>(n));
    d.assign(n, inf);
    visited.assign(n, false);
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            int ver;
            fin >> ver;
            if (ver < 0)
                grap[i][j] = inf;
            else
                grap[i][j] = ver;
        }
    }
    dijkstra(vStart-1);
    (d[vFinal - 1] < inf) ? fout << d[vFinal-1] : fout << -1;
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab11/lab11A/lab11A/pathmgep.in
