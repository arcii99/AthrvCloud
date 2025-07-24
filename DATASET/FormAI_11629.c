//FormAI DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define variables to hold user input and processing result
    char input[1000];
    char result[1000];
       
    // Ask user for input string
    printf("Enter a string: ");
    fgets(input, 1000, stdin);
    
    // Convert input string to lowercase
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            result[i] = input[i] + 32;
        }
        else {
            result[i] = input[i];
        }
    }
    
    // Remove spaces from processed string
    int j = 0;
    for(int i = 0; i < strlen(result); i++) {
        if(result[i] != ' ') {
            result[j++] = result[i];
        }
    }
    result[j] = '\0'; // Terminate the result string with null character
    
    // Find length of processed string
    int length = strlen(result);
    
    // Print out the processed string and its length
    printf("\nProcessed string: %s\n", result);
    printf("Length of processed string: %d\n", length);
    
    return 0;
}