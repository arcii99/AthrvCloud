//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
/*
 * This program demonstrates the use of the bubble sort algorithm 
 * to sort an array of integers in ascending order.
 */

#include <stdio.h>

#define MAX_SIZE 10

void bubble_sort(int arr[], int n);

int main()
{
    int i, n, arr[MAX_SIZE];

    printf("Enter the number of elements to be sorted (Max 10): ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr, n);

    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}