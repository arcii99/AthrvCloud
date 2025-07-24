//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
/* Statistical C Searching Algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
#define MAX_NUM 1000

int binary_search(int arr[], int value, int left, int right, int *count);

int main()
{
    int arr[SIZE], i, num, index, count = 0;
    
    srand(time(NULL));
    
    /* generating random numbers */
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_NUM;
    }
    
    /* printing the array */
    printf("Array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    /* getting input from user */
    printf("\nEnter a number to search: ");
    scanf("%d", &num);
    
    /* performing binary search */
    index = binary_search(arr, num, 0, SIZE - 1, &count);
    
    if (index == -1) {
        printf("\n%d not found in the array.\n", num);
    }
    else {
        printf("\n%d found at index %d.\n", num, index);
        printf("Number of comparisons made: %d\n", count);
    }
    
    return 0;
}

/* binary search algorithm */
int binary_search(int arr[], int value, int left, int right, int *count)
{
    int mid;
    
    while (left <= right) {
        (*count)++;
        mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return -1;
}