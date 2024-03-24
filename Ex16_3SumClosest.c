/*
----------------------------------------------------------------------------------------------------------------------------------

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"

int threeSumClosest(int* nums, int numsSize, int target) 
{   
    int closest = INT_MAX; //init to high value for integer

    // quick sort the array
    quickSort(nums, 0, numsSize-1);

    // iterate until the 2 last values in the array for two pointer approach
    for(int i = 0; i < numsSize-2; i++)
    {
        int leftSide    = i + 1; // next value after index i
        int rightSide   = numsSize - 1; // last value of the array
        int switchSide = true; 

        while(leftSide != rightSide)
        {
            int temp = nums[i] + nums[leftSide] + nums[rightSide];
            

            // check closest distance
            if(abs(target - temp) <= abs(target - closest))
            {
                closest = temp;
            }
            if(switchSide)
            {
                rightSide--;
            }
            else
            {
                leftSide++;
            }
            switchSide = !switchSide;
        }
    }

    return closest;
}

/* Code for manual check
void main()
{   
    int test1[] = {-1,2,1,-4};
    int target1 = 1;
    printf("the closest sum of taget1[] to target %d is :%d\n", target1, threeSumClosest(test1, sizeof(test1)/sizeof(test1[0]), target1));

    int test2[] = {0,0,0};
    int target2 = 1;
    printf("the closest sum of taget2[] to target %d is :%d\n", target2, threeSumClosest(test2, sizeof(test2)/sizeof(test2[0]), target2));

    int test3[] = {40,-53,36,89,-38,-51,80,11,-10,76,-30,46,-39,-15,4,72,83,-25,33,-69,-73,-100,-23,-37,-13,-62,-26,-54,36,-84,-65,-51,11,98,-21,49,51,78,-58,-40,95,-81,41,-17,-70,83,-88,-14,-75,-10,-44,-21,6,68,-81,-1,41,-61,-82,-24,45,19,6,-98,11,9,-66,50,-97,-2,58,17,51,-13,88,-16,-77,31,35,98,-2,0,-70,6,-34,-8,78,22,-1,-93,-39,-88,-77,-65,80,91,35,-15,7,-37,-96,65,3,33,-22,60,1,76,-32,22};
    int target3 = 292;
    printf("the closest sum of taget3[] to target %d is :%d\n", target3, threeSumClosest(test3, sizeof(test3)/sizeof(test3[0]), target3));

    int test4[] = {4,0,5,-5,3,3,0,-4,-5};
    int target4 = -2;
    printf("the closest sum of taget3[] to target %d is :%d\n", target4, threeSumClosest(test4, sizeof(test4)/sizeof(test4[0]), target4));

    return;
}
*/