//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    printf("Enter input to sanitize: ");
    fgets(input, sizeof(input), stdin);
    
    char sanitizedInput[100];
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9') ||
            input[i] == ' ' || input[i] == '\n') {
            sanitizedInput[j] = input[i];
            j++;
        }
    }
    sanitizedInput[j] = '\0';
    
    printf("\nSanitized Input: %s", sanitizedInput);
    return 0;
}