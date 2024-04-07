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
#define ENABLE_TESTING


#define MAX_STACK_SIZE 15000 // half the string max length

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

char peek(Stack_t * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty - pop operation failed\n");
        return 0;
    }

    return stack->items[stack->top];
}

int longestValidParentheses(char* s) 
{
    if(s == NULL || s == '\0')
        return 0;

    Stack_t * stack = createStack();
    int sSize = strlen(s);

    for(int i = 0; i < sSize ;i++)
    {
        char charFromString = *(s + i);

        if(!isEmpty(stack))
        {
            char topStackChar = peek(stack);
            if(topStackChar == '(' && charFromString == ')')
            {
                topStackChar = pop(stack); // discard the popped value
            }
            else
            {
                push(stack, charFromString);
            }
        }
        else //stack empty
        {
            push(stack, charFromString);
        }
    }

    return sSize - (stack->top + 1);
}

#ifdef ENABLE_TESTING
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

void main()
{
    //TODO debug this test carse
    char inputChars[] ="()(()";


    return;
}
#endif