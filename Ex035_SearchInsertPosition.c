/*
----------------------------------------------------------------------------------------------------------------------------------
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4

----------------------------------------------------------------------------------------------------------------------------------
*/
#include "common.h"
#define ENABLE_TESTING

int searchInsert(int* nums, int numsSize, int target) 
{


    // 2 pointers approch for binary search
    int left = 0;
    int right = numsSize - 1;

    // target is greater then the last element of the array
    if(target > *(nums + right))
        return numsSize;
    
    // targer is lower then the first element of the array
    if(target < *(nums + left))
        return 0;


    int resultIndex = -1;

    // iterate until left reaches/passes right
    while(left <= right)
    {
        int middle = (left + right)/2;

        if(*(nums + middle) < target)// the targets are on the right side relative to the middle
        {
            left = middle + 1;

            // left pointer hits the target
            if(target == *(nums + left))
            {
                resultIndex = left;
                break;
            }

            // the target is not in the array
            if(left - middle == 1  && target < *(nums + left) && target > *(nums + middle))
            {
                resultIndex = middle;
                break;
            }
        }

        else if(*(nums + middle) > target)// the targets are on the left side relative to the middle
        {
            right = middle - 1;

            // right pointer hits the target
            if(target == *(nums + right))
            {
                resultIndex = right;
                break;
            }

            // the target is not in the array
            if(middle - right == 1  && target > *(nums + right) && target < *(nums + middle))
            {
                resultIndex = middle;
                break;
            }

        }

        else // hit the target
        {
            resultIndex = middle;
            break; // can exit loop
        }

    }

    return resultIndex;
}

#ifdef ENABLE_TESTING
    void main()
    {
        // test case 1
        // int myArr[] ={1,3,5,6};
        // int target = 5;

        // test case 2
        // int myArr[] ={1,3,5,6};
        // int target = 2;

        // test case 3
        // int myArr[] ={1,3,5,6};
        // int target = 7;

        // test case 4
        int myArr[] ={1,3};
        int target = 2;

        printf("the target should be in index : %d\n",searchInsert(myArr, sizeof(myArr)/sizeof(myArr[0]), target));
        return;
    }
#endif