//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr; // declare integer pointer
    int n, i, sum = 0;
 
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    ptr = (int*)malloc(n * sizeof(int)); // allocate memory using malloc
 
    if(ptr == NULL)                     
    {
        printf("Memory allocation failed"); // checks if memory allocation is successful
        exit(0);
    }
 
    printf("Enter elements of array:\n");
    for(i = 0; i < n; ++i)
    {
        scanf("%d", ptr+i); // get values from user input
        sum += *(ptr+i);    // add the values
    }
 
    printf("Sum = %d\n", sum);
    
    free(ptr); // deallocate the memory
 
    return 0;
}