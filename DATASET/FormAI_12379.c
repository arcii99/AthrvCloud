//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    char sanitized[100];
    int i = 0, j = 0;

    printf("Hello there! This is a user input sanitizer program.\n");
    printf("Please enter your text: \n");
    fgets(input, 100, stdin); // read user input

    while (input[i]) { // loop through each character in input
        if (isalpha(input[i])) { // if character is an alphabet
            sanitized[j] = tolower(input[i]); // convert to lowercase
            j++; // increment index of sanitized string
        } else if (isdigit(input[i])) { // if character is a digit
            sanitized[j] = input[i]; // copy digit as is
            j++; // increment index of sanitized string
        } // ignore special characters and whitespaces
        i++; // increment index of input string
    }

    sanitized[j] = '\0'; // terminate sanitized string
    printf("Here is your sanitized input: %s\n", sanitized);

    return 0;
}