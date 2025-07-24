//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

void text_to_morse(const char *text) {
    int i, j;
    for(i = 0; i < strlen(text); i++) {
        // Convert to lowercase for simplicity
        char c = tolower(text[i]);
        if(c == ' ') {
            // Print a space when there is one in the text
            printf(" ");
        } else {
            // Look for the character in the alphabet
            for(j = 0; j < strlen(alphabet); j++) {
                if(alphabet[j] == c) {
                    // When found, print its Morse code representation
                    printf("%s ", morse_code[j]);
                    break;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Enter some text to convert to Morse code: ");
    fgets(input, 100, stdin);
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    text_to_morse(input);
    return 0;
}