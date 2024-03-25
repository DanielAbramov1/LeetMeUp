/*
----------------------------------------------------------------------------------------------------------------------------------
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Example 4:
Input: nums = [1,2,1,4,5,-2], target = 3
Output: [0,1,2,4,5]

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
----------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

#define CHECK_VALID_PTR(ptr) \
    if(ptr == NULL) { \
        printf("Couldn't allocate memory <>\n"); \
        return NULL; \
    }

#define true 1
#define false 0
 

/*  Complexity O(N) */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{

    //  Keep track of the new array size
    int pSize = 1; 
    int * p = (int*)calloc(pSize, sizeof(int));
    CHECK_VALID_PTR(p);

    //  sequentinal flag keeps track if the adjacent nums are still sums to the targert
    //  true  - allocate 1 int element
    //  false - allocate 2 elements
    int sequentialFlag = true;

    //  first element in the output array flag - address the use case of 2 first element that not sum to target
    int firstNewElement = true;

    for(int index = 1; index < numsSize; index++)
    {
        if(nums[index] + nums[index-1] == target)
        {
            if(sequentialFlag)
            {
                pSize++;
            }
            else // sequentialFlag = false
            {
                if (!firstNewElement)
                    pSize += 2;

                else // this need to run only once
                {
                    pSize++;
                    firstNewElement = false;
                }
                sequentialFlag = 1;
            }

            p = realloc(p, pSize);
            CHECK_VALID_PTR(p);

            //  using the pSize also as index but we need to reduce 1 from the current possition
            p[pSize-2] = index - 1; 
            p[pSize-1] = index;
        }
        
        else
        {
            sequentialFlag = false;
        }
    }

    *returnSize = pSize;
    return p;
}


/*  Code for manual check

void main()
{
    int arr[] = {-17,15,0,3,7,-5,9,13};
    int target = 3;

    int arrSize = sizeo1f(arr)/sizeof(int);
    printf("size of input arr = %d\n",arrSize);

    int newArrSize;

    int * newArr = twoSum(arr, arrSize, target, &newArrSize);

    for(int i = 0; i< newArrSize; i++)
    {
        printf("%d,",newArr[i]);
    }

    printf("\nsize of output arr = %d\n",newArrSize);

    return;
}

*/