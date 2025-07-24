//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Morse code mapping
char *mapping[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", 
    "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

// Function to convert a character to its Morse code equivalent
char *to_morse_code(char c) {
    if (c == ' ') {
        return "/";
    }
    if (c >= 'a' && c <= 'z') {
        return mapping[c - 'a'];
    }
    if (c >= 'A' && c <= 'Z') {
        return mapping[c - 'A'];
    }
    return NULL;
}

// MAIN FUNCTION
int main() {
    char input[100]; // Input string
    char output[1000]; // Output Morse code string
    int i, j;

    printf("Enter a string to convert to Morse code: ");
    fgets(input, 100, stdin);

    // Convert each character in the input string to Morse code
    for (i = 0, j = 0; i < strlen(input); i++) {
        char *code = to_morse_code(input[i]);
        if (code != NULL) {
            // Append the Morse code to the output string
            strcat(output, code);
            strcat(output, " "); // Add a space after each symbol
            j += strlen(code) + 1;
        }
    }

    // Print the input and output strings
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    return 0;
}