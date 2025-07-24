//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int i, j, n, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted array in ascending order: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}