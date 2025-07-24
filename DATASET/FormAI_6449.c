//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], output[100];
    int i, j;
    
    printf("Enter a string: ");
    fgets(input, 100, stdin);  // Read input string from user
    
    j = 0;  // Initialize output string index to 0
    
    // Loop through each character in input string
    for (i = 0; i < strlen(input); i++) {
        if (!ispunct(input[i])) {  // Check if character is not a punctuation mark
            output[j++] = tolower(input[i]);  // Convert character to lowercase and add it to output string
        }
    }
    
    output[j] = '\0';  // Add null character to terminate output string
    
    printf("Processed string: %s\n", output);  // Print processed string
    
    return 0;
}