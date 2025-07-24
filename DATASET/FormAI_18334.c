//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) // function to swap two integers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void funny_sort(int arr[], int n) // function to sort an integer array in funny way
{
    printf("\nWelcome to Funny Sort!\n");
    printf("Get ready to witness the funniest sorting algorithm ever!\n");
    printf("Sorting %d elements...\n\n", n);
    
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                printf("Oh no! %d is greater than %d!\n", arr[j], arr[j+1]);
                printf("Swapping them to fix the problem...\n\n");
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    
    printf("Congratulations! The sorting is complete!\n");
    printf("Now, let's have some fun...\n\n");
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        if(i == n-2)
        {
            printf("and "); // adding some humor
        }
    }
    printf("\n\n");
}

int main()
{
    int arr[] = {10, 2, 7, 5, 8, 12, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    funny_sort(arr, n);
    return 0;
}