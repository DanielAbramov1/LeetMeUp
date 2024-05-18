/*
----------------------------------------------------------------------------------------------------------------------------------
 the filled cells need to be validated according to the mentioned rules.
 

Example 1:
see example picture on https://leetcode.com/problems/valid-sudoku/

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true


Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 
Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
----------------------------------------------------------------------------------------------------------------------------------
*/

#include "common.h"
#define ENABLE_TESTING

bool isValidSudoku(char** board, int boardSize, int* boardColSize) 
{
    
}

#ifdef ENABLE_TESTING
void main()
{

    return;
}
#endif