//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void sanitizeInput(char *input) {
    int i;
    for(i=0;input[i]!=0;i++) {
        if(!isalnum(input[i])) {
            input[i] = '_';
        }
    }
}

int main() {
    printf("Enter a string to sanitize: ");
    char input[1000];
    scanf("%s",input);
    printf("Sanitized string: ");
    sanitizeInput(input);
    printf("%s\n",input);
    return 0;
}