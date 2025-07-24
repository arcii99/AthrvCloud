//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    printf("Welcome to the Surrealist User Input Sanitizer!\n");
    printf("Please enter a string to be sanitized: \n");

    char input[100];
    fgets(input, sizeof(input), stdin);    // read in user input

    int n = strlen(input);
    for (int i = 0; i < n; i++) {
        char c = input[i];
        if (isalpha(c)) {
            int rand_num = rand() % 26;    // generate random number between 0 - 25 inclusive
            if (isupper(c)) {
                input[i] = rand_num + 65;    // map random number to uppercase ASCII code
            } else {
                input[i] = rand_num + 97;    // map random number to lowercase ASCII code
            }
        } else if (isdigit(c)) {
            input[i] = '*';    // replace digits with asterisks
        } else {
            input[i] = ' ';    // replace non-letter, non-digit characters with spaces
        }
    }
    
    printf("Sanitized string: %s\n", input);

    return 0;
}