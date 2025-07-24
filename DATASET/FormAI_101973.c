//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
/* 
This program demonstrates how to dynamically allocate and free memory in C using the memory management functions malloc() and free(). 

The program prompts the user to enter the number of integers they want to input, dynamically allocates the required amount of memory using malloc(), reads in the integers, calculates their sum and average, and then frees the allocated memory using free().
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    float avg;
  
    printf("How many integers do you want to input? ");
    scanf("%d", &n);
  
    // Dynamically allocate memory for n integers
    int *nums = (int*) malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if(nums == NULL)
    {
        printf("Error allocating memory!");
        exit(1);
    }
    
    // Read in the integers
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", (nums + i));
        sum += *(nums + i);
    }
    
    // Calculate average
    avg = (float) sum / n;
    
    // Print sum and average
    printf("The sum of the integers is %d\n", sum);
    printf("The average of the integers is %f\n", avg);
    
    // Free the allocated memory
    free(nums);
    
    return 0;
}