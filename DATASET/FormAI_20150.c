//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *str) {
    int i, j;
    char temp[strlen(str)];

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            temp[j++] = str[i];
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char input[100];

    printf("Enter some input: ");
    fgets(input, 100, stdin);

    printf("User input before sanitization: %s\n", input);

    sanitize(input);

    printf("User input after sanitization: %s\n", input);

    return 0;
}