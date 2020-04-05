//
// Created by 黄紫君 on 08/03/2020.
//
#include <iostream>
using namespace std;
void SelectionSort(int nums[], int length){
    for (int i = 0; i < length - 1; i++){
        int min = i;
        int temp = nums[i];
        for (int j = i; j < length; j++){
            if(temp > nums[j]){
                min = j;
                temp = nums[j];
            }
        }
        if(min != i){
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
}
int main(){
    int nums[9] = {9,3,5,5,7,82,1,10,11};
    SelectionSort(nums, 9);
    for (int j = 0; j < 9;j++){
        cout << nums[j] << "  ";
    }
    return 0;


}
