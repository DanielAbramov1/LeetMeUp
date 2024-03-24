/*
----------------------------------------------------------------------------------------------------------------------------------

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//TODO Ex5 not done

char* intToRoman(int num) 
{
    // output string allocation and verification and initialization
    char * output = (char*)calloc(100, sizeof(char));
    if(output == NULL)
    {
        printf("Memory Allocation failed\n");
        return NULL;
    }

    // define arrays for Roman numeral symbols and their corresponding values
    char * symbols[] = {"M", "D", "C", "L", "X", "V", "I"};
    int values[] = {1000, 500, 100, 50, 10, 5, 1};

    // iterate through the symbol-value arrays to construct the Roman numeral
    for (int i = 0; i < 7; i += 2) 
    {
        while (num >= values[i]) 
        {
            strcat(output, symbols[i]);
            num -= values[i];
        }

        // check for subtraction cases and append the appropriate symbols
        if (i < 6 && num >= values[i] - values[i + 2]) 
        {
            strcat(output, symbols[i + 2]);
            strcat(output, symbols[i]);
            num -= (values[i] - values[i + 2]);
        }
    }
        
    return output;
}

void main()
{
    // int x = 3;
    // char* roman = intToRoman(x);
    // printf("%d in roman is %s\n",x, roman);
    // int x = 58;
    // char* roman = intToRoman(x);
    // printf("%d in roman is %s\n",x, roman);
    int x;
    while(1)
    {
        printf("Enter number to convert to roman\n");
        scanf("%d",&x);

        char* roman = intToRoman(x);
        printf("%d in roman is %s\n",x, roman);

        free(roman);

    }
    return;
}
