//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char string[100];

    // Get string input from user
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove newline character from input
    string[strcspn(string, "\n")] = 0;

    // Reverse the string
    reverse_string(string);

    printf("The reversed string is: %s\n", string);

    // Extract the first word from the string
    char first_word[50];
    sscanf(string, "%s", first_word);
    printf("The first word in the string is: %s\n", first_word);

    return 0;
}