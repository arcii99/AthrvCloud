//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the alien language
char* ALPHABET[] = {
    "10101010", // A
    "01100110", // B
    "01010101", // C
    "10011001", // D
    "11000011", // E
    "11110000", // F
    "00001111", // G
    "11111111", // H
    "00000000", // I
    "10111100", // J
    "00110011", // K
    "01001100", // L
    "10110101", // M
    "01001010", // N
    "10100001", // O
    "00111100", // P
    "11010101", // Q
    "01111011", // R
    "11100001", // S
    "00110000", // T
    "01111100", // U
    "10101001", // V
    "01010110", // W
    "10011010", // X
    "11000001", // Y
    "11110011"  // Z
};

// Define the conversion function
char* alien_to_english(char* input) {
    // Determine length of input
    int input_len = strlen(input);
    
    // Allocate space for output
    char* output = malloc(sizeof(char) * ((input_len/8) + 1));
    
    // Iterate through input
    for (int i = 0; i < input_len; i+=8) {
        // Extract 8-bit segment of input
        char segment[9];
        strncpy(segment, input + i, 8);
        segment[8] = '\0';
        
        // Translate segment to English
        char letter = ' ';
        for (int j = 0; j < 26; j++) {
            if (strcmp(segment, ALPHABET[j]) == 0) {
                letter = 'A' + j;
                break;
            }
        }
        
        // Append letter to output string
        strncat(output, &letter, 1);
    }
    
    // Return output
    return output;
}

// Define the main program
int main() {
    // Prompt user for input
    printf("Enter Alien Language message: ");
    char input[256];
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0;
    
    // Convert input to English
    char* output = alien_to_english(input);
    
    // Print output
    printf("Translation: %s\n", output);
    
    // Free allocated memory
    free(output);
    
    return 0;
}