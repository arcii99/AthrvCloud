//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(void) {
    char input[MAX_LEN];
    char sanitized_input[MAX_LEN];
    int i, j;
    int is_valid = 1;
    
    printf("Enter a string to sanitize:\n");
    fgets(input, MAX_LEN, stdin);
    
    // sanitize input
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (isalpha(input[i])) { 
            // if character is alphabetic, copy to sanitized_input as is
            sanitized_input[j] = input[i];
        } else if (isspace(input[i])) { 
            // if character is space, copy to sanitized_input as is
            sanitized_input[j] = input[i];
        } else {
            // if character is not alphabetic or space, skip it
            is_valid = 0;
            j--; // decrement j to account for skipped character
        }
    }
    
    if (is_valid) {
        printf("Sanitized input: %s\n", sanitized_input);
    } else {
        printf("Invalid input detected. Resanitizing...\n");
        main(); // restart program for resanitization
    }
    
    return 0;
}