#ifndef COMMON_H
#define COMMON_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


// macros
#define true    1
#define false   0
#define CHECK_VALID_PTR(ptr) \
    if(ptr == NULL) { \
        printf("Couldn't allocate memory <>\n"); \
        return NULL; \
    }
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


//functions
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) 
        {
            if (arr[j] < pivot) 
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    return;
}

#endif /* COMMON_H */