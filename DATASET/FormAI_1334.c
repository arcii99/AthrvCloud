//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char output[100] = "";
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Remove vowels from the input string
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u') {
            strncat(output, &input[i], 1);
        }
    }

    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);

    // Count the number of words in the input string
    int num_words = 1;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_words++;
        }
    }

    printf("Number of words in input string: %d\n", num_words);

    // Reverse the input string
    char reversed[100] = "";
    for (int i = strlen(input) - 2; i >= 0; i--) {
        strncat(reversed, &input[i], 1);
    }

    printf("Reversed input string: %s\n", reversed);

    return 0;
}