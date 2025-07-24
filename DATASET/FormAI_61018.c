//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void capitalize(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);

    capitalize(str);

    printf("Capitalized string: %s", str);

    return 0;
}