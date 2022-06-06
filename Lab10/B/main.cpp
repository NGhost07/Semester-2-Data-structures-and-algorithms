#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
struct Point{
    int x, y;
};
 
double distance2P(Point a, Point b){ // function calculates the distance between two points
    return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
};
 
int main(int argc, const char * argv[]) {
    ifstream fin ("spantree.in");
    ofstream fout ("spantree.out");
    int n;
    fin >> n;
    vector<Point> points; // save all points
    vector<bool> visited; // marked vertexes approved
    visited.assign(n, false);
    vector<double> edges;
    edges.resize(n);
     
    for (int i=0; i<n; i++) {
        Point tmp;
        fin >> tmp.x >> tmp.y;
        points.push_back(tmp);
        // calculate the distance from the first vertex to the remaining vertices
        if (i > 0) {
            edges[i] = distance2P(points[0], points[i]);
        }
    }
    visited[0] = true; // marked first vertex vertexes approved
     
    double result = 0; // variables to save the results
    for (int i=1; i<n; i++) {
        int tmp = 0;
        double min_len = INT_MAX;// initialize the minimum distance by infinity
        for (int j=1; j<n; j++) {
            if (edges[j] < min_len && !visited[j]) {
                min_len = edges[j];
                tmp = j;
            }
        }
        visited[tmp] = true;
        result += min_len;
        for (int j=0; j<n; j++) {
            if (!visited[j]) {
                double len = distance2P(points[tmp], points[j]);
                if (len < edges[j])
                    edges[j] = len;
            }
        }
    }
    fout << setprecision(10) << result;
    return 0;
}
///Users/tranhoangnam/Desktop/Algorithm/lab10/lab10B/lab10B/
