/*
----------------------------------------------------------------------------------------------------------------------------------

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

----------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdbool.h>
#include "common.h"

#define MAX_STACK_SIZE 10000

typedef struct Stack
{
    char items[MAX_STACK_SIZE];
    int top;

}Stack_t;

Stack_t * createStack()
{
    Stack_t * newStack = (Stack_t*)malloc(sizeof(Stack_t));

    //init new stack
    memset(newStack, 0, sizeof(Stack_t));
    newStack->top = -1;

    return newStack;
}

bool isEmpty(Stack_t * stack)
{
    return stack->top == -1;
}

bool isFull(Stack_t * stack)
{
    return stack->top == MAX_STACK_SIZE-1;
}

void push(Stack_t * stack, char ch)
{
    if(isFull(stack))
    {
        printf("Stack overflow - push operation failed\n");
        return;
    }

    stack->top++;
    stack->items[stack->top] = ch;
    return; 
}

char pop(Stack_t * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty - pop operation failed\n");
        return 0;
    }

    char ch = stack->items[stack->top];
    stack->items[stack->top] = 0; // for visual debug purpose
    stack->top--;
    return ch;
}

void printStack(Stack_t * stack)
{
    printf("printing stack from top to bottom --->||\t ");
    for(int i = stack->top; i >= 0; i--)
    {
        printf("\t%c",stack->items[i]);
    }
    printf(" ||\n");

    return;
}

bool isValid(char* s) 
{
    // edge case for string length is 1
    int sLength = strlen(s);
    if(sLength == 1)
    {
        return false;
    }

    int sIndex = 0;

    Stack_t * myStack = createStack();
    while(sIndex < sLength)
    {
        char nextChar = s[sIndex];
        if(nextChar == '[' || nextChar == '(' || nextChar == '{')//if open bracket
        {
            push(myStack, nextChar);
        }
        else if(nextChar == ']' || nextChar == ')' || nextChar == '}') //if closing bracket
        {
            if(isEmpty(myStack))
            {
                return false;
            }
            else
            {
                char popedVal = pop(myStack);

                //the int value distance between the same bracket type is less then 2 in the ascii table
                if(abs(popedVal - nextChar) > 2)
                {
                    return false;
                }
            }
        }

        sIndex++;
    }

    if(isEmpty(myStack))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Code for manual check
void main()
{
    //enter use case here
    char inputChars[] ="()[]{}";
    if(isValid(inputChars))
    {
        printf("The string has valid parentheses\n");
    }
    else
    {
        printf("The stirng has NOT valid parentheses\n");
    }

    return;
}
*/