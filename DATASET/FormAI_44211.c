//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *ptr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation successful.\n");

        for (int i = 0; i < n; i++)
        {
            ptr[i] = i+1;
            printf("Enter the value of element %d: %d\n", i+1, ptr[i]);
        }

        free(ptr);
        printf("Memory has been freed successfully.\n");
    }

    return 0;
}