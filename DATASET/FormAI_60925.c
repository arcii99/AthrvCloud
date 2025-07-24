//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character at the end of string
    str[strcspn(str, "\n")] = 0;

    char *str_copy = (char *)malloc(strlen(str) + 1);
    strcpy(str_copy, str);

    // Make all characters uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    // Reverse the string
    reverse_string(str_copy);

    printf("Original string: %s\n", str_copy);
    printf("Uppercase string: %s\n", str);

    free(str_copy);
    return 0;
}