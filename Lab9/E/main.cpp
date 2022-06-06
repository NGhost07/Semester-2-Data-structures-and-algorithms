#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> order, used;

void DFS(int v){
    used[v] = 1;
    for (auto i: graph[v])
        if (used[i] == 0)
            DFS(i);
    order.push_back(v);
}

bool check(){
    for (int i=(int)order.size()-1; i>0; i--) {
        bool flag = true;
        for (int j=0; j<graph[order[i]].size(); j++)
            if (graph[order[i]][j] == order[i-1])
                flag = false;
        if (flag) {
            return false;
            break;
        }
    }return true;
}

int main(int argc, const char * argv[]) {
    ifstream fin("hamiltonian.in");
    ofstream fout ("hamiltonian.out");
    fin >> n >> m;
    graph.resize(n);
    for (int i=0; i<m; i++) {
        int v1, v2;
        fin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
    }
    used.assign(n, 0);
    for (int i=0; i<n; i++)
        if (used[i] == 0)
            DFS(i);
    bool a = check();
    a == true ? fout << "YES" : fout << "NO";
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab9/lab9E/lab9E/hamiltonian.in
