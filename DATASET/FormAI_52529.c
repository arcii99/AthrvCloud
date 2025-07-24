//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Welcome to the Textprocessor 3000!\n");
    printf("Please enter some text below:\n");

    // Allocate memory for input string
    char *input = malloc(sizeof(char) * 100);
    fgets(input, 100, stdin);

    // Remove newline character from input string
    int len = strlen(input);
    if (input[len-1] == '\n')
        input[len-1] = '\0';

    // Count the number of vowels in the input string
    int vowels = 0;
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels++;
    }

    // Replace all spaces in the input string with "_"
    for (int i = 0; i < len; i++) {
        if (input[i] == ' ')
            input[i] = '_';
    }

    // Capitalize the first letter of each word in the input string
    for (int i = 0; i < len; i++) {
        if (i == 0 || input[i-1] == ' ')
            input[i] = toupper(input[i]);
    }

    // Print the modified string and vowel count
    printf("Modified text: %s\n", input);
    printf("Vowels found: %d\n", vowels);

    // Free allocated memory
    free(input);

    return 0;
}