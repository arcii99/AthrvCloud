//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <string.h>

const char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};
// Defines the morse code table, which stores the converted Morse symbols.

void print_morse_code(const char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            printf("  ");
        } else {
            printf("%s ", morse_code_table[s[i] - 'a']);
        }
    }
    printf("\n");
}
// Function to print the converted Morse code from the given text string.

int main() {
    printf("Welcome to the Brave C Morse Code Converter!\n");
    printf("Enter a text to convert: ");

    char input[100];
    fgets(input, sizeof(input), stdin);
    // Takes input from the user.

    printf("Input: %s", input);
    printf("Output: ");
    print_morse_code(input);

    printf("Thank you for using the Brave C Morse Code Converter!\n");
    return 0;
}
// The main function prompts the user to input the text and prints the converted
// Morse code by calling the print_morse_code function.