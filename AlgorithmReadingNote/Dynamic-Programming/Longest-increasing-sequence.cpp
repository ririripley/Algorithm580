//
// Created by 黄紫君 on 10/03/2020.
//

//
#define LEN 7
#include <math.h>
#include <iostream>
using namespace std;

int table[LEN] = {0};


void FindLongestSequence(int nums[], int index){
    if (index==0)
        return;
    for(int i = 0; i < index; i++){
        if(nums[index] > nums[i])
            table[index] = max(table[index], table[i] + 1);
    }
}

int main(){
    int nums[LEN] = {56, -12, 4, 34, -3, 5};
    for (int i = 0; i < LEN; i++){
        table[i]  = 1;
        FindLongestSequence(nums,i);
    }

    int maximum = 0;
    for (int i = 0; i < LEN; i++){
        maximum= max(maximum, table[i]);

    }
    cout << maximum << endl;
}