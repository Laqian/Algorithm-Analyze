//
//  main.cpp
//  exp4 Dijkstra(MIn Heap)
//
//  Created by QianqianLiao on 2021/5/30.
//

#include <iostream>
#include "minheap.hpp"

typedef struct {
    vector<int> vertex;
    vector<vector<int>> edge;
    int vertex_num;
}Graph;

void relax(int vertex1, int min_value, int vertex2, MinHeap &dis, vector<vector<int>> &e){
    if (e[vertex1][vertex2] != INT_MAX) {   // a + INT_MAX may < 0
        if (dis.GetValueByVertex(vertex2) > min_value + e[vertex1][vertex2]) {
            int value = min_value + e[vertex1][vertex2];
            int index = dis.GetIndexByVertex(vertex2);
            dis.Delete(index);
            dis.Insert(value, vertex2);
        }
    }
}

vector<int> dijkstra(Graph &g, int start){
    MinHeap dis;
    // initial heap
    for (int i = 0; i < g.vertex_num; i++) {
        if (i != start) {
            dis.Insert(INT_MAX, i);
        }
        else{
            dis.Insert(0, i);
        }
    }
    vector<int> unsearched = g.vertex;
    vector<int> searched(g.vertex_num, INT_MAX);
    while (unsearched.size() != 0) {
        // find the vertex with min value, in min heap the min index = 0
        int min_value = dis.GetValue(0);
        int min_vertex = dis.GetVertex(0);
        searched[min_vertex] = min_value;
        dis.Delete(0);
        //remove from the unsearched node
        for (int i = 0; i < unsearched.size(); i++) {
            if (min_vertex == unsearched[i]) {
                unsearched.erase(unsearched.begin() + i);
                break;
            }
        }
        // update the shortest path
        for (int i = 0; i < unsearched.size(); i++) {
            relax(min_vertex, min_value, unsearched[i], dis, g.edge);
        }
    }
    return searched;
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
        cout << dist[i]<< " ";
    }
    return 0;
}
