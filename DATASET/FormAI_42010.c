//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Memory Management Show!\n");
    printf("We have an amazing program for you today, folks!\n");
  
    // Allocating memory for a string
    char *str = (char*) malloc(sizeof(char) * 10);
    if (str)
    {
        printf("Memory allocated successfully for the string!\n");
    }
    else
    {
        printf("Oops! Memory allocation failure for the string!\n");
    }
  
    // Allocating memory for an integer array
    int *arr = (int*) calloc(5, sizeof(int));
    if (arr)
    {
        printf("Memory allocated successfully for the integer array!\n");
    }
    else
    {
        printf("Oops! Memory allocation failure for the integer array!\n");
    }
  
    // Reallocating memory for the string
    str = (char*) realloc(str, sizeof(char) * 20);
    if (str)
    {
        printf("Memory reallocated successfully for the string!\n");
    }
    else
    {
        printf("Oops! Memory reallocation failure for the string!\n");
    }
  
    // Freeing memory allocated for the string
    free(str);
    printf("Memory freed successfully for the string!\n");
  
    // Freeing memory allocated for the integer array
    free(arr);
    printf("Memory freed successfully for the integer array!\n");
  
    printf("That's all for today, folks! Hope you had a great time at the Memory Management Show!\n");
  
    return 0;
}