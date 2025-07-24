//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define the Morse code lookup table
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};

int main() {
    char message[256]; // Create a string to hold the message to be converted to Morse code
    printf("Enter a message to convert to Morse code:\n");
    fgets(message, 256, stdin); // Use fgets to read the user input

    printf("Morse code version:\n");
    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]); // Convert the character to lowercase
        if (c > 96 && c < 123) { // Check if the character is a letter
            printf("%s ", morse_code[c-97]); // Print the corresponding Morse code sequence
        }
        else if (c == 32) { // Check if the character is a space
            printf(" ");
        }
        else { // If the character is not a letter or space, ignore it
            continue;
        }
    }
    printf("\n");
    return 0;
}