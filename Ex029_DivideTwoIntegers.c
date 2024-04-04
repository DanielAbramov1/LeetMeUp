/*
----------------------------------------------------------------------------------------------------------------------------------
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-2^31 <= dividend, divisor <= 2^31 - 1
divisor != 0
----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"
#include <stdint.h>

bool isSigned(int num)
{
    if(num >= 0)
        return false;
    else
        return true;
}


int64_t myAbsolute(int num)
{
    int64_t result;

    if(num < 0)
    {
        int64_t temp = ~num;
        result = temp +1 ;
    }
    else
        result = num;

    return result;
}

int divide(int dividend, int divisor) 
{
    // xor operator will return the sing between 2 numbers
    bool signReturn = isSigned(dividend) ^ isSigned(divisor);

    int count = 0;

    // working with absolutes
    int64_t absDividend = myAbsolute(dividend);
    int64_t absDivider = myAbsolute(divisor);

    // edge case for out of int bounds
    if(dividend == INT32_MIN && absDivider == 1) 
    {
        if(isSigned(divisor))
            return INT32_MAX;
        else // advisor == 1
            return INT32_MIN;
    }

    // reducing the dividend until he is less then 0
    while(absDividend >= 0)
    {
        if(absDividend - absDivider >= 0)
        {
            count++;
        }
        absDividend = absDividend - absDivider;
    }
    
    // changing the sign if one of the nums is signed
    if(signReturn)
        count = (~count) + 1;

    return count;

}

void main()
{
    int a = -2147483648;
    int b = -1;
    printf("Dividing test without multiply and devision operators on %d / %d = %d\n", a, b, divide(a,b));

    a = 2147483647;
    b = 1;
    printf("Dividing test without multiply and devision operators on %d / %d = %d\n", a, b, divide(a,b));

    a = -2147483648;
    b = 1;
    printf("Dividing test without multiply and devision operators on %d / %d = %d\n", a, b, divide(a,b));

    a = 2147483647;
    b = -1;
    printf("Dividing test without multiply and devision operators on %d / %d = %d\n", a, b, divide(a,b));
    return;
}