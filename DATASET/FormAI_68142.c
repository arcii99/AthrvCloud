//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#define MAX 100

int main()
{
    int arr[MAX], i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The positive elements of the array are:\n");
    for(i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}