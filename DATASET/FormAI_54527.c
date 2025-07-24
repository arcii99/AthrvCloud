//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

int main()
{   
    int i, n;
    int* p;       // Pointer to int
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    p = (int*) malloc(n * sizeof(int));   // Allocating memory using malloc
 
    // If malloc fails to allocate memory
    if (p == NULL)
    {
        printf("Memory allocation failed, exiting program.\n");
        exit(0);
    }
 
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &*(p + i));   // Accepting input from user
    }
 
    printf("Elements you entered are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));   // Accessing values using pointer
    }
 
    free(p);   // Freeing memory allocated by malloc
    printf("\nMemory freed successfully!\n");
 
    return 0;
}