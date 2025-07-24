//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Input sanitizer function
void input_sanitizer(char* str) {
    int i = 0, j = 0;
    while(str[i]) {
        if(isalnum(str[i])) {
            str[j] = str[i];
            j++;
        } 
        i++;
    }
    str[j] = '\0';
}

// Main Function
int main() {
    // User input variable declaration
    char input_string[100];
    
    // User Input Prompt
    printf("Enter a string: ");
    scanf("%[^\n]%*c", input_string);
    
    // Sanitize User Input
    input_sanitizer(input_string);
    
    // Output the sanitized string
    printf("Sanitized String: %s\n", input_string);
    
    return 0;
}