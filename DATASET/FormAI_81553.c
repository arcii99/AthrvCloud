//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include<stdio.h>
#include<string.h>

void sanitizeInput(char* input) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        if(input[i] == '<' || input[i] == '>') {
            input[i] = '|';
        }
    }
}

int main() {
    char input[50];
    printf("Enter your input: ");
    fgets(input, 50, stdin);

    printf("Your sanitized input is: ");
    sanitizeInput(input);
    printf("%s", input);

    return 0;
}