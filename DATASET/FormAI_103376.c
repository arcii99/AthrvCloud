//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

// Function to convert text to morse code
void text_to_morse(char *text, char *morse) {
    // Define morse code table
    char *morse_table[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        // If character is a letter
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Convert letter to uppercase
            if (c >= 'a' && c <= 'z') {
                c -= 32;
            }
            // Find index of letter in alphabet
            int index = c - 'A';
            // Copy corresponding morse code to the output string
            strcpy(morse + strlen(morse), morse_table[index]);
            // Add a space between letters
            strcpy(morse + strlen(morse), " ");
        }
        // If character is a digit
        else if (c >= '0' && c <= '9') {
            // Find index of digit in table
            int index = c - '0';
            // Copy corresponding morse code to the output string
            strcpy(morse + strlen(morse), morse_table[index + 25]);
            // Add a space between digits
            strcpy(morse + strlen(morse), " ");
        }
        // If character is a space
        else if (c == ' ') {
            // Add a slash to the output string to represent a space
            strcpy(morse + strlen(morse), "/ ");
        }
        // If character is none of the above
        else {
            // Add a question mark to the output string to indicate invalid input
            strcpy(morse + strlen(morse), "? ");
        }
    }
}

int main() {
    // Test the text_to_morse function
    char text[] = "HELLO WORLD";
    char morse[100] = {0};
    text_to_morse(text, morse);
    printf("%s", morse);
    // Expected output: ".... . .-.. .-.. --- / .-- --- .-. .-.. -.."
    return 0;
}