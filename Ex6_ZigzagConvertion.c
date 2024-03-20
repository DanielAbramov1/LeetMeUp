/*
----------------------------------------------------------------------------------------------------------------------------------

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

----------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENABLE_MATRIX_PRINT

void printMatrix(char *matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%c ", *((matrix + i * cols) + j));
        }
        printf("\n");
    }
    printf("\n");
    
    return;
}


char* convert(char* s, int numRows) 
{   
    //allocate 1000 bytes to meet the constrain in the excersize 
    char * convertedString = (char *)malloc(1000);
    if (convertedString == NULL) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int convIndex = 0;                  // converted string index
    int stringIndex = 0;                // string s index

    // matrix vars
    int numCols = numRows*5;            // dont know why multiply by 5 but it works
    char matrix[numRows][numCols];
    memset(matrix,' ',sizeof(matrix));  //setting the matrix with spaces for visual printing the matrix in the terminal
    int j = 0;                          // columb index
    int jump = numRows-1;               // zigzag jumping index
    
    //running throw all the input string
    while(stringIndex < strlen(s))
    {
        // normal vertical column insertion to the matrix
        if(jump == numRows-1)
        {
            for(int i = 0; i < numRows; i++)
            {
                matrix[i][j] = s[stringIndex];
                stringIndex ++;
            }
        }
        //diagonal insertion
        else
        {
            matrix[jump][j] = s[stringIndex];
            stringIndex++;
        }

        // jumping throw the rows and columns diagonaly until jump index reaches 1
        if(jump == 1)
        {
            jump = numRows-1;
        }
        else
        {
            jump--;
        }

        // incramenting the columb after insertion type
        j++;
    }

// enable this print help function to see the matrix layout in terminal
#ifdef ENABLE_MATRIX_PRINT
    printf("The converted matrix print:\n");
    printMatrix(*matrix,numRows,numCols );
#endif

    for(int row = 0; row <= numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            //not insert space or null terminal char converted string and overheading the existing length of the input string (maybe bug because of unknown column allocation)
            if((matrix[row][col] != ' ') && (matrix[row][col] != '\0') && (convIndex < strlen(s)))
            {
                convertedString[convIndex] = matrix[row][col] ;
                convIndex++;
            }
        }
    }

    return convertedString;
}


void main() 
{
    char test[] = "PAYPALISHIRING" ;
    printf("the string before conversion is :%s\n",test);
    
    char * output = convert(test,10);
    printf("converted string is :%s\n",output);

    free(output);

    return;
}