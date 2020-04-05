//
// Created by 黄紫君 on 08/03/2020.
//
#include <iostream>
using namespace std;

void BubbleSort(int nums[], int length)
{
    for (int i = length - 1; i > 0; i--){
        for (int j = 0; j < i; j++ ){
            if(nums[j] > nums[j + 1]){
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
int main(){
    int nums[9] = {9,3,5,5,7,82,1,10,11};
    BubbleSort(nums, 9);
    for (int j = 0; j < 9;j++){
        cout << nums[j] << "  ";
    }
    return 0;
}