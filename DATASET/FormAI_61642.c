//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    // Declare a character pointer to allocate memory
    char *ptr = NULL;

    // Use malloc to allocate memory dynamically
    ptr = (char*) malloc(MAX_SIZE * sizeof(char));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize the allocated memory with zeros
    for (int i = 0; i < MAX_SIZE; i++) {
        *(ptr + i) = 0;
    }

    // Prompt user to input a string
    printf("Enter a string: ");
    fgets(ptr, MAX_SIZE, stdin);

    // Display the input string
    printf("You entered: %s", ptr);

    // Modify the input string
    for (int i = 0; i < MAX_SIZE; i++) {
        *(ptr + i) = *(ptr + i) + 1;
    }

    // Display the modified string
    printf("After modification: %s", ptr);

    // Use free function to deallocate the allocated memory
    free(ptr);

    return 0;
}