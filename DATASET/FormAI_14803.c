//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>

// Function to perform introspective compression
void introspective_compression(char* original_string, char* compressed_string) {

    // Initialize variables
    int count = 1;
    char current_char = original_string[0];

    // Loop through each character in the original string
    for (int i = 1; original_string[i] != '\0'; i++) {

        // If the current character is the same as the previous one, increment count
        if (original_string[i] == current_char) {
            count++;
        }

        // If the current character is different than the previous one, add it to the compressed string with the count
        else {
            compressed_string += sprintf(compressed_string, "%c%d", current_char, count);
            current_char = original_string[i];
            count = 1;
        }
    }

    // Add the last character to the compressed string with the count
    compressed_string += sprintf(compressed_string, "%c%d", current_char, count);
}

int main() {

    // Initialize original and compressed strings
    char original[] = "hello world!";
    char compressed[50];

    // Call the introspective compression function with the original and compressed strings as arguments
    introspective_compression(original, compressed);

    // Print the original and compressed strings
    printf("Original string: %s\n", original);
    printf("Compressed string: %s\n", compressed);

    return 0;
}