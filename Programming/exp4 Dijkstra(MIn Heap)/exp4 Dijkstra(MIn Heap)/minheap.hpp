//
//  minheap.hpp
//  exp4 Dijkstra(MIn Heap)
//
//  Created by QianqianLiao on 2021/5/30.
//

#ifndef minheap_hpp
#define minheap_hpp

#include <stdio.h>
#include <vector>
using namespace std;

typedef struct {
    int value;
    int vertex;
}HeapNode;

class MinHeap{
public:
    vector<HeapNode> heap;
    void Insert(int num, int vertex);
    void Delete(int index);
    int GetSize();
    int GetValue(int index);
    int GetVertex(int index);
    int GetValueByVertex(int vertex);
    int GetIndexByVertex(int vertex);
};

void MinHeap::Insert(int num, int vertex){
    int index = int(heap.size());  // the index of the insert num
    HeapNode node;
    node.value = num;
    node.vertex = vertex;
    heap.push_back(node);
    while (index != 0) {
        if (heap[index].value < heap[index / 2].value) {
            swap(heap[index], heap[index / 2]);
        }
        index /= 2;
    }
}

void MinHeap::Delete(int del_index){
    // Delete min value and replace it with the last value
    swap(heap[del_index], heap[heap.size() - 1]);
    heap.pop_back();
    if (heap.size() == 0 || heap.size() == 1) {
        return;
    }
    int index = del_index + 1;
    while (2 * index <= heap.size()) { // if the index has left tree
        int small_index = (heap[index - 1].value < heap[2 * index - 1].value) ? index : 2 * index;
        if (2 * index + 1 <= heap.size()) {
            small_index = (heap[small_index - 1].value < heap[2 * index].value ? small_index : 2 * index + 1);
        }
        if (index != small_index){   // the left tree or right tree is smaller
            swap(heap[index - 1], heap[small_index - 1]);
            index = small_index;
        }
        else{
            return;
        }
    }
}

int MinHeap::GetValueByVertex(int vertex){
    for (int i = 0; i < heap.size(); i++) {
        if (vertex == heap[i].vertex) {
            return heap[i].value;
        }
    }
    return -1;
}

int MinHeap::GetIndexByVertex(int vertex){
    for (int i = 0; i < heap.size(); i++) {
        if (vertex == heap[i].vertex) {
            return i;
        }
    }
    return -1;
}
int MinHeap::GetSize(){
    return int(heap.size());
}

int MinHeap::GetValue(int index){
    return heap[index].value;
}

int MinHeap::GetVertex(int index){
    return heap[index].vertex;
}

#endif /* minheap_hpp */
