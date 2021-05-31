//
//  main.cpp
//  Tree Depth
//
//  Created by QianqianLiao on 2021/4/30.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct{
    Node* root;
    int node_num;
} Tree;

void insert(Tree* tree, int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->node_num == 0){
        tree->root = node;
    }
    else if(node_num % 2 == 0){
        while (<#condition#>) {
            <#statements#>
        }
    }
}

int main(int argc, const char * argv[]) {
    Tree tree;
    tree.node_num = 0;
    tree.root = NULL;
    int num;
    cout << "input the node number";
    cin >> num;
    cout << "input data to create tree\n";
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        
    }
    return 0;
}
