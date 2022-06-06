#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> cycle;// Cycle markers
vector<bool> used;// The vertex mark was visited
vector<int> order;// results after sorting
vector<int> temp; // temporary

bool check(int &vertex, int &Vstart, int &Vend) {
    //If the graph is periodic then cannot use Topological sorting
    cycle[vertex] = true;
    for (auto i : graph[vertex]) {
        int tmp = i;
        if (cycle[tmp] == false) {
            temp[tmp] = vertex;
            if (check(tmp, Vstart, Vend)) {
                return true;
            }
        }else if (cycle[tmp] == true) {
            Vstart = tmp;
            Vend = vertex;
            return true;
        }
    }cycle[vertex] = false;
    return false;
}

void top_sort(int vertex) {
    used[vertex] = true;
    for (auto i: graph[vertex])
        if (!used[i])
            top_sort(i);
    order.push_back(vertex);
}

int main() {
    ifstream fin ("topsort.in");
    ofstream fout ("topsort.out");
    int Vstart = -1, Vend;
    fin >> n >> m;
    graph.resize(n);// resize by graph is n
    used.assign(n, false);// used has n elements, all elements are false
    cycle.assign(n, false);//cycle has n elements, all elements are false
    temp.assign(n, -1); //temp has n elements, all elements are -1
    for (int i = 0; i < m; i++) { // push all vertices into graph
        int v1, v2;
        fin >> v1 >> v2;
        graph[v1 - 1].push_back(v2 - 1);
    }
    for (int i = 0; i < n; i++) { // check Topological sorting
        if (check(i, Vstart, Vend)) {// Vstart/end: vertice start/end
            fout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) { // Topological sorting
        if (!used[i]) {
            top_sort(i);
        }
    }
    for (int i = n-1; i >= 0; i--) { // print to file out
        fout << order[i] + 1 << " ";
    }
    return 0;
}
// /Users/tranhoangnam/Desktop/Algorithm/lab9/lab9A/lab9A/topsort.in
