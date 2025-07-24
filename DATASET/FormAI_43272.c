//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    printf("Please enter a string:\n");
    fgets(str, 50, stdin); // Read input line from user

    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Convert the string to uppercase
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }

    // Count the number of vowels in the string
    int vowelCount = 0;
    for (int i = 0; str[i]; i++) {
        switch(str[i]) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowelCount++;
                break;
            default:
                break;
        }
    }

    // Print out the final result
    printf("\nYour string converted to upper case: %s\n", str);
    printf("Number of vowels in your string: %d\n\n", vowelCount);

    return 0;
}