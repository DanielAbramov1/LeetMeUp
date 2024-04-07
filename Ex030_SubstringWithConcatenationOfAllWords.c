/*
----------------------------------------------------------------------------------------------------------------------------------
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
There is no substring of length 16 in s that is equal to the concatenation of any permutation of words.
We return an empty array.
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
----------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//TODO Ex30 not done

#include "common.h"
#define ENABLE_TESTING

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) 
{
    
}


#define MAX_LEN 100 // Maximum length of each string
#define MAX_WORDS 100 // Maximum number of words

void printCombinations(char** words, int n) 
{
    int totalCombinations = 1 << n; // Total number of combinations is 2^n

    for (int mask = 0; mask < totalCombinations; mask++) 
    {
        char current[MAX_LEN * MAX_WORDS + 1]; // Initialize current combination
        current[0] = '\0'; // Null-terminate the string

        for (int i = 0; i < n; i++) 
        {
            if (mask & (1 << i)) { // Check if word at index i is included in the current combination
                strcat(current, *(words + i)); // Concatenate the word using pointer arithmetic
            }
        }

        printf("%s\n", current); // Print the current combination
    }
}


#ifdef ENABLE_TESTING
void main()
{
    char * words[] = {"bar","foo","the"};
    printCombinations(words, 3);


    return;
}
#endif

