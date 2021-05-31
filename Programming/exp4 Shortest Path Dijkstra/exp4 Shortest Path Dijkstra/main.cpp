//
//  main.cpp
//  exp4 Shortest Path Dijkstra
//
//  Created by QianqianLiao on 2021/5/30.
//

#include <iostream>
#include <vector>
using namespace std;



typedef struct {
    vector<int> vertex;
    vector<vector<int>> edge;
    int vertex_num;
}Graph;

void relax(int vertex1, int vertex2, vector<int> &dis, vector<vector<int>> &e){
    if (e[vertex1][vertex2] != INT_MAX) {   // a + INT_MAX may < 0
        dis[vertex2] = min(dis[vertex2], dis[vertex1] + e[vertex1][vertex2]);
    }
}

vector<int> dijkstra(Graph &g, int start){
    vector<int> dis(g.vertex_num, INT_MAX);
    vector<int> unsearched = g.vertex;
    dis[start] = 0;
    while (unsearched.size() != 0) {
        // find the min distance
        int min_dis = INT_MAX;
        int min_index = 0;
        int delete_index = 0;
        for (int i = 0; i < unsearched.size(); i++) {
            if (dis[unsearched[i]] < min_dis) {
                min_dis = dis[unsearched[i]];
                min_index = unsearched[i];
                delete_index = i;
            }
        }
        //remove from the unsearched node
        unsearched.erase(unsearched.begin() + delete_index);
        // update the shortest path
        for (int i = 0; i < unsearched.size(); i++) {
            relax(min_index, unsearched[i], dis, g.edge);
        }
    }
    return dis;
}

void initial_graph(Graph &g, vector<int> &v, vector<vector<int>> &e){
    g.vertex.insert(g.vertex.end(), v.begin(), v.end());
    g.edge = e;
    g.vertex_num = int(v.size());
}

int main(int argc, const char * argv[]) {
    Graph g;
    vector<int> v{0, 1, 2, 3, 4};
    vector<vector<int>> e{{0, 10, INT_MAX, 5, INT_MAX},
        {INT_MAX, 0, 1, 2, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 4},
        {INT_MAX, 3, 9, 0, 2},
        {7, INT_MAX, 6, INT_MAX, 0}};
    initial_graph(g, v, e);
    vector<int> dist = dijkstra(g, 0);
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i];
    }
    return 0;
}
