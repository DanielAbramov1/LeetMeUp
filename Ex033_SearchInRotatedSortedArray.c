/*
----------------------------------------------------------------------------------------------------------------------------------
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
----------------------------------------------------------------------------------------------------------------------------------
*/
#include "common.h"
// #define ENABLE_TESTING

int search(int* nums, int numsSize, int target) 
{
    // initiate indexes for binary search on an array
    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        // to reach O(log n)
        int middle = (left + right)/2;

        // check that one of the indexes is pointing on target
        if(*(nums + middle) == target)
        {
            return middle;
        }
        else if(*(nums + left) == target)
        {
            return left;
        }
        else if(*(nums + right) == target)
        {
            return right;
        }

        if(*(nums + left) < *(nums + middle)) // left side is sorted relative to middle index
        {
            if(*(nums + left) <= target && target < *(nums + middle)) // target is somewhere is the left side
            {
                right = middle - 1;
            }
            else // target is somewhere in the right side 
            {
                left = middle + 1;
            }
        }
        else // right side is sorted relative to middle index
        {
            if(*(nums + right) >= target && target > *(nums + middle)) // target is somewhere is the right side
            {
                left = middle + 1;
            }
            else // target is somewhere in the left side 
            {
                right = middle - 1;
            }
        }
    }

    return -1; // if the target is not in the array
}


#ifdef ENABLE_TESTING
void main()
{
    // int arr[] = {3,1};
    // int target = 1;
    // int arr[] = {4,5,6,7,0,1,2};
    // int target = 0;
    int arr[] = {8,1,2,3,4,5,6,7};
    int target = 6;
    printf("%d\n", search(arr, sizeof(arr)/sizeof(arr[0]), target));
    return;
}
#endif