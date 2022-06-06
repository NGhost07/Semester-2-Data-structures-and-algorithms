#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &gra, vector<int> &visited, queue<int> Q, int t){
    Q.push(t);
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (auto i=1; i<=gra[a].size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin("/Users/tranhoangnam/Desktop/Algorithm/lab8/labE/labE/pathbge1.in");
    ofstream fout("/Users/tranhoangnam/Desktop/Algorithm/lab8/labE/labE/pathbge1.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> gra;
    gra.resize(n);
    for (int i=0; i<m; i++) {
        int v1, v2;
        fin >> v1 >> v2;
        gra[v1].push_back(v2);
        gra[v2].push_back(v1);
    }
    vector<int> visited;
    for (int i=1; i<n+1; i++)
        visited[i] = 0;
    queue<int> Q;
    BFS(gra, visited, Q, 1);
    for (int i=1; i<n+1; i++) 
        cout << visited[i] << " ";
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab8/labE/labE/
