//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: happy
#include <stdio.h>
#include <string.h>

// Function declaration to convert character to Morse Code
char* convertToMorse(char character);

int main() {
    printf("Welcome to the Happy Text to Morse Code Converter!\n");
    printf("Please enter the text to convert to Morse Code:\n");
    
    // Taking user input as a string
    char text[100];
    fgets(text, 100, stdin);

    printf("\nOkay, Let's convert your text to Morse Code!\n\n");

    for (int i = 0; i < strlen(text); i++) {
        // Checking if the character is alphabetic or numeric
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0' && text[i] <= '9')) {
            // Calling the function to convert character to Morse Code and printing the result
            printf("%s ", convertToMorse(text[i]));
        } 
        else if (text[i] == ' ') {
            // Print a space for whitespace
            printf(" ");
        }
        else {
            // If the character is not a valid english alphabetic or numeric character, print an error message
            printf("Sorry, we cannot convert this character to Morse Code. Please try again with valid input.\n");
            return 1; // error code
        }
    }

    // Print a happy message once the conversion is complete
    printf("\n\nYay! Your text has been successfully converted to Morse Code!\n");

    return 0; // success code
}

// Function definition to convert character to Morse Code
char* convertToMorse(char character) {

    switch (character) {
        case 'a': case 'A':
            return ".-";
        case 'b': case 'B':
            return "-...";
        case 'c': case 'C':
            return "-.-.";
        case 'd': case 'D':
            return "-..";
        case 'e': case 'E':
            return ".";
        case 'f': case 'F':
            return "..-.";
        case 'g': case 'G':
            return "--.";
        case 'h': case 'H':
            return "....";
        case 'i': case 'I':
            return "..";
        case 'j': case 'J':
            return ".---";
        case 'k': case 'K':
            return "-.-";
        case 'l': case 'L':
            return ".-..";
        case 'm': case 'M':
            return "--";
        case 'n': case 'N':
            return "-.";
        case 'o': case 'O':
            return "---";
        case 'p': case 'P':
            return ".--.";
        case 'q': case 'Q':
            return "--.-";
        case 'r': case 'R':
            return ".-.";
        case 's': case 'S':
            return "...";
        case 't': case 'T':
            return "-";
        case 'u': case 'U':
            return "..-";
        case 'v': case 'V':
            return "...-";
        case 'w': case 'W':
            return ".--";
        case 'x': case 'X':
            return "-..-";
        case 'y': case 'Y':
            return "-.--";
        case 'z': case 'Z':
            return "--..";
        case '0':
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        default:
            return ""; // If character is not an English alphabet or numerical value return an empty string
    }
}