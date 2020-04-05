//
// Created by 黄紫君 on 09/03/2020.
//
#include <iostream>

using namespace std;

void QuickSort(int nums[], int left, int right) {
    if (right <= left)
        return;
    int key = nums[left];
    int j = right;
    int i = left;
    while (i < j) {
        while (nums[j] >= key && i < j) { // 忘记在while循环内添加 i < j 属于logic mistake 不够严谨
            j--;
        }
        if (j > i) {
            nums[i] = nums[j];
        }
        while (nums[i] <= key && i < j) {
            i++;
        }
        if (i < j) {
            nums[j] = nums[i];
        }

    }

    if (i == j) {
        nums[i] = key;
    }
    QuickSort(nums, left, i - 1);
    QuickSort(nums, i + 1, right);
}

int main() {
    int nums[9] = {9,3,5,5,7,82,1,10,24};
    int nums1[5] = {0,3,1,4,2};
    QuickSort(nums,0,8);
    for (int j = 0; j < 9;j++){
        cout << nums[j] << "  ";
    }
    return 0;

}
