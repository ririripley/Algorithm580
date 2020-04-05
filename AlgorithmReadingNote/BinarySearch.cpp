#include <iostream>

using namespace std;

// Find the least index in an array pointing to the target
int binarySearch(int nums[], int target, int left, int right) {
    if (right < left)
        return -1;
    int mid = (left + right)/2;
    if (target < nums[mid]){
        return binarySearch(nums, target,left, mid - 1);
    }
    else if (target > nums[mid]){
        return binarySearch(nums, target, mid + 1, right);
    }
    else{
        int other = binarySearch(nums, target,left, mid - 1);
        return ( other == -1 ?  mid : other);
    }
}

int main() {
    int nums[9] = {1,2,2,2,3,3,3,3,4};
    int nums1[9] = {1,2,3,4,4,6,7,8,9};
    int pos = binarySearch(nums,9,0,8);
    cout << pos << endl;
    return 0;

}
/**
 * Time Complexity Analysis
 * input size: N
 *
 * For any input, time complexity is LOG2(N)
 * */

