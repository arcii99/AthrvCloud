//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

// Function to generate random numbers
void generate_random_numbers(int* array)
{
    srand(time(NULL));
    for(int i=0; i<SIZE; i++)
    {
        array[i] = rand() % 1000000 + 1;
    }
}

// Function to print the array
void print_array(int* array)
{
    printf("Array: ");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to do the performance-critical task
void perform_task(int* array)
{
    int sum = 0;
    for(int i=0; i<SIZE; i++)
    {
        sum += array[i];
    }
    printf("Sum: %d\n", sum);
}

int main()
{
    int array[SIZE];
    
    // Generate random numbers
    generate_random_numbers(array);
    
    // Print the array
    print_array(array);
    
    // Perform the performance-critical task
    perform_task(array);
    
    return 0;
}