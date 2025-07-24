//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Memory Management Example Program!\n");
    printf("Here, we will demonstrate how to allocate, use, and deallocate memory in C!\n\n");
    
    // Allocating memory for a string with 10 characters
    char *str = (char*) malloc(10 * sizeof(char));
    if (str == NULL) {
        printf("Error: Failed to allocate memory!\n");
        return 1;
    }

    printf("Enter a string (up to 10 characters): ");
    scanf("%s", str);

    printf("The string you entered is: %s\n", str);
    
    // Reallocating memory for the string with 20 characters
    str = (char*) realloc(str, 20 * sizeof(char));
    if (str == NULL) {
        printf("Error: Failed to reallocate memory!\n");
        return 1;
    }

    printf("Enter a string (up to 20 characters): ");
    scanf("%s", str);

    printf("The string you entered is: %s\n", str);

    // Deallocating memory for the string
    free(str);
    
    printf("Memory deallocated! Thank you for using this program.\n");
    return 0;
}