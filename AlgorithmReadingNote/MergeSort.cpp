//
// Created by 黄紫君 on 08/03/2020.
//
#include <iostream>

using namespace std;

    void merge(int nums1[], int left, int mid, int right){

    int i = left;
    int j = mid + 1;
    int k =0;
    int * p = new int[right - left + 1];

    while (i <= mid && j <= right){
        if(nums1[i] <= nums1[j]){
            p[k] = nums1[i];
            i++;
            k++;
        }
        else {
            p[k] = nums1[j];
            j++;
            k++;
        }

    }
    if(i > mid){
        while(j <= right){
            p[k] = nums1[j];
            j++;
            k++;
        }
    }

    if(j > right) {
        while (i <= mid) {
            p[k] = nums1[i];
            i++;
            k++;

        }
    }
    int n = 0;
    for (int k = left; k <= right; k++){
        nums1[k] = p[n]; // 写成了nums[k] = p[k]
        n++;

    }

    delete []p;

}

    void MergeSort(int nums[], int left, int right){
    if (left == right)
        return;
    int mid = (left + right) /2;
    MergeSort(nums, left,mid);
    MergeSort(nums, mid + 1, right);
    merge(nums,left,mid,right);
}




int main(){

    int nums1[5] = {0,3,1,4,2};
    int nums[9] = {9,3,5,5,7,82,1,10,24};
//    merge(nums1,0,1,3);
    MergeSort(nums,0,8);
    for (int i = 0; i <= 8; i++){
        cout << nums[i] << "  ";
    }
    cout << endl;

    return 0;
}
// 傻逼错误  即 i 写成 k
// 逻辑错误  一般需要check一遍algorithm确保是否有遗漏 或者 logic 上的错误