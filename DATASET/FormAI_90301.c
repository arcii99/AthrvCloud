//FormAI DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr, sum = 0;
 
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    ptr = (int*) malloc(n * sizeof(int)); 
 
    // Check if memory has been successfully allocated by malloc or not
    if(ptr == NULL)                     
    {
        printf("Memory allocation failed! Exiting program...\n");
        exit(0);
    }
 
    // Get elements from user and store in memory
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }
 
    printf("Elements in memory: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr+i));
    }
 
    printf("\nSum of elements: %d\n", sum);

    // Free allocated memory
    free(ptr);
 
    return 0;
}