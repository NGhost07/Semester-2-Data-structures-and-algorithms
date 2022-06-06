#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m, s;
vector<vector<int>> graph;
vector<bool> result;
vector<int> visited;

void DFS_Game(int s){
    visited[s] = 1;
    bool cur_result = false;
    for (auto i : graph[s]) {
        if (visited[i] == 0)
            DFS_Game(i);
        if (!result[i])
            cur_result = true;
    }
    result[s] = cur_result;
}

int main(int argc, const char * argv[]) {
    ifstream fin ("game.in");
    ofstream fout ("game.out");
    fin >> n >> m >> s;
    s--;
    graph.resize(n);
    for (int i=0; i<m; i++) {
        int v1, v2;
        fin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
    }
    visited.assign(n, 0);
    result.assign(n, false);
    DFS_Game(s);
    result[s] == true ? fout << "First player wins" : fout << "Second player wins";
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab9/lab9F/lab9F/game.in
