//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
// Morse Code conversion example program
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code definitions
const char *morse_chars[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", 
                            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
                            ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                            ".--", "-..-", "-.--", "--.."};

// Function to convert a single character to Morse code
void char_to_morse(char c) {
    int index;
    if (isalpha(c)) {
        index = tolower(c) - 'a';
    } else if (isdigit(c)) {
        index = c - '0' + 26;
    } else {
        return; // Ignore non-alphanumeric characters
    }
    printf("%s ", morse_chars[index]);
}

// Function to convert a string to Morse code
void text_to_morse(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        char_to_morse(text[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char text[50];
    while (1) {
        printf("Enter a string to convert to Morse code (or q to quit): ");
        scanf("%s", text);
        if (strcmp(text, "q") == 0) {
            break;
        }
        text_to_morse(text);
    }
    return 0;
}