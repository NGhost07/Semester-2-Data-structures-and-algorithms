#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
 
unsigned long long primMst(vector<vector<pair<int, int>>> &list, vector<bool> &visited){
    unsigned long long res = 0;
    // initialize priority queue, When using the greater operation, the element with the highest precedence is the one with the smallest value.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()){
        pair<int, int> v_w_Pair = q.top();
        q.pop();
        int dis = v_w_Pair.first; // distance
        int ver = v_w_Pair.second; // vertice
        if (visited[ver]){ // Once the element has been visited, nothing is needed
            continue;
        }
        visited[ver] = true;// If this is a vertex we have not yet visited, mark it as visited
        res += dis;
        for (int i = 0; i < list[ver].size(); i++){
            int v = list[ver][i].first;
            int d = list[ver][i].second;
            if (!visited[v]){
                q.push(make_pair(d, v));
            }
        }
    }return res;
}
 
int main(){
    ifstream fin("spantree3.in");
    ofstream fout ("spantree3.out");
    int n, m;
    fin >> n >> m;
    vector<vector<pair<int, int>>> list(n, vector<pair<int, int>>());
    vector<bool> visited(n, false);
    for (int i = 0; i < m; i++){
        int v1, v2, w;
        fin >> v1 >> v2 >> w;
        v1--;
        v2--;
        list[v1].push_back(make_pair(v2, w));
        list[v2].push_back(make_pair(v1, w));
    }
    unsigned long long res = primMst(list, visited);
    fout << res;
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab10/lab10C/lab10C/spantree3.in

