#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> com_num, visited;
int vStart = -1;
int vEnd;

void DFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        if (visited[graph[v][i]] == 1) {
            vStart = graph[v][i];
            vEnd = v;
        }
        if (visited[graph[v][i]] == 0) {
            com_num[graph[v][i]] = v;
            DFS(graph[v][i]);
        }
    }visited[v] = 2;
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
    fin >> n >> m;
    graph.resize(n); // resize by graph is n
    for (int i = 0; i < m; i++) { // push all vertices into graph
        int a, b;
        fin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    com_num.assign(n, -1); // com_num has n elements, all elements are -1
    visited.assign(n, 0);// visited has n elements, all elements are 0
    for (int i = 0; i < n; i++)
        if (visited[i] == 0)
            DFS(i);
    if (vStart == -1)
        fout << "NO" << endl;
    else {
        fout << "YES" << endl;
        vector<int> result;
        result.push_back(vStart + 1);
        for (int i = vEnd; i != vStart; i = com_num[i]) {
            result.push_back(i + 1);
        }
        for (int i = (int)result.size() - 1; i >= 0; i--) {
            fout << result[i] << " ";
        }
    }
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab9/lab9B/lab9B/
