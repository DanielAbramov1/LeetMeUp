/*
----------------------------------------------------------------------------------------------------------------------------------

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-2^31 <= x <= 2^31 

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define true    1
#define false   0

int reverse(int x)
{
    // first edge case
    if(x == 0)
    {
        return 0;
    }
    
    // 2nd edge case if number is negative
    int negativeFlag = false;
    if(x < 0)
    {
        negativeFlag = true;
    }

    // save the absolute value for processing
    x = abs(x);
    int xReversed = 0;

    while(x > 0)
    {
        xReversed = (xReversed*10) + (x%10);
        x = x/10;
    }

    // turn to negtive if flag was raised
    if(negativeFlag)
    {
        xReversed = -1*xReversed;
    }

    return xReversed;
}

/* Code for manual check
void main()
{
    int inputNum;
    while(1)
    {
        printf("please enter a number -2^31 <= num <= 2^31:\n");
        scanf("%d", &inputNum);
        printf("you entered the num :%d\n",inputNum);

        printf("the reversed integer is :%d\n", reverse(inputNum));
    }
    return;
}
*/