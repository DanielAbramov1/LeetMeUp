/*
----------------------------------------------------------------------------------------------------------------------------------

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1: see on https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
----------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "common.h"

typedef struct ListNode 
{
    int val;
    struct ListNode *next;

}ListNode_t;


/* one pass on the list */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode* gapPtr = head;
    struct ListNode* nodeToDelete = head;
    struct ListNode* temp = head;

    //edge case for 1 node in list
    if(head-> next == NULL)
    {
        free(head);
        return NULL;
    }

    //move the gapPtr pointer n steps
    for(int i = 0; i < n; i++)
    {
        gapPtr = gapPtr->next;
    }

    //moving both pointers until gapPtr reaches null to create n gap between the end of the list and the node to delete
    while(gapPtr != NULL)
    {
        temp = nodeToDelete; //save the prev node of nodeToDelete
        nodeToDelete = nodeToDelete->next;
        gapPtr = gapPtr->next;
    }

   
    if(head == nodeToDelete) //edge case that the node to delete is the first node that head points
    {
        head = nodeToDelete->next;
    }
    else
    {
        temp->next = nodeToDelete->next;
    }

    free(nodeToDelete);

    return head;
}

/* Code for manual check
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

ListNode_t * createEmptyList(int nodeNum)
{
    if(nodeNum < 1)
    {
        printf("Amount of nodes are invalid for list");
        return NULL;
    }

    //create first node, init it and saving it to temp pointer
    ListNode_t * head = createNode();
    ListNode_t * temp = head;
    nodeNum--;

    while(nodeNum != 0)
    {
        //create new node and connect it to the list
        temp->next = createNode();
        temp = temp->next;
        nodeNum--;
    }

    return head;
}

void freeList(ListNode_t * list)
{
    while(list != NULL)
    {
        ListNode_t * temp = list;
        list = list->next;
        free(temp);
    }

    printf("List freed successfuly");
    return;
}

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
    int numberOfNodes;
    int nodeVal = 0;
    int nodeToDelet;

    printf("Please enter number of node for the new List\n");
    scanf("%d",&numberOfNodes);

    //create new list
    ListNode_t * myList = createEmptyList(numberOfNodes);
    printList(myList);

    //for not losing the head
    ListNode_t * temp = myList;

    while(numberOfNodes != 0)
    {
        printf("enter val for node or -1 to stop\n");
        scanf("%d",&nodeVal);
        if(nodeVal == -1)
        {
            break;
        }

        //insert the value and jump to next node
        temp->val = nodeVal;
        temp = temp->next;

        numberOfNodes--;
    }
    printf("after entering value the list is:\n");
    printList(myList);

    printf("enter the number of node from the back you want to remove:\n");
    scanf("%d",&nodeToDelet);

    myList = removeNthFromEnd(myList, nodeToDelet);
    printList(myList);
    
    freeList(myList);
    return;
}

*/