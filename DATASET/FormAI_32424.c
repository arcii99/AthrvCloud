//FormAI DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input_string[MAX_LEN];
    int word_count = 1, char_count = 0, i;

    printf("Enter a sentence: ");
    fgets(input_string, MAX_LEN, stdin); // Read input string

    // Count the number of words and characters in the input string
    for (i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == ' ' || input_string[i] == '\n' || input_string[i] == '\t') {
            word_count++; // Increment the word count
        } else {
            char_count++; // Increment the character count
        }
    }

    // Output the results
    printf("The input string you entered is:\n%s\n", input_string);
    printf("The number of words in the input string is: %d\n", word_count);
    printf("The number of characters in the input string is: %d\n", char_count);

    return 0;
}