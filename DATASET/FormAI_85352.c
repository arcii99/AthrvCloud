//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the length of the input string
#define MAX_LENGTH 1000

// Function to calculate the binomial coefficient of two numbers
int binomial(int n, int k)
{
    if (n == k || k == 0) {
        return 1;
    } else {
        return binomial(n - 1, k - 1) + binomial(n - 1, k);
    }
}

// Function to compress the input string using our custom algorithm
void compress(char* input)
{
    int length = strlen(input);
    char compressed[MAX_LENGTH];
    memset(compressed, '\0', sizeof(compressed));

    // Iterate through each character in the input string
    for (int i = 0; i < length; i++) {
        // Get the ASCII code of this character
        int ascii_code = (int)input[i];
        // Calculate the binomial coefficient of this code and 5
        int coefficient = binomial(ascii_code, 5);
        // Add the coefficient to the compressed string
        compressed[i] = (char)coefficient;
    }

    // Print the compressed string to the console
    printf("Compressed string: %s\n", compressed);
}

// Function to decompress the input string using our custom algorithm
void decompress(char* input)
{
    int length = strlen(input);
    char decompressed[MAX_LENGTH];
    memset(decompressed, '\0', sizeof(decompressed));

    // Iterate through each character in the input string
    for (int i = 0; i < length; i++) {
        // Get the coefficient from the input string
        int coefficient = (int)input[i];
        // Calculate the ASCII code using the binomial inverse of 5 and the coefficient
        int ascii_code = 10;
        while (binomial(ascii_code, 5) != coefficient) {
            ascii_code++;
        }
        // Add the ASCII code as a character to the decompressed string
        decompressed[i] = (char)ascii_code;
    }

    // Print the decompressed string to the console
    printf("Decompressed string: %s\n", decompressed);
}

int main()
{
    // Prompt the user for an input string to compress and decompress
    char input[MAX_LENGTH];
    printf("Enter a string to compress and decompress: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the end of the input string
    input[strcspn(input, "\n")] = '\0';

    // Compress and decompress the input string
    compress(input);
    decompress(input);

    return 0;
}