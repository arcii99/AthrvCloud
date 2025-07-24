//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, *ptr, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    ptr = (int*) malloc(n * sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum = %d\n", sum);
    free(ptr);

    return 0;
}