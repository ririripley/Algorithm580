//
// Created by 黄紫君 on 10/03/2020.
//

#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;
struct Node{
    Node(int _age, string _value):value(_value),age(_age){};
    int age;
    string value;
    bool operator==(const Node & p) const
    {
        return this->age == p.age  && this->value == p.value;
    }
};

struct hash_name{
    size_t operator()(const Node& node) const{
        return (hash<int>() (node.age) ^ hash<string>() (node.value));
    }
};

int main(){
    unordered_map<Node, int, hash_name> mydict;

    Node q1 = Node(200, "hzj");
    Node q2 = Node(5000, "gjf");
    Node q5 = Node(100, "jesus");
    Node q4 = Node(6000, "happy");
    Node q3 = Node(6000, "happy");

    Node node[5] = {q1,q2,q3,q4,q5};
    for (int i = 0; i < 5; i++){
        if (mydict.find(node[i]) == mydict.end())
            mydict[node[i]] = 1;
        else
            mydict[node[i]]++;
    }

    auto it = mydict.begin();
    while(it != mydict.end()){
        if (it->second == 2)
        {
            cout << "name: " << (it->first).value <<"    age: " << (it->first).age << endl;
        }
        it++;
    }


    return 0;



//    bool operator+ (Node& n1, Node&n2) {
//        return  n1.value < n2.value;
//    }
}