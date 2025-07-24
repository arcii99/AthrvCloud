//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress the input string
void compress(char* input_string, char* output_string) {
    int i = 0, j = 0;
    int count = 1, length = strlen(input_string);

    // Loop through the input string
    while (i < length) {
        // If the current character is same as the next one
        if (input_string[i] == input_string[i + 1]) {
            count++;
        } 
        // If the current character is not same as the next one
        else {
            // Add the current character to the output string
            output_string[j++] = input_string[i];

            // If the current character occurs more than once
            if (count > 1) {
                // Convert the count to a string and add it to the output string
                char count_str[MAX_SIZE];
                sprintf(count_str, "%d", count);
                strcat(output_string, count_str);
                j += strlen(count_str);
                count = 1;
            }
        }
        i++;
    }
    // Add null terminator to the output string
    output_string[j] = '\0';
}

int main() {
    char input_string[MAX_SIZE];
    char output_string[MAX_SIZE];
    printf("Enter string to be compressed: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // remove trailing newline character

    compress(input_string, output_string);

    printf("Compressed string: %s\n", output_string);

    return 0;
}