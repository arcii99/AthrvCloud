//FormAI DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int n, i, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int*) malloc(n * sizeof(int)); // memory allocation for n integers
    if(ptr == NULL)                     
     {
        printf("Memory not allocated.");
        exit(0);
     }
    printf("Enter elements: ");
    for(i = 0; i < n; ++i) 
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}