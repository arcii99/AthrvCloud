//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    int i;
    int num_vowels = 0, num_consonants = 0, num_spaces = 0, num_digits = 0;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            if (toupper(input[i]) == 'A' || toupper(input[i]) == 'E' || toupper(input[i]) == 'I'
                || toupper(input[i]) == 'O' || toupper(input[i]) == 'U') {
                num_vowels++;
            }
            else {
                num_consonants++;
            }
        }
        else if (isdigit(input[i])) {
            num_digits++;
        }
        else if (isspace(input[i])) {
            num_spaces++;
        }
    }

    printf("\nNumber of vowels: %d", num_vowels);
    printf("\nNumber of consonants: %d", num_consonants);
    printf("\nNumber of spaces: %d", num_spaces);
    printf("\nNumber of digits: %d", num_digits);

    return 0;
}