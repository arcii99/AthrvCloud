//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_string[1000];
    int frequency[26] = {0};
    int i, index, length;

    printf("Enter a string (max 1000 characters): ");
    fgets(input_string, 1000, stdin);
    length = strlen(input_string);

    // Loop through input string
    for (i = 0; i < length; i++) {
        // Convert character to uppercase
        input_string[i] = toupper(input_string[i]);

        // Check if character is a letter of the alphabet
        if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
            // Get index in frequency array
            index = input_string[i] - 'A';

            // Increment frequency of letter in frequency array
            frequency[index]++;
        }
    }

    // Print frequency of each letter
    printf("Letter frequencies:\n");
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, frequency[i]);
    }

    return 0;
}