/*
----------------------------------------------------------------------------------------------------------------------------------
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
----------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
*/

#include "common.h"
#include <stdbool.h>

typedef struct ListNode 
{
  int val;
  struct ListNode *next;
}ListNode_t;

// create new node
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

// returns true if all lists in the array are empty
bool isEmptyListArray(struct ListNode** lists, int listsSize) 
{
  int k = 0;
  int countEmptyLists = 0;

  while(k < listsSize)
  {
    if(*(lists + k) == NULL)
      countEmptyLists++;
    else
      break;

    k++;
  }

  if(countEmptyLists == listsSize)
    return true;
  else
    return false;
}

// returns the index of the first non null list
int firstValidListIndex (struct ListNode** lists, int listsSize)
{
  int index = -1;

  for (int k = 0; k < listsSize; k++)
  {
    if(*(lists + k) != NULL)
    {
      index = k;
      break;
    }
  }

  return index;
}

// returns the index of the smallest value in the  first nodes in the array of lists
int smallestValIndex(struct ListNode** lists, int listsSize)
{
  // store the first element val of the first list found
  int smallestValIndex = firstValidListIndex(lists, listsSize);
  int currentVal = (*(lists + smallestValIndex))->val;
  int minVal = currentVal;

  for (int k = smallestValIndex+1; k < listsSize; k++)
  {
    if(*(lists + k) != NULL)
    { 
      currentVal = (*(lists + k))->val;
      
      if(currentVal < minVal)
      {
        minVal = currentVal;
        smallestValIndex = k;
      }
    }
  }

  return smallestValIndex;
}

//TODO continue here - here we need to trim and rearrange the pointers
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
  if(isEmptyListArray(lists, listsSize))
  {
    printf("All the lists in the list array are empty\n");
    return NULL;
  }

  return NULL;
}


void main()
{
  struct ListNode * list2 = createNode();
  struct ListNode * list4 = createNode();
  struct ListNode * list5 = createNode();

  list2->val = 3;
  list4->val = 1;
  list5->val = 5;

  struct ListNode * lists[] = {NULL, list2, NULL, list4, list5};

  printf("the smallest is in list number:%d\n",smallestValIndex(lists, sizeof(lists)/sizeof(lists[0])) + 1);

  // struct ListNode * merged = createNode();
  // merged = mergeKLists(lists, sizeof(lists)/sizeof(lists[0]));

  free(list2);
  free(list4);
  free(list5);
  // free(merged);
  return;
}