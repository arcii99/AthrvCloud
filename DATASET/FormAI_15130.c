//FormAI DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];
    char output[2*MAX_LENGTH]; // Output can be double the max length of input

    if (argc != 2) { // Expect exactly one argument (the input string)
        printf("USAGE: %s <input_string>\n", argv[0]);
        return 1; // Exit with non-zero status
    }

    const char *input_str = argv[1];
    const int input_length = strlen(input_str);
    if (input_length > MAX_LENGTH) { // Ensure input string isn't too long
        printf("Input string must be at most %d characters in length\n", MAX_LENGTH);
        return 1;
    }

    // Perform string manipulation
    int i, j;
    for (i = 0, j = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == ' ') { // Replace spaces with underscores
            output[j] = '_';
        } else if (input_str[i] >= 'a' && input_str[i] <= 'z') { // Convert lowercase letters to uppercase
            output[j] = input_str[i] - ('a' - 'A');
        } else { // Leave all other characters as is
            output[j] = input_str[i];
        }
        j++;
    }
    output[j] = '\0'; // Terminate the output string

    printf("Input: %s\nOutput: %s\n", input_str, output);
    return 0; // Exit with success status
}