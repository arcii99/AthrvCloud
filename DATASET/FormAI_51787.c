//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, *ptr, sum = 0;

    // Getting input from user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &num);

    // Allocating memory dynamically
    ptr = (int*) malloc(num * sizeof(int));

    if(ptr == NULL)                     
    {
        printf("Error! Memory not allocated");
        exit(0);
    }

    // Getting input from user
    printf("\nEnter elements of array:\n");

    for(int i = 0; i < num; i++) 
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    // Printing the sum and freeing the allocated memory
    printf("\nSum = %d\n", sum);
    free(ptr);

    return 0;
}