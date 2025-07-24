//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Define a function that converts text to Morse code
void textToMorse(char text[]) {
    // Define the Morse code equivalents for each letter
    char* morseAlphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    // Loop through each character in the text string
    for (int i = 0; i <= strlen(text); i++) {
        // Convert the current character to uppercase
        char character = toupper(text[i]);
        // Check if the character is a letter
        if (character >= 'A' && character <= 'Z') {
            // Get the index of the character in the Morse code array
            int index = character - 'A';
            // Print the Morse code equivalent to the console
            printf("%s ", morseAlphabet[index]);
        } else if (character == ' ') {
            // Print a space to indicate a space between words
            printf(" ");
        } else if (character == '\0') {
            // Print a newline to end the conversion
            printf("\n");
        } else {
            // If the character is not a letter or space, print an error message
            printf("ERROR: Invalid input\n");
            // Exit the function
            return;
        }
    }
}

// Main function that prompts the user for input and calls the textToMorse function
int main() {
    // Define a variable to store the user's input
    char text[100];
    // Prompt the user for input
    printf("Enter text to convert to Morse code: ");
    // Get the user's input and store it in the text variable
    fgets(text, sizeof(text), stdin);
    // Call the textToMorse function with the user's input as the argument
    textToMorse(text);
    // Exit the main function
    return 0;
}