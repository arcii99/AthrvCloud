//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

// Function to convert text to Morse code
void convert_to_morse(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') {
            // Add a space between words
            printf(" ");
        } else {
            int index;
            if (text[i] >= 'a' && text[i] <= 'z') {
                // Convert lowercase letters to uppercase
                index = text[i] - 'a';
                index += 'A' - 'a';
            } else {
                // Index of other characters
                index = text[i] - '0' + 26;
            }
            printf("%s", morse_table[index]);
            printf(" ");
        }
    }
}

// Main function
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);

    // Paranoid code to prevent buffer overflow attacks
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == '\n') {
            // Replace newline with null terminator
            text[i] = '\0';
        }
    }

    printf("Morse code: ");
    convert_to_morse(text);

    return 0;
}