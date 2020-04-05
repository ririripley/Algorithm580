//
// Created by 黄紫君 on 08/03/2020.
//

#include <iostream>
using namespace std;

// 2  3  5
void insertion(int nums[], int left, int right, int target) {
    int index;
    int _left = left;
    int _right = right;

    /* Using Binary Search To Find Out the Position for the Newly Inserted Element. */
    /**
     * 可以用target 直接跟 left right 比从而在极端的情况下提高效率
     */
    while (_right - _left > 1) {
        int mid = (_left + _right) / 2;
        if (nums[mid] > target) {
            _right = mid;
        }
        if (nums[mid] <= target) {
            _left = mid;
        }
    }
    if (target >= nums[_right])
        index = _right + 1;
    else if (target <= nums[_left])
        index = _left;
    else
        index = _right;


    for (int i = right + 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = target;

}

void InsertionSort(int nums[],int length){
    int left = 0;
    /*Iterative Method*/
    for(int i = 1; i < length; i++){
        insertion(nums,left,i - 1, nums[i]);
    }
}



int main(){
    int nums[10] = {9,3,5,5,7,82,1,10,11,3};
    int nums1[4] =  {9,3,5,5};
    InsertionSort(nums, 10);
    for (int j = 0; j < 10;j++){
        cout << nums[j] << "  ";
    }
    return 0;
}

// 检查 错漏的方法 ： check if condition 里面 是否漏了某种条件 （没有全包）
/**
 * Iterative Method
 * Time Complexity Analysis
 * input size: N
 * InsertionSort 必定执行N - 1
 * insertion 取决于找到位置的方法 从后往前比较 target值时：
 *
 * Best case:  already ordered
 * theta(1)  * （N - 1) = THETA(N)
 * Worst case:  reverse sorted
 * theta(1) + theta(2) + ...... theta(N - 1) = THETA(N^2)
 * */
