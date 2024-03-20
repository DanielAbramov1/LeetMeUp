/*
----------------------------------------------------------------------------------------------------------------------------------
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
----------------------------------------------------------------------------------------------------------------------------------
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PRINT_IF_NULL(x) \
    if ((temp) == NULL) { \
        printf("0\n"); \
        return; \
    }

/**
 * Definition for singly-linked list.
 */

typedef struct ListNode 
{
    int val;
    struct ListNode *next;
}ListNode_t;


//create new node
ListNode_t * createNode(void)
{
    ListNode_t * p = (ListNode_t*)malloc(sizeof(ListNode_t));
    if(p == NULL)
    { 
        printf("Couldn't allocate memory <>\n");
        return NULL;
    }

    p->val = 0;
    p->next = NULL;

    return p;
}


//  convert inverted linked list to numer
//  example :2->5->7 = 752
int listToNum(ListNode_t* inputList)
{
    //  for not loosing the head
    ListNode_t * temp = inputList;
    if(temp == NULL)
    {
        printf("list is null\n");
        return 0;
    }

    int result = 0;
    int i = 0; 

    while(temp != NULL)
    {
        result = result + (temp->val * pow(10,i)); //  10^i - can use pow10(i) with compatible compiler
        i++;

        temp = temp->next;
    }

    return result;
}


//  convert numer to inverted linked list
//  example :752 = 2->5->7
ListNode_t * createListFromNum(int num)
{
    if(num <= 0)
        return NULL;

    ListNode_t * head = createNode();

    //  first value before looping throw the number
    head->val = num % 10;
    num = num/10;

    //  iterator for constructing the list without loosing the head
    ListNode_t * temp = head;

    while(num > 0)
    {
        //  creaating a new node and inserting value
        ListNode_t * newNode = createNode();
        newNode->val = num % 10;
        num = num / 10;

        //  connecting the nodes
        temp->next = newNode;

        //  jumping to the last node
        temp = newNode;
    }

    return head;
}

/*  Complexity O(N) */
struct ListNode* addTwoNumbers( ListNode_t* l1,  ListNode_t* l2) 
{
    int num1 = listToNum(l1);
    int num2 = listToNum(l2);

    ListNode_t * listResult = createListFromNum(num1 + num2);

    return listResult;
}


/*  Code for manual check

void printList(ListNode_t * listToPrint)
{
    //  for not loosing the head
    ListNode_t * temp = listToPrint;
    if(temp == NULL)
    {
        printf("list is null\n");
        return;
    }

    printf("List = ");
    while (temp != NULL)
    {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("NULL(end of list)\n");
    
    return;
}


void main()
{
    int inputNum1,inputNum2;

    printf("enter FIRST number to convert to a list: \t");
    scanf("%d",&inputNum1);
    ListNode_t * l1 = createListFromNum(inputNum1);
    printList(l1);
    printf("the original number is: %d\n", listToNum(l1));


    printf("enter FIRST number to convert to a list: \t");
    scanf("%d",&inputNum2);
    ListNode_t * l2 = createListFromNum(inputNum2);
    printList(l2);
    printf("the original number is: %d\n", listToNum(l2));

    ListNode_t * newList = addTwoNumbers(l1,l2);
    printf("The new ");
    printList(newList);
    printf("and the sum number is : %d\n", listToNum(newList));

    free(l1);
    free(l2);
    free(newList);

    return;
}

*/