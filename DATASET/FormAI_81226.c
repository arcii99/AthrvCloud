//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_char(char*, char);

int main() {
    char input[50];
    char remove;
    printf("Enter a string: ");
    fgets(input, 50, stdin);
    printf("Enter a character to remove: ");
    scanf("%c", &remove);
    remove_char(input, remove);
    printf("Result: %s", input);
    return 0;
}

void remove_char(char* str, char c) {
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != c) {
            str[k] = str[i];
            k++;
        }
    }
    str[k] = '\0';
}