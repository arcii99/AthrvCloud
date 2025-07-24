//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

int main() {
    char string[MAX_STRING_LENGTH];

    printf("Please enter a string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    // Count the number of words in the string
    int word_count = 1;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isspace(string[i])) {
            word_count++;
        }
    }

    printf("The number of words in the string is: %d\n", word_count);

    // Convert the string to all uppercase
    for (int i = 0; string[i] != '\0'; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }

    printf("The string in all uppercase is: %s", string);

    // Reverse the string
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }

    char reversed_string[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        reversed_string[j] = string[i];
    }

    printf("The reversed string is: %s", reversed_string);

    return 0;
}