//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {

    // Prompt the user to enter a sentence
    printf("Please enter a sentence: ");

    // Read the user input into a character array called 'input'
    char input[100];
    fgets(input, 100, stdin);

    // Remove the newline character from the end of the input
    input[strcspn(input, "\n")] = 0;

    // Print the input in lowercase
    printf("Input in lowercase: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%c", tolower(input[i]));
    }
    printf("\n");

    // Print the input in uppercase
    printf("Input in uppercase: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%c", toupper(input[i]));
    }
    printf("\n");

    // Count the number of vowels in the input
    int vowels = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            vowels++;
        }
    }
    printf("Number of vowels in input: %d\n", vowels);

    // Reverse the input
    printf("Input in reverse: ");
    for (int i = strlen(input) - 1; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}