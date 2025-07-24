//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    for(int i = 0; input[i] != '\0'; i++) {
        // Convert uppercase characters to lowercase
        if(isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
        
        // Remove white space
        if(isspace(input[i])) {
            for(int j = i; input[j] != '\0'; j++) {
                input[j] = input[j+1];
            }
            i--;
        }
    }
    
    // Remove trailing newline character
    int len = strlen(input);
    if(len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    
    printf("The sanitized input is: %s\n", input);
    
    return 0;
}