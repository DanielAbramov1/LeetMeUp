/*
----------------------------------------------------------------------------------------------------------------------------------
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"
// #define ENABLE_TESTING

int longestValidParentheses(char *s) {
    int maxLen = 0;
    int len = strlen(s);
    int *dp = (int *)malloc(len * sizeof(int));

    memset(dp, 0, len * sizeof(int));

    for (int i = 1; i < len; i++) 
    {
        if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') 
        {
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i - 1] - 2 >= 0) 
            {
                dp[i] += dp[i - dp[i - 1] - 2];
            }
            maxLen = maxLen > dp[i] ? maxLen : dp[i];
        }
    }

    free(dp);
    return maxLen;
}

#ifdef ENABLE_TESTING
void main()
{
    int choise = 0;
    while(choise != -1)
    {
        char inputChars[20] = {0};
        printf("\nEnter debug choise 1-8, -1 for exit:");
        scanf("%d", &choise);

        switch(choise)
        {
            case 1:
                strncpy(inputChars,  "(()", sizeof("(()"));
                printf("expected 2 result is:");
                break;
            case 2:
                strncpy(inputChars,  ")()())", sizeof(")()())"));
                printf("expected 4 result is:");
                break;
            case 3:
                strncpy(inputChars,  "", sizeof(""));
                printf("expected 0 result is:");
                break;
            case 4:
                strncpy(inputChars,  ")(", sizeof(")("));
                printf("expected 0 result is:");
                break;
            case 5:
                strncpy(inputChars,  "()", sizeof("()"));
                printf("expected 2 result is:");
                break;

            case 6:
                printf("expected 2 result is:");
                strncpy(inputChars, "())",sizeof("())"));
                break;
            case 7:
                printf("expected 4 result is:");
                strncpy(inputChars, "()()",sizeof("()()"));
                break;

            case 8:
                printf("expected 2 result is:");
                strncpy(inputChars, "()(()",sizeof("()(()"));
                break;

            case -1:
                return;

            default:
                break;
        }
        printf("%d\n" ,longestValidParentheses(inputChars));
    }
    
    return;
}
#endif