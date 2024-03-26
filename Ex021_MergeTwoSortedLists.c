/*
----------------------------------------------------------------------------------------------------------------------------------

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1: see picture on https://leetcode.com/problems/merge-two-sorted-lists/


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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

/*@list1 and list2 are not getting mutated, for the merge list we create new list

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    // edge case for both lists are empty
    if(list1 == NULL && list2 == NULL)
    {
        printf("Both lists are empty\n");
        return NULL;
    }

    // creating the merged list
    ListNode_t * head = createNode();

    // for not losing the head
    ListNode_t * temp = head;

    while(list1 != NULL || list2 != NULL)
    {
        ListNode_t * newNode = createNode();

        if(list1 == NULL)
        {
            newNode->val = list2->val;

            // connecting the new node
            temp->next = newNode;

            // moving temp to the end of the list
            temp = newNode;

            // moving to the next node in list2
            list2 = list2->next;
        }
        else if(list2 == NULL)
        {
            newNode->val = list1->val;

            // connecting the new node
            temp->next = newNode;

            // moving temp to the end of the list
            temp = newNode;

            // moving to the next node in list1
            list1 = list1->next;
        }
        else
        {
            ListNode_t * extraNewNode = createNode();
            newNode->val        = list1->val;
            extraNewNode->val   = list2->val;
            if(newNode->val <= extraNewNode->val)
            {
                // connecting the  the smallest value node first
                temp->next = newNode;

                // moving temp to the end of the list
                temp = newNode;

                // moving the list to the next node
                list1 = list1->next;

                //free the new created not that is not beeing used
                free(extraNewNode);
            }
            else
            {
                // connecting the  the smallest value node first
                temp->next = extraNewNode;

                // moving temp to the end of the list
                temp = extraNewNode;

                // moving the list to the next node
                list2 = list2->next;

                //free the new created not that is not beeing used
                free(newNode);
            }

        }
    }

    // moving head to point for the first element of the merged list and free the node
    temp = head;
    head = head->next;
    free(temp);

    return head;
}
*/

/*@merging both list into one using the same memory and nodes from lists*/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    // edge case for both lists are empty
    if(list1 == NULL && list2 == NULL)
    {
        printf("Both lists are empty\n");
        return NULL;
    }

    // creating dummy node for easier interconnection for the merged list, will free the dummy node at return
    ListNode_t * head = createNode();

    // for not losing the head
    ListNode_t * temp = head;

    // using flag to decide which list's first node to reconnect to merged list
    // 0 for init
    // 1 for list1  
    // 2 for list2 
    int trimFlag = 0;

    while(list1 != NULL || list2 != NULL)
    {
        if(list1 == NULL)
        {
            trimFlag = 2;
        }
        else if(list2 == NULL)
        {
            trimFlag = 1;
        }
        else
        {
            if(list1->val <= list2->val)
            {
                trimFlag = 1;
            }
            else
            {
                trimFlag = 2;
            }
        }

        if(trimFlag == 1)// disconnect node from list 1
        {
            //connecting the first node of list1 to the merged list
            temp->next = list1;

            // moving temp to point to the next node of the merged list
            temp = temp->next;

            // moving list1 pointer to point to the next node of list1
            list1 = list1->next;

            // disconnecting the node that was merged from list1
            temp->next = NULL;
        }
        else if(trimFlag == 2)// disconnect node from list 2
        {
            //connecting the first node of list2 to the merged list
            temp->next = list2;

            // moving temp to point to the next node of the merged list
            temp = temp->next;

            // moving list2 pointer to point to the next node of list2
            list2 = list2->next;

            // disconnecting the node that was merged from list2
            temp->next = NULL;
        }
    }

    // moving head to point for the first element of the merged list and free the dummy node
    temp = head;
    head = head->next;
    free(temp);

    return head;
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

    ListNode_t * list1   = createNode();; //list 1 empty
    list1->val = 5;


    ListNode_t * list2 = createNode();
    list2->val = 1;
    ListNode_t * temp2 = createNode();
    temp2->val = 2;
    list2->next = temp2;
    temp2 = createNode();
    temp2->val = 4;
    list2->next->next = temp2;
    printf("list 1 is: ");
    printList(list1);
    printf("list 2 is: ");
    printList(list2);

    ListNode_t * merged = mergeTwoLists(list1,list2);
    printf("merged list is: ");
    printList(merged);

    free(list1);
    free(list2);
    free(merged);

    return;
}