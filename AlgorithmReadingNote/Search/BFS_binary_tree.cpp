//
// Created by 黄紫君 on 09/03/2020.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Given binary tree [3,9,20,null,null,15,7],
struct Node{
    int _value;
    Node* _left;
    Node* _right;
};


vector<int> BinaryTreeLevelOrderTraversal(Node * root){
    vector<int> list;
    queue<Node*> que;
    if(root == nullptr)
        return list;
    que.push(root);
    while(!que.empty())
    {
        Node* first = que.front();
        list.push_back(first->_value);
        que.pop();

        if (first->_left != nullptr){
            que.push(first->_left);

        }

        if (first->_right != nullptr){
            que.push(first->_right);
        }
    }
    return list;
}


int main(){
    struct Node* root = new Node;
    root->_value = 3;

    struct Node* left  = new Node;
    left->_value = 9;
    left->_left = nullptr;
    left->_right = nullptr;
    root->_left = left;

    struct Node* right  = new Node;
    root->_right = right;

    right->_value = 20;
    left = new Node;
    left->_value = 15;
    left->_left = nullptr;
    left->_right = nullptr;

    right->_left = left;

    left = new Node;
    left->_value = 7;
    left->_left = nullptr;
    left->_right = nullptr;

    right->_right = left;

    vector<int> tree = BinaryTreeLevelOrderTraversal(root);
    for (int i = 0; i< tree.size(); i++){
        cout << tree[i] << "  ";
    }
    cout << endl;
    return 0;
}
