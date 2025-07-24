//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    char sanitized[100];
    int i, j;

    printf("Please enter input: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove newline character from input
    
    // sanitize input
    j = 0;
    for(i = 0; i < strlen(input); i++) {
        if(isalpha(input[i])) {
            sanitized[j] = toupper(input[i]);
            j++;
        }
    }
    
    sanitized[j] = '\0';  // add null terminator to sanitized string
    
    printf("Sanitized input: %s\n", sanitized);
    
    return 0;
}