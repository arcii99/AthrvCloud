//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to encode a string with a watermark
void encode_string(char input_string[], char watermark[]) {
    // Get the length of the input string
    int string_length = strlen(input_string);
    // Get the length of the watermark
    int watermark_length = strlen(watermark);

    // Loop through each character in the input string
    for (int i = 0; i < string_length; i++) {
        // Get the ASCII value of the current character
        int ascii_value = input_string[i];

        // Loop through each character in the watermark
        for (int j = 0; j < watermark_length; j++) {
            // Get the ASCII value of the current watermark character
            int watermark_ascii_value = watermark[j];

            // Add the ASCII values of the input string and watermark characters
            ascii_value += watermark_ascii_value;

            // Ensure the ASCII value is still within the printable range
            ascii_value = ascii_value % 127 + 32;
        }

        // Assign the new ASCII value to the current character in the input string
        input_string[i] = (char)ascii_value;
    }
}

// Function to decode a string with a watermark
void decode_string(char input_string[], char watermark[]) {
    // Get the length of the input string
    int string_length = strlen(input_string);
    // Get the length of the watermark
    int watermark_length = strlen(watermark);

    // Loop through each character in the input string
    for (int i = 0; i < string_length; i++) {
        // Get the ASCII value of the current character
        int ascii_value = input_string[i];

        // Loop through each character in the watermark
        for (int j = 0; j < watermark_length; j++) {
            // Get the ASCII value of the current watermark character
            int watermark_ascii_value = watermark[j];

            // Subtract the ASCII values of the input string and watermark characters
            ascii_value -= watermark_ascii_value;

            // Ensure the ASCII value is still within the printable range
            if (ascii_value < 32) {
                ascii_value += 95;
            }
        }

        // Assign the new ASCII value to the current character in the input string
        input_string[i] = (char)ascii_value;
    }
}

int main() {
    // Define the input string and watermark
    char input_string[] = "Hello world!";
    char watermark[] = "watermark";

    // Encode the input string with the watermark
    encode_string(input_string, watermark);

    // Print the encoded string
    printf("Encoded string: %s\n", input_string);

    // Decode the input string with the watermark
    decode_string(input_string, watermark);

    // Print the decoded string
    printf("Decoded string: %s\n", input_string);

    return 0;
}