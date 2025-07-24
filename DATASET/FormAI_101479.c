//FormAI DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdlib.h>

int main()
{
    int *ptr, i, n;
    printf("Welcome to the cyberpunk universe's memory management program.\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    
    if(ptr == NULL)
    {
        printf("Oops! The memory allocation failed. Looks like the system is hacked!\n");
        exit(0);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Enter element %d: ", i + 1);
            scanf("%d", ptr + i);
        }
        printf("Elements entered:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", *(ptr + i));
        }
    }
    free(ptr);
    printf("\nMemory allocated to the program has now been freed, erasing all traces of existence.\n");

    return 0;
}