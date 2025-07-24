//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char str[MAX_STRING_LENGTH];
    printf("Enter a string:\n");
    fgets(str, MAX_STRING_LENGTH, stdin);

    // Remove trailing newline character if present
    int str_len = strlen(str);
    if (str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }

    // Convert the string to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;  // Subtract 32 to convert to uppercase
        }
    }

    // Remove all vowels from the string
    char final_str[MAX_STRING_LENGTH];
    int final_index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            final_str[final_index++] = str[i];
        }
    }
    final_str[final_index] = '\0';

    printf("The final string is: %s\n", final_str);
    return 0;
}