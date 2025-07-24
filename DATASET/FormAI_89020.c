//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* ptr;
    int n;
    printf("Enter the size of array you want to create: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &ptr[i]);
        }
        printf("Elements in the array are: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ptr[i]);
        }
    }
    else
    {
        printf("Unable to allocate memory");
    }
    free(ptr);
    return 0;
}