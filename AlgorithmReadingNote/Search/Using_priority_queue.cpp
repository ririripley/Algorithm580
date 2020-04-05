//
// Created by 黄紫君 on 10/03/2020.
//

#include <iostream>
#include <queue>
using namespace std;


struct Node{
public:
    Node(int val, Node* nex):value(val),next(nex) {value2 = value;}
    int value2;
    bool operator> (const Node& second) const {
        return this->value2 > second.value2;
    }
private:
    int value;
    Node* next;
//   friend bool operator< (const Node &first, const Node& second);

};

//bool operator<(const Node &first, const Node &second) {
//    return first.value <= second.value;}

//bool operator>(const Node &first, const Node &second) {
//        return first.value2 > second.value2;
//}

int main(){
//    Node p1 = Node(200, nullptr);
//    Node p2 = Node(5000, nullptr);
//    if(p1 > p2){
//        cout << "p1 < p2" << " success!" << endl;
//     }
//    else {
//        cout << "p1 < p2" << " fail!" << endl;
//    }
//    priority_queue<Node> myque;
//    Node p1 = Node(200, nullptr);
//    Node p2 = Node(5000, nullptr);
//    Node p3 = Node(100, nullptr);
//    Node p4 = Node(6000, nullptr);
//    myque.push(p1);
//    cout << myque.top().value2 << endl;
//    myque.push(p2);
//    cout << myque.top().value2<< endl;
//    myque.push(p3);
//    cout << myque.top().value2 << endl;
//    myque.push(p4);
//    cout << myque.top().value2 << endl;
//
//cout << endl;

    priority_queue<Node, vector<Node>, greater<Node> >myque2;
    Node q1 = Node(200, nullptr);
    Node q2 = Node(5000, nullptr);
    Node q3 = Node(100, nullptr);
    Node q4 = Node(6000, nullptr);

    myque2.push(q1);
    cout << myque2.top().value2 << endl;
    myque2.push(q2);
    cout << myque2.top().value2<< endl;
    myque2.push(q3);
    cout << myque2.top().value2 << endl;
    myque2.push(q4);
    cout << myque2.top().value2 << endl;
//
//    priority_queue< int, vector<int>, greater<int> > myque;
//    myque.push(1);
//    myque.push(10);
//    myque.push(100);
//    while(!myque.empty()){
//        cout << myque.top() << endl;
//        myque.pop();
//    }



}
//
//    bool operator < (struct Node first,struct  Node second) {
//        return (first.value <= second.value);
//    }
//    bool operator< (const struct Node &first, const struct Node &second)
//    {
//        return (n1.value < n2.value);
//    }







/*
 *使用STL构建riority_queue的Method1:
 * */
//    priority_queue<int, vector<int>, greater<int> > myque;
//    for(int i = 0; i < 10; i++){
//        myque.push(i);
//    }
//
//    cout << myque.top() << endl;
//
//    while(!myque.empty()){
//        cout << myque.top() << endl;
//        myque.pop();
//    }

//


