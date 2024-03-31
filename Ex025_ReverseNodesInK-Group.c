/*
----------------------------------------------------------------------------------------------------------------------------------
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1: see picture on https://leetcode.com/problems/reverse-nodes-in-k-group/description/


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
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
// #define ENABLE_TESTING

typedef struct ListNode 
{
    int val;
    struct ListNode *next;

}ListNode;

// create new node
struct ListNode * createNode(void)
{
    struct ListNode * p = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(p == NULL)
    { 
        printf("Couldn't allocate memory <createNode>\n");
        return NULL;
    }

    p->val = 0;
    p->next = NULL;

    return p;
}

// count node in a list or sub list
int nodesInList(struct ListNode* head)
{
    if(head == NULL)
    {
        printf("Head is NULL <nodesInList>\n");
        return 0;
    }

    int num = 0;
    while(head != NULL)
    {
        num++;
        head = head->next;
    }
    return num;
}

// releasing dummy node
struct ListNode * releaseDummyNode(struct ListNode * head)
{
    if(head == NULL)
    {
        printf("Head is NULL <releaseDummyNode>\n");
        return NULL;
    }
    else if(head->next == NULL)
    {
        printf("Head->next is NULL <releaseDummyNode>\n");
        return NULL;
    }
    else
    {
        struct ListNode * temp = head;
        head = head->next;
        free(temp);
        return head;
    }

}

// reverse a list or sub list
struct ListNode * reverseList(struct ListNode* head , struct ListNode* tail)
{
    //create dummy node
    struct ListNode * newHead = createNode();
    struct ListNode * newTail = newHead;

    // iterator for the original list
    struct ListNode * temp = head;

    while(head != tail)
    {
        if(temp->next == tail)
        {
            // disconnect the last node of the original list
            tail->next = NULL;

            // connect node to reversed list
            newTail->next = tail;
            newTail = newTail->next;

            // get back 1 node in the OG list
            tail = temp;

            // return temp to head of OG list
            temp = head;
        }
        else
        {
            // increament interator
            temp = temp->next;
        }
    }

    // connect last node
    head->next = NULL;
    newTail->next = head;

    // release dummy node
    newHead = releaseDummyNode(newHead);

    return newHead;
}

/*Runtime Complexity = O(n), Memory Complexity O(1)*/
struct ListNode * reverseKGroup(struct ListNode* head, int k) 
{
    // temp vars for processing
    struct ListNode * tempHead = head;
    struct ListNode * tempTail = head;

    // after processing vars
    struct ListNode * newHead = createNode();
    struct ListNode * newTail = newHead;

    while(nodesInList(head) >= k)
    {
        // moving the head k nodes, and the temp vals k-1 for processing reverse
        for(int i = 0; i < k-1; i++)
        {
            tempTail = tempTail->next;
        }
        head = tempTail->next;

        // reverse sub-list
        struct ListNode * reversedSubList = reverseList(tempHead, tempTail);

        // connect sub-list to main reversed list
        newTail->next = reversedSubList;

        // moving the new tail to the last node of the reversed list
        for(int i = 0; i < k; i++)
        {
            newTail = newTail->next;
        }

        // move temps to point to current head after processing
        tempHead = head;
        tempTail = head;
    }

    // connecting the remainder of the OG list
    newTail->next = head;

    // release first dummy node
    newHead = releaseDummyNode(newHead);

    return newHead;
}


#ifdef ENABLE_TESTING

void printList(struct ListNode * listToPrint)
{
    // for not loosing the head
    struct ListNode * temp = listToPrint;
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

void freeAllNodeInList(struct ListNode* head)
{
    while(head != NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    printf("List have been freed successfuly");

    return;
}

void main()
{
    struct ListNode* myHead = createNode();
    struct ListNode* node2 = createNode();
    // struct ListNode* node3 = createNode();
    // struct ListNode* node4 = createNode();
    // struct ListNode* node5 = createNode();

    myHead->val = 1;
    node2->val = 2;
    // node3->val = 3;
    // node4->val = 4;
    // node5->val = 5;

    myHead->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;


    printList(myHead);
    // printf("node in list : %d\n", nodesInList(myHead));
    
    // struct ListNode* reversedList = reverseList(myHead, node4);

    // printList(reversedList);

    // freeAllNodeInList(reversedList);

    struct ListNode * revesedHead = reverseKGroup(myHead, 2);
    printList(revesedHead);
    freeAllNodeInList(revesedHead);

    return;
}

#endif