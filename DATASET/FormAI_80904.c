//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int *ptr;
int i, sum = 0;

// Function to allocate memory dynamically
void allocate_memory(int n)
{
    ptr = (int*) malloc(n * sizeof(int));
    printf("\nEnter the data: ");
    for(i = 0; i < n; i++){
        scanf("%d", (ptr + i));
        sum += *(ptr + i); // Calculating sum of entered data
    }
}

// Function to display the allocated memory with sum
void display_memory(int n)
{
    printf("\nAllocated Memory: ");
    for(i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }
    printf("\nSum of Entered Data: %d", sum);
}

// Function to deallocate the allocated memory
void deallocate_memory()
{
    free(ptr);
    printf("\nMemory deallocated Successfully.\n");
}

int main()
{
    int n;

    printf("Enter the number of elements to allocate memory: ");
    scanf("%d", &n);

    allocate_memory(n);
    display_memory(n);
    deallocate_memory();

    return 0;
}