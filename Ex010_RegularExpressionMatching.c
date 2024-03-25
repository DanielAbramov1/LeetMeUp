/*
----------------------------------------------------------------------------------------------------------------------------------

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) 
{
    int m = strlen(s);
    int n = strlen(p);

    // Create a DP table to store the matching results
    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true; // Empty string matches empty pattern

    // Handle patterns like "a*", "a*b*", etc.
    for (int j = 1; j <= n; j++) 
    {
        if (p[j - 1] == '*') 
        {
            dp[0][j] = dp[0][j - 2]; // '*' matches zero characters
        }
    }

    // Fill the DP table based on the matching conditions
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') 
            {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else if (p[j - 1] == '*') 
            {
                dp[i][j] = dp[i][j - 2]; // '*' matches zero characters
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) 
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            } 
            else 
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n]; // Return the result for full string and pattern
}

/* Code for manual check
void main()
{
    char s[] = "aa";
    char p[] = "a";

    bool result = isMatch(s, p);
    printf("Output: %s\n", result ? "true" : "false");

    char s1[] = "aa";
    char p1[] = "a*";

    bool result1 = isMatch(s1, p1);
    printf("Output: %s\n", result1 ? "true" : "false");

    char s2[] = "aa";
    char p2[] = "a*";

    bool result2 = isMatch(s2, p2);
    printf("Output: %s\n", result2 ? "true" : "false");

    return;
}
*/
