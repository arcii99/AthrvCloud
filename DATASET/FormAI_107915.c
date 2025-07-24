//FormAI DATASET v1.0 Category: Random ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int n, i, j, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for(i=0;i<n;i++)
    {
        arr[i] = rand()%100; //generating random numbers between 0 and 99
    }

    printf("Array before sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }

    //sorting the array using bubble sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nArray after sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}