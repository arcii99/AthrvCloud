//FormAI DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>

//function to perform bubble sort
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            //if current element is greater than next element, swap them
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 6, 1, 9, 8, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Unsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bubble_sort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}