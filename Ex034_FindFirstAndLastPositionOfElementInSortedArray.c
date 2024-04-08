/*
----------------------------------------------------------------------------------------------------------------------------------
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
----------------------------------------------------------------------------------------------------------------------------------
*/
#include "common.h"
#define ENABLE_TESTING

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{   
    int * returnArray = (int*)malloc(2*sizeof(int));
    *returnSize = 2; // cause the company that asked that question is geh
    memset(returnArray, -1 , *returnSize * sizeof(int)); // init the array to be -1

    // initiate indexes for binary search on an array
    int left = 0;
    int right = numsSize - 1;

    //edge case for if the numSize <2
    if(numsSize == 0)
    {
        return returnArray;
    }
    else if(numsSize == 1)
    {
        if(*nums == target)
        {
            memset(returnArray, 0 , *returnSize * sizeof(int));
        }
        return returnArray;
    }

    //TODO need to adjust the algo to work with numsSize = 2;
    while(left <= right)
    {
        // to reach O(log n)
        int middle = (left + right)/2;

        if(*(nums + middle) < target) // the targets are on the right side relative to the middle
        {
            left = middle + 1;

            if(*(nums + left) == target && *returnArray != target) // first target located
            {
                *returnArray = left; 
            }
            if(*(nums + right) == target && *(returnArray + 1) != target) //last target located
            {
                *(returnArray + 1) = right; 
            }
        }   
        else if(*(nums + middle) > target) // the targets are on the left side relative to the middle
        {
            right = middle - 1;

            if(*(nums + left) == target && *returnArray != target) // first target located
            {
                *returnArray = left; 
            }
            if(*(nums + right) == target && *(returnArray + 1) != target) //last target located
            {
                *(returnArray + 1) = right; 
            }

        }
        else // hit the target exactly
        {
            if(*returnArray != -1) // found the first one already, process the last
            {
                if(*(nums + right) != target)
                {
                    right--;
                }
                else
                {
                    *(returnArray + 1) = right;
                }
            }
            else if(*(returnArray + 1) != -1) // found last one already process the first one
            {
                if(*(nums + left) != target)
                {
                    left--;
                }
                else
                {
                    *(returnArray) = left;
                }                
            }   
        }

        if(*returnArray != -1 && *(returnArray + 1) != -1) // found first and last exit while loop
        {
            break;
        }

    }

    return returnArray;
}

#ifdef ENABLE_TESTING
void main()
{
    // int arr[] = {5,7,7,8,8,10};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int target = 8;

    // int returnSize;
    // int * returnArr = searchRange(arr, size, target, &returnSize);
    // printf("expected [3,4] got:[%d,%d]\n", *returnArr, *(returnArr +1));

    // int arr[] = {5,7,7,8,8,10};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int target = 6;

    // int returnSize;
    // int * returnArr = searchRange(arr, size, target, &returnSize);
    // printf("expected [3,4] got:[%d,%d]\n", *returnArr, *(returnArr +1));

    // int arr[] = {};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int target = 0;

    // int returnSize;
    // int * returnArr = searchRange(arr, size, target, &returnSize);
    // printf("expected [-1,-1] got:[%d,%d]\n", *returnArr, *(returnArr +1));

    int arr[] = {2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 2;

    int returnSize;
    int * returnArr = searchRange(arr, size, target, &returnSize);
    printf("expected [-1,-1] got:[%d,%d]\n", *returnArr, *(returnArr +1));

    return;
}
#endif