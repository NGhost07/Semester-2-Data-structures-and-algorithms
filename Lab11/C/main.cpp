#include <iostream>
#include <fstream>
#include <vector>
#include<set>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> G;
vector<int> dist; // distance
set<pair<int, int>> q;

int main(){
    ifstream fin ("pathbgep.in");
    ofstream fout ("pathbgep.out");
    
    fin >> n >> m;
    G.assign(n, vector<pair<int, int>>());
    dist.assign(n, INT_MAX);
    dist[0] = 0;

    for(int i = 0; i < m; ++i){
        int v1, v2, w;
        fin >> v1 >> v2 >> w;
        G[v1 - 1].push_back(make_pair(v2 - 1, w));
        G[v2 - 1].push_back(make_pair(v1 - 1, w));
    }

    q.insert({0, 0});
    while(!q.empty()){ // Bellman-Ford algorithm
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int i = 0; i < G[v].size(); i++){
            if (dist[G[v][i].first] > dist[v] + G[v][i].second){
                q.erase(make_pair(dist[G[v][i].first], G[v][i].first));
                dist[G[v][i].first] = dist[v] + G[v][i].second;
                q.insert(make_pair(dist[G[v][i].first], G[v][i].first));
            }
        }
    }
    
    for(int i: dist)
        fout << i << "  ";
    return 0;
}
// O(V.E)
///Users/tranhoangnam/Desktop/Algorithm/lab11/lab11C/lab11C/pathbgep.in
