//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < (n-1); i++)
    {
        for (j = 0; j < (n-i-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}