//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Morse Code character arrays
const char *abc[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
const char *nums[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

// Function to convert a single character to Morse code
void convertCharToMorse(char c) {
    // Check if character is alphabetical or numerical
    if (c >= 'a' && c <= 'z') {
        printf("%s ", abc[c - 'a']); // Print Morse code equivalent of alphabetical character
    } else if (c >= '0' && c <= '9') {
        printf("%s ", nums[c - '0']); // Print Morse code equivalent of numerical character
    } else if (c == ' ') {
        printf(" / "); // Print slash symbol for space
    } else {
        printf(" "); // Print blank space for unknown characters
    }
}

// Function to convert entire string to Morse code
void convertStringToMorse(char *str) {
    int len = strlen(str); // Get length of string
    for (int i = 0; i < len; i++) {
        convertCharToMorse(str[i]); // Convert each character to Morse code
    }
    printf("\n"); // Print new line after conversion
}

// Main function to take user input and call Morse code conversion function
int main() {
    char input[1000]; // Initialize character array to store user input
    printf("Enter text to be converted to Morse code: ");
    fgets(input, sizeof(input), stdin); // Get user input from console
    printf("Morse code output: ");
    convertStringToMorse(input); // Call Morse code conversion function
    return 0; // Return 0 to indicate successful program execution
}