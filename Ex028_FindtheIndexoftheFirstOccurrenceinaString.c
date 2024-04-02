/*
----------------------------------------------------------------------------------------------------------------------------------
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"
#define ENABLE_TESTING

int strStr(char* haystack, char* needle) 
{
    int returnIndex = -1;
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    // return -1 if the needle len is greater then haystack len
    if(needleLen > haystackLen)
        return returnIndex;

    // needle string iterator
    int k = 0;

    bool firstLatterInNeedleFlag = true;
    
    for(int i = 0; i < haystackLen; i++)
    {
        if(*(haystack + i) == *(needle + k))
        {
            // save the first index in the haystack
            if(firstLatterInNeedleFlag)
            {
                returnIndex = i;
                firstLatterInNeedleFlag = false;
            }

            k++;

            // number of the same chars is as needle then break
            if(k == needleLen)
                break;
        }
        else
        {
            // if the previous char in the haystack is the same as the first char in the needle
            if (i > 0 )
            {
                if(*(haystack + i - 1) == *needle)
                {
                    k = 1;
                    i--;
                    returnIndex = i;
                    firstLatterInNeedleFlag = false;
                }
                
            }
            else
            {
                k = 0;
                returnIndex = -1;
                firstLatterInNeedleFlag = true;
            }

        }
    }

    if(k < needleLen)
        returnIndex = -1;

    return returnIndex;   
}

#ifdef ENABLE_TESTING
void main()
{
    char needle[] = "issip";
    char haystack[] = "misissippt";

    printf("the first index is %d\n", strStr(haystack,needle));

    return;
}

#endif