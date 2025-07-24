//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100]; // Declare a character array to store user input
    printf("Please enter a word or phrase:\n");
    fgets(input, sizeof(input), stdin); // Get user input using fgets
    input[strcspn(input, "\n")] = 0; // Remove newline character from the input

    // Convert input to uppercase
    char upperInput[100] = "";
    int i = 0;
    while (input[i]) {
        upperInput[i] = toupper(input[i]);
        i++;
    }

    // Count the number of vowels in input
    int vowelCount = 0;
    char vowels[] = "AEIOU";
    for (i = 0; i < strlen(input); i++) {
        char currentChar = toupper(input[i]);
        if (strchr(vowels, currentChar) != NULL) {
            vowelCount++;
        }
    }

    // Reverse input
    char reversedInput[100] = "";
    for (i = strlen(input) - 1; i >= 0; i--) {
        reversedInput[strlen(input) - 1 - i] = input[i];
    }

    // Count the number of non-letter characters in input
    int nonLetterCount = 0;
    for (i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            nonLetterCount++;
        }
    }

    printf("Original input: %s\n", input);
    printf("Uppercase input: %s\n", upperInput);
    printf("Number of vowels in input: %d\n", vowelCount);
    printf("Reversed input: %s\n", reversedInput);
    printf("Number of non-letter characters in input: %d\n", nonLetterCount);

    return 0;
}