//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *str) {
    int i, j;
    char temp[strlen(str)+1];
    
    for (i = 0, j = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            temp[j++] = str[i];
        }
    }
    
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char input[100];
    
    printf("Enter a string to sanitize: ");
    scanf("%s", input);
    
    sanitize(input);
    
    printf("Sanitized string: %s\n", input);
    
    return 0;
}