#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m, cnt = 0; // cnt: number of strongly connected components
vector<vector<int>> edges1, edges2;
vector<int> order, comp, visited, result;

void DFS(int v, int x){
    visited[v] = 1;
    if (x == 1) {
        for (auto i: edges1[v]) { // assign i equal to the values of the elements in edges1[v]
            if (visited[i] == 0) {
                DFS(i, x);
            }
        }order.push_back(v);
    }
    else{
        comp.push_back(v);
        for (auto i: edges2[v]) { // assign i equal to the values of the elements in edges2[v]
            if (visited[i] == 0) {
                DFS(i, x);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin ("cond.in");
    ofstream fout ("cond.out");
    fin >> n >> m;
    edges1.resize(n);
    edges2.resize(n);
    for (int i=0; i<m; i++) { // push all edges to edges1 and edges2
        int v1, v2;
        fin >> v1 >> v2;
        edges1[v1-1].push_back(v2-1);
        edges2[v2-1].push_back(v1-1);
    }
    visited.assign(n, 0);
    for (int i=0; i<n; i++) {
        if (visited[i] == 0) {
            DFS(i, 1); // DFS for edges1
        }
    }
    visited.assign(n, 0);
    result.assign(n, 0);
    for (int i=(int)order.size()-1; i>=0; i--) {
        if (visited[order[i]] == 0) {
            comp.clear();
            DFS(order[i], 2);// DFS for edges2
            cnt ++; //
            for (auto j: comp) {// assign i equal to the values of the elements in comp
                result[j] = cnt;
            }
        }
    }
    fout << cnt << endl;
    for (auto i: result) 
        fout << i << "  ";
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab9/lab9D/lab9D/cond.in
