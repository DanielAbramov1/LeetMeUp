/*
----------------------------------------------------------------------------------------------------------------------------------

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:
 
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
----------------------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <string.h>

//  this size value is from 32-126 value in decimal (from ascii table) that represents all English letters, digits, symbols and spaces.
#define HASH_ARR_SIZE (int)95


/*  Complexity O(N) */
int lengthOfLongestSubstring(char* s) 
{
    //  init hash table with value 0
    int hashTable[HASH_ARR_SIZE] = {0};

    //  return the len value of the longest substring
    int longestSubstringLen = 0;

    //  need a temp value to incrament the continues substring len
    int tempLen = 0;

    for(int sIndex = 0; sIndex < strlen(s); sIndex++)
    {       
        //  hash map function
        int key = s[sIndex] % HASH_ARR_SIZE;

        //  new char detected, increament the count
        if(hashTable[key] == 0)
        {
            tempLen++;
        }

        //  collision spotted
        else
        {
            //  store the longest value
            if( tempLen > longestSubstringLen)
                longestSubstringLen = tempLen;

            //  init the new temp length to 1 and start counting again
            tempLen = 1;
        }


        //  continue inserting all chars into the hash map even if we go a colusion
        hashTable[key] = s[sIndex];
    }

    return longestSubstringLen;       
}

/* Code for manual check

void main()
{
    printf("Ex3 test\n");
    
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";
    char s4[] = "qazwsxedcs"; //answer should be 9
    char s5[] = "12qwaszxxjhhjkiujj"; //answer should be  8
    
    
    
    printf("string is %s, and the longest substring is %d\n",s1,lengthOfLongestSubstring(s1));
    printf("string is %s, and the longest substring is %d\n",s2,lengthOfLongestSubstring(s2));
    printf("string is %s, and the longest substring is %d\n",s3,lengthOfLongestSubstring(s3));
    printf("string is %s, and the longest substring is %d\n",s4,lengthOfLongestSubstring(s4));
    printf("string is %s, and the longest substring is %d\n",s5,lengthOfLongestSubstring(s5));

    return;
}

*/