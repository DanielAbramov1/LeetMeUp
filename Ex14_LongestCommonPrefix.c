/*
----------------------------------------------------------------------------------------------------------------------------------

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

----------------------------------------------------------------------------------------------------------------------------------
*/

/*@ Accessing the char elements in an array of strings explanaition 

    char signleCharElement = *(*(myStringsArray + stringIndex) + charIndex);

    signleCharElement   - signle char element value
    myStringArray       - array of strings like in the excersize : ["flower","flow","flight"]
    stringIndex         - index points to the number of the string like stringArr[i];
    charIndex           - char index in the relative string like stringArr[][i];

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define true    1
#define false   0

#define CHECK_VALID_PTR(ptr) \
    if(ptr == NULL) { \
        printf("Couldn't allocate memory <>\n"); \
        return NULL; \
    }

char* longestCommonPrefix(char** strs, int strsSize) 
{
    int prefixCounter   = 0;
    int stringIndex     = 0;
    int charIndex       = 0;

    int breakLoopFlag   = false;

    //allocate 1 char, check allocation and asign null terminal
    char* commonPrefixStr = (char*)malloc(1);
    CHECK_VALID_PTR(commonPrefixStr);

    *commonPrefixStr = '\0'; 
    
    // if there is only one string there are no common prefixes therefor skip the algorithm
    if(strsSize <= 1)
    {
        breakLoopFlag = true;
    }

    // stop condition : if found difference in prefix AND first string reached null terminal '\0'
    while(!breakLoopFlag && *(*strs + charIndex) != '\0')
    {
        int count = 0; //used inly in this scope counting the num string that the char element is equal

        for (stringIndex = 0; stringIndex < strsSize; stringIndex++)
        {
            // check if the n'th char element in every string is not equal (see explanation above) OR the char in the n'th string is equal to null terminal '\0'
            if(*(*strs + charIndex) != *(*(strs + stringIndex) + charIndex) || *(*(strs + stringIndex) + charIndex) == '\0')
            {   
                break; // break from the for loop no need to proceed to the next string
            }
            count++;
        }

        if(count != strsSize)
        {
            breakLoopFlag = true;
        }
        else
        {
            prefixCounter++;
        }

        charIndex++;
    }

    if(prefixCounter != 0)
    {
        commonPrefixStr = (char*)realloc(commonPrefixStr, prefixCounter+1);   //+1 for null terminal
        CHECK_VALID_PTR(commonPrefixStr);
        strncpy(commonPrefixStr, *strs, prefixCounter);     // copy the char from the first string in the array
        commonPrefixStr[prefixCounter] = '\0';              
    }

    return commonPrefixStr;
}   

void main()
{
    char *test1[] = {"flower","flow","flight"};
    char *ptr1 = longestCommonPrefix(test1,3);
    printf("first common prefix of [flower,flow,flight] is :%s\n",ptr1);
    free(ptr1);

    char *test2[] = {"dog","racecar","car"};
    char *ptr2 = longestCommonPrefix(test2,3);
    printf("first common prefix of [dog,racecar,car] is :%s\n",ptr2);
    free(ptr2);

    char *test3[] = {"","racecar","rcar"};
    char *ptr3 = longestCommonPrefix(test3,3);
    printf("first common prefix of [,racecar,rcar] is :%s\n",ptr3);
    free(ptr3);

    char *test4[] = {"s","sracecar","scar"};
    char *ptr4 = longestCommonPrefix(test4,3);
    printf("first common prefix of [s,sracecar,scar] is :%s\n",ptr4);
    free(ptr4);

    char *test5[] = {"s","ssss","scar","","sasdafd"};
    char *ptr5 = longestCommonPrefix(test5,5);
    printf("first common prefix of [s,ssss,scar,,sasdafd] is :%s\n",ptr5);
    free(ptr5);

    char *test6[] = {"asdf","asdfskcar","asdfpouhj","asdfskasdafd"};
    char *ptr6 = longestCommonPrefix(test6,4);
    printf("first common prefix of [asdf,asdfskcar,asdfpouhj,asdfskasdafd] is :%s\n",ptr6);
    free(ptr6);
    return;
}