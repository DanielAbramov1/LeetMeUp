/*
----------------------------------------------------------------------------------------------------------------------------------

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-2^31 <= x <= 2^31 - 1
----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) 
{
    // 1st edge case
    if(x == 0)
        return true;
    
    // 2nd edge case
    if(x < 0)
        return false;

    int xTemp = x;
    int xReverse = 0;

    while(xTemp > 0)
    {
        xReverse = (xReverse*10) + (xTemp%10);
        xTemp = xTemp/10;
    }

    if(x == xReverse)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Code for manual check
void main()
{
    int input;
    while(1)
    {
        printf("please enter input number:\n");
        scanf("%d",&input);
        if(isPalindrome(input))
            printf("the number %d is a palindrome\n", input);
        else
            printf("the number %d is NOT palindrome\n", input);
    }
        
    return;
}
*/