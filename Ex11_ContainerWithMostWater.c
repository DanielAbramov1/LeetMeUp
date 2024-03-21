/*
----------------------------------------------------------------------------------------------------------------------------------

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


//complexity O(n)
int maxArea(int* height, int heightSize) 
{
    int maxArea = 0;
    int left = 0;               // Left pointer starting from the beginning of the array
    int right = heightSize - 1; // Right pointer starting from the end of the array

    while (left < right) 
    {
        int tempArea = (right - left) * MIN(height[left], height[right]); // Calculate area

        if (tempArea > maxArea) 
        {
            maxArea = tempArea;
        }

        // Move the pointer with smaller height inward to potentially increase the area
        if (height[left] < height[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }

    return maxArea;
}

/* Code for manual check
void main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    printf("the max area of given heigths is : %d\n", maxArea(arr, sizeof(arr)/sizeof(int)));
    return; 
}
*/