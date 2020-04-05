#include <iostream>
#include <vector>
using namespace std;

// Find the least index in an array pointing to the target
int binarySearch(int nums[], int target, int left, int right) {
    if (right < left)
        return right + 1;
    int mid = (left + right)/2;
    if (target < nums[mid]){
        return binarySearch(nums, target,left, mid - 1);
    }
    else if (target > nums[mid]){
        return binarySearch(nums, target, mid + 1, right);
    }
    else{
        int other = binarySearch(nums, target,left, mid - 1);
        return (mid > other ? other : mid);
    }
}

int main() {
    int nums[9] = {1,2,2,2,3,3,3,3,4};
    int nums1[9] = {1,2,3,4,4,6,7,8,9};
    int pos = binarySearch(nums,3,0,8);
    cout << pos << endl;
    return 0;

}


