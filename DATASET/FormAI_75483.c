//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given character is a digit or not
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to count the number of digits in a given string
int countDigits(char *s) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isDigit(s[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char input[100];

    // Get the input string from the user
    printf("Enter a string: ");
    scanf("%s", input);

    // Count the number of digits in the string
    int numDigits = countDigits(input);

    // Print the output
    printf("The string '%s' contains %d digits.\n", input, numDigits);

    return 0;
}