#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long n, m, start;
const unsigned long long max_n = 2001;
long long inf = LLONG_MAX / 2;

struct edge {
    long long v1, v2, w;
    edge(long long x, long long y, long long z) {
        v1 = x;
        v2 = y;
        w = z;
    }
};

vector<edge> edges;
vector<vector<long long>> edgesDFS;
vector<long long> d;
vector<long long> proceed;
vector<bool> visited;

void dfs(long long v) {
    visited[v] = true;
    proceed[v] = false;
    for (auto to : edgesDFS[v]) {
        if (!visited[to])
            dfs(to);
    }
}

void Bellman_Ford() {
    d[start] = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (d[edges[j].v1] < inf) {
                if (d[edges[j].v2] > d[edges[j].v1] + edges[j].w) {
                    d[edges[j].v2] = min(inf, d[edges[j].v1] + edges[j].w);
                    if (i == n - 1) {
                        for (long long i = 0; i < n; ++i)
                            visited[i] = false;
                        dfs(edges[j].v2);
                    }
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin ("/Users/tranhoangnam/Desktop/Algorithm/lab11/lab11D/lab11D/path.in");
    ofstream fout ("/Users/tranhoangnam/Desktop/Algorithm/lab11/lab11D/lab11D/path.out");
    fin >> n >> m >> start;
    start--;
    edgesDFS.resize(max_n);
    d.assign(max_n, inf);
    proceed.assign(max_n, true);
    visited.resize(max_n);
    for (long long i = 0; i < m; ++i) {
        long long v1, v2, weight;
        fin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        edges.push_back(edge(v1, v2, weight));
        edgesDFS[v1].push_back(v2);
    }
    Bellman_Ford();
    for (long long i = 0; i < n; ++i) {
        if (d[i] == inf)
            fout << '*' << endl;
        else if (!proceed[i])
            fout << '-' << endl;
        else
            fout << d[i] << endl;
    }
    return 0;
}

//Bellman_Ford
// /Users/tranhoangnam/Desktop/Algorithm/lab11/lab11D/lab11D/path.in
