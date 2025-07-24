//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Global lookup table for Morse code conversions
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--.."
};

// Function to convert a single character to Morse code
void convert_char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        printf("%s ", morse_table[c - 'A']);
    } else if (c >= 'a' && c <= 'z') {
        printf("%s ", morse_table[c - 'a']);
    } else if (c >= '0' && c <= '9') {
        printf("%s ", morse_table[c - '0' + 25]);
    } else if (c == ' ') {
        printf("/ ");
    }
}

// Function to convert an entire string to Morse code
void convert_string_to_morse(char *string) {
    int i;
    int len = strlen(string);

    for (i = 0; i < len; i++) {
        convert_char_to_morse(string[i]);
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string to convert to Morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("Morse code conversion:\n");
    convert_string_to_morse(input);
    printf("\n");

    return 0;
}