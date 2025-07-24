//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *str) {
    int i, j = 0;
    char ch;

    for (i = 0; str[i]!='\0'; i++) {
        ch = str[i];
        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            str[j] = ch;
            j++;
        }
    }
    str[j] = '\0';
}

int main() {
    char input[100];
    
    printf("Enter your input: ");
    scanf("%[^\n]", input);

    sanitize(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}