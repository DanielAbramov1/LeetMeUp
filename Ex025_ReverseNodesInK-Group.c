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
#define ENABLE_TESTING

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
    printf("Couldn't allocate memory <>\n");
    return NULL;
  }

  p->val = 0;
  p->next = NULL;

  return p;
}

// count node in a list or sub list
int nodesInList(struct ListNode* head , struct ListNode* tail)
{
  int num = 1; 
  while(head != tail)
  {
    num++;
    head = head->next;
  }
  return num;
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
  newTail = newHead;
  newHead = newHead->next;
  free(newTail);

  return newHead;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    
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
    struct ListNode* node3 = createNode();
    struct ListNode* node4 = createNode();

    myHead->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;

    myHead->next = node2;
    node2->next = node3;
    node3->next = node4;


    printList(myHead);
    printf("node in list : %d\n", nodesInList(myHead, node4));
    
    struct ListNode* reversedList = reverseList(myHead, node4);

    printList(reversedList);

    freeAllNodeInList(reversedList);
    return;
}

#endif