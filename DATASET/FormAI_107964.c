//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], sanitizedInput[100];
    int i, j;
    printf("Please enter your input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
    for(i = 0, j = 0; i < strlen(input); i++) {
        if(input[i] != '&' && input[i] != '<' && input[i] != '>') {
            sanitizedInput[j] = input[i];
            j++;
        }
    }
    printf("Your sanitized input is: %s\n", sanitizedInput);
    return 0;
}