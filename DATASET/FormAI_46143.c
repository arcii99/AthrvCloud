//FormAI DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to compress the input string
void compress(char* input_string, char* output_string) {
    int count, i, j, k;
    char current_char, count_char[10];

    // Loop over all characters in the input string
    for (i = 0, j = 0; input_string[i] != '\0'; i++) {
        current_char = input_string[i];
        count = 1;

        // Count the number of consecutive occurences of the current character
        while (input_string[i + 1] == current_char) {
            count++;
            i++;
        }

        // Store the compressed substring in the output string
        output_string[j++] = current_char;
        sprintf(count_char, "%d", count);
        for (k = 0; count_char[k] != '\0'; k++, j++) {
            output_string[j] = count_char[k];
        }
    }

    // Null terminate the output string
    output_string[j] = '\0';
}

int main() {
    char input_string[100], output_string[100];

    // Accept input from the user
    printf("Enter an input string to compress: ");
    fgets(input_string, 100, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    // Compress the input string and print the output
    compress(input_string, output_string);
    printf("Compressed string: %s\n", output_string);

    return 0;
}