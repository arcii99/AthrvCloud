//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
//Let's write a program to sort an array of integers using the Bubble Sort Algorithm!

#include<stdio.h>

int main()
{
    int n, i, j, temp;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d integers: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted integers: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Bubble Sort Algorithm
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n\nSorted integers in ascending order: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}