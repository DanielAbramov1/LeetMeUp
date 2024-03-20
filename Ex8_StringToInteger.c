/*
----------------------------------------------------------------------------------------------------------------------------------

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Macro to check if a character is a digit (0-9)
#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')

// substracting the first dec value of '0' to receive the actual number
#define ASCII_DIGIT_DELTA (int) 48

#define true    1
#define false   0

int myAtoi(char* s) 
{
    // string vars
    int sLen = strlen(s);
    if(sLen == 0)
    {
        printf("String is empty, returning 0\n");
        return 0;
    }
    int sIndex = 0;
    
    // result vars and flag
    int output = 0;
    int negativeFlag = false;
    int startedFlag = false; 

    // this while loop stops as soon as a digit appear or no digits at all
    while(!startedFlag || sIndex < sLen)
    {  
        if (IS_DIGIT(s[sIndex]))
        {
            // check if the previous char is not out of scope and a '-'
            if(sIndex != 0 && s[sIndex-1] == '-')
            {
                negativeFlag = true;
            }
            startedFlag = true;
            break;
        } 

        sIndex++;
    }

    // if no digits found return;
    if(!startedFlag)
    {
        printf("No digits found in the string, returning 0\n");
        return 0;
    }

    // this while loop stops at the end of the string or when a non-digit char appear
    while(sIndex < sLen)
    {
        if(!IS_DIGIT(s[sIndex]))
        {
            break;
        }

        output = (output*10) + (s[sIndex] - ASCII_DIGIT_DELTA);
        sIndex++;
    }

    // turn to negative number if negativeFlag is raised
    if(negativeFlag)
    {
        output *= -1;
    }

    return output;

}

/* Code for manual check
void main()
{
    char test1[] = "42";
    printf("testing myAtoi on '42' -> %d\n",myAtoi(test1));
    char test2[] = "   -42";
    printf("testing myAtoi on '   -42' -> %d\n",myAtoi(test2));
    char test3[] = "4193 with words";
    printf("testing myAtoi on '4193 with words' -> %d\n",myAtoi(test3));
    char test4[] = "-231.275";
    printf("testing myAtoi on '-231.275' -> %d\n",myAtoi(test4));
    char test5[] = "a.-256u";
    printf("testing myAtoi on 'a.-256u' -> %d\n",myAtoi(test5));
    char test6[] = "  -372.73K7";
    printf("testing myAtoi on '  -372.73K7' -> %d\n",myAtoi(test6));
    char test7[] = "512.35";
    printf("testing myAtoi on '512.35' -> %d\n",myAtoi(test7));
    char test8[] = "13  ";
    printf("testing myAtoi on '13  ' -> %d\n",myAtoi(test8));
    char test9[] = "";
    printf("testing myAtoi on '' -> %d\n",myAtoi(test9));
    char test10[] = "1";
    printf("testing myAtoi on '1' -> %d\n",myAtoi(test10));
    return;
}
*/