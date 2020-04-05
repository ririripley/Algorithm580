//
// Created by 黄紫君 on 10/03/2020.
//
#include <iostream>

#include <unordered_map>
using namespace std;
int main(){
//    数组中第一个出现一次的字符（这题是没有要求要第一次）
//    思路：利用hashmap
    char list[10]= {'a','b','a','b','c','d','e','c','f','d'};
    unordered_map<char,int> dict;
    for(int i = 0; i < 10; i++){
        if(dict.find(list[i]) == dict.end())
            dict[list[i]] = 1;
        else
            dict[list[i]]++;
    }
    cout << "The first character that appears only once in the array." << endl;
    for(int i = 0; i < 10; i++){
        if(dict[list[i]] == 1){
            cout << list[i] << endl;
            break;
        }
    }

    cout << "Print all the characters that only appear once in the array." << endl;
    unordered_map<char, int>::iterator it = dict.begin();
    while(it != dict.end()){
        if (it->second == 1)
            cout << it->first << "  ";
        it++;
    }
    cout << endl;
}

