//FormAI DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare and allocate memory for variable
    char* my_str = malloc(6);
    
    // Check if allocation was successful
    if (my_str == NULL) {
        printf("Oh cruel fate, my memory allocation has failed!\n");
        return 1;
    }
    
    // Store a string in the allocated memory
    my_str[0] = 'R';
    my_str[1] = 'o';
    my_str[2] = 'm';
    my_str[3] = 'e';
    my_str[4] = 'o';
    my_str[5] = '\0';
    
    // Display the result
    printf("My dear Juliet, thy memory has been allocated successfully:\n");
    printf("%s\n", my_str);
    
    // Deallocate the memory
    free(my_str);
    
    // Show the program's gratitude
    printf("My sweet Juliet, thy memory has been released and all is well.\n");
    
    return 0;
}