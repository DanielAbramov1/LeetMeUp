/*
----------------------------------------------------------------------------------------------------------------------------------
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"
// #define ENABLE_TESTING

#define MAX_CONSTRAIN_VAL (int)100

int * reverseSubArray(int *arr , int arrSize, int startIndex, int endIndex)
{
    // checking valid inputs
    if(startIndex < 0 || endIndex < 0 || startIndex > arrSize - 1 || endIndex > arrSize - 1 || startIndex > endIndex)
    {
        printf("Input failure <reverseSubArray>\n");
        return arr;
    }

    int temp;
    while (startIndex < endIndex)
    {
        temp = *(arr + startIndex);
        *(arr + startIndex) = *(arr + endIndex);
        *(arr + endIndex) = temp;

        startIndex++;
        endIndex--;
    }
    
    return arr;
}


void nextPermutation(int* nums, int numsSize) 
{
    int i;
    int j;

    int smallestNum = MAX_CONSTRAIN_VAL;
    int smalletstNumIndex;
    int swapTemp;

    // find the first element that is smaller than its immediate right neighbor
    for(i = numsSize - 2; i >= 0; i--)
    {
        if(*(nums + i) < *(nums + i + 1))
        {
            break;
        }
    }

    // if i==-1 the array is in descending order, and it is already the largest permutation
    if(i != -1)
    {
        //Find the smallest element to the right of index i that is greater than the element at index i
        for(j = i + 1; j < numsSize; j++)
        {
            if(*(nums + j) > *(nums + i) && *(nums + j) <= smallestNum)
            {
                smallestNum = *(nums + j);
                smalletstNumIndex = j;
            }
        }
        // swap smallest with val in index i
        swapTemp = *(nums + smalletstNumIndex);
        *(nums + smalletstNumIndex) = *(nums + i);
        *(nums + i) = swapTemp;
    }

    nums = reverseSubArray(nums, numsSize, i + 1, numsSize-1);
    
}

#ifdef ENABLE_TESTING
void main()
{
    int arr[] = {2,3,1,3,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // printf("checking function reverseSubArray():\n");
    // reverseSubArray(arr, arrSize, 0,15);
    // printArray(arr, arrSize);
    nextPermutation(arr, arrSize);
    printArray(arr, arrSize);


    return;
}
#endif