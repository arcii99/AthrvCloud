//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

/*
This program is a simple example of an Alien Language Translator 
for the C language. It uses a custom Alien language made up of 
only two characters: 'X' and 'O'.

The translator works by taking in a string of characters from the 
user, and then replacing all instances of 'X' with 'O' and vice versa.

For example, the string "OXXO" would be translated to "XOOX".

*/

// Function to translate the Alien language string
void translate(char* string) {
    int length = strlen(string);

    // Loop through every character in the string
    for(int i=0; i<length; i++) {
        // If the character is 'X', replace with 'O'
        if(string[i] == 'X') {
            string[i] = 'O';
        }
        // If the character is 'O', replace with 'X'
        else if(string[i] == 'O') {
            string[i] = 'X';
        }
    }
}

int main() {
    // Prompt the user to enter a string to translate
    printf("Enter an Alien language string to translate:\n");

    // Create a buffer to hold the user input
    char buffer[256];

    // Read the user input and store it in the buffer
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the newline character from the end of the string
    buffer[strcspn(buffer, "\n")] = 0;

    // Translate the Alien language string
    translate(buffer);

    // Print the translated string to the console
    printf("Translated string: %s\n", buffer);

    return 0;
}