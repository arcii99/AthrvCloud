//FormAI DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int n, i, j, temp;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    srand(time(0)); // for generating random numbers
    printf("\nOriginal Array: ");
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // random numbers
        printf("%d ", arr[i]); // printing the array
    }

    // Selection Sort Algorithm
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Displaying the sorted array
    printf("\n\nSelection Sort: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}