//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, temp;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];  // creating an integer array of size n
    srand(time(0)); // seeding the random number generator with current time

    // generating n random numbers between 0 and 500 and storing in the array
    for(i = 0; i < n; i++)
        arr[i] = rand() % 500;

    printf("Original Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Bubble Sort Algorithm
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}