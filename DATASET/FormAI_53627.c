//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
// Welcome! This program is a funky Morse code converter!
// Let's start by including the necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Now let's define our Morse code dictionary.
char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// We also need a function to convert our input string into uppercase.
void toUpperCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Time for the main function!
int main() {

    // First we need to declare our strings to hold the input and output.
    char input[80];
    char output[2000];
    memset(output, 0, sizeof(output)); // We need to initialize the output string to avoid garbage values.

    // Now let's get some user input!
    printf("Hello there! Please enter the text you would like to convert to Morse code: ");
    fgets(input, 80, stdin);

    // We need to remove the newline character from the input string.
    input[strcspn(input, "\n")] = 0;

    // Let's convert the input string to uppercase.
    toUpperCase(input);

    // Finally, we can iterate through the input string and convert each character to Morse code.
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            strcat(output, "/"); // If the character is a space, we append a slash to indicate word separation.
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            strcat(output, morseCode[input[i] - 'A']); // If the character is a letter, we use our Morse code dictionary.
            strcat(output, " ");
        } else {
            strcat(output, "? "); // If the character is not a letter or a space, we append a question mark as a placeholder.
        }
    }

    // Time to output the results!
    printf("\nHere is your Morse code: %s\n", output);

    // And finally, we return 0 to indicate successful execution of the program.
    return 0;
}