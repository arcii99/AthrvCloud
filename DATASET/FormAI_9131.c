//FormAI DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void quicksort(int* arr, int left, int right);
int partition(int* arr, int left, int right);
void swap(int* a, int* b);

int main(void)
{
    srand(time(NULL));
    int nums[SIZE];
    int i;
    printf("The end of the world has come, and chaos has taken over.\nBut amongst the ruins, there is still order to be found.\nIntroducing the apocalypse sorter!\n");
    for(i = 0; i < SIZE; i++)
    {
        nums[i] = rand() % 100;
    }
    printf("Unsorted Array:");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", nums[i]);
    }
    quicksort(nums, 0, SIZE - 1);
    printf("\nSorted Array:");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\nOrder has been restored.\n");
    return 0;
}

void quicksort(int* arr, int left, int right)
{
    if(left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
}

int partition(int* arr, int left, int right)
{
    int pivotValue = arr[right];
    int pivotIndex = left;
    int i;
    for(i = left; i < right; i++)
    {
        if(arr[i] < pivotValue)
        {
            swap(&arr[i], &arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(&arr[pivotIndex], &arr[right]);
    return pivotIndex;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}