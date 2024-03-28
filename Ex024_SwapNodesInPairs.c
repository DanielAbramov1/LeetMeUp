/*
----------------------------------------------------------------------------------------------------------------------------------
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1: see picture on https://leetcode.com/problems/swap-nodes-in-pairs/


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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
};

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

struct ListNode* swapPairs(struct ListNode* head) 
{
    // edge case for 0 and 1 nodes in the list
    if(head == NULL || head->next == NULL)
    {
        printf("No need to swap the list\n");
        return head;
    }

    // swap helpers
    struct ListNode * temp = head;
    struct ListNode * swapTail = head->next;

    // new pointers to keep track of the swapped list, crating dummy node for easy first time swap
    struct ListNode * newHead = createNode();
    struct ListNode * newTail = newHead;

    while(head != NULL)
    {
        // move 2 nodes
        head = head->next->next;

        // connecting and swapping
        newTail->next = swapTail;
        swapTail->next = temp;
        temp->next = NULL;

        // keep track of swapped list tail
        newTail = temp;

        // checking last nodes
        if(head != NULL)
        {
            // if only 1 lnode left
            if(head->next == NULL)
            {
                newTail->next = head;
                head = head->next;
            }
            else
            {
                temp = head;
                swapTail = head->next;
            }
        }
    }

    // free dummy node
    newTail = newHead;
    newHead = newHead->next;
    free(newTail);

    return newHead;
}

/* Code for manual check
void main()
{

    return;
}
*/