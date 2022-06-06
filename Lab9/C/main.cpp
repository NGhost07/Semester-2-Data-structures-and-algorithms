#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> edges;
vector<int> visited;
queue<int> q;

bool check(){
    for (int i=0; i<n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int  u = q.front();
                q.pop();
                for (int j=0; j<edges[u].size(); j++) {
                    if (visited[edges[u][j]] == 0) {
                        q.push(edges[u][j]);
                        visited[edges[u][j]] = -visited[u];
                    }
                    else if (visited[u] == visited[edges[u][j]]){
                        return false;
                    }
                }
            }
        }
    }return true;
}

int main(int argc, const char * argv[]) {
    ifstream fin ("bipartite.in");
    ofstream fout ("bipartite.out");
    fin >> n >> m;
    edges.resize(n);
    for (int i=0; i<m; i++) { // push all edges to vector
        int v1, v2;
        fin >> v1 >> v2;
        edges[v1-1].push_back(v2-1);
        edges[v2-1].push_back(v1-1);
    }
    visited.assign(n, 0);// visited has n elements, all elements are 0
    bool a = check();
    a == true ? fout << "YES" : fout << "NO";
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab9/lab9C/lab9C/
