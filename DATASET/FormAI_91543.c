//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    char morse[26][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char code[1000] = "";
    printf("Enter your romantic message: \n");
    fgets(message, 100, stdin); // Reading the message

    for (int i = 0; i < strlen(message); i++) { // For every character in the message
        char character = message[i];
        if (character >= 'a' && character <= 'z') { // If the character is a letter
            strcat(code, morse[character - 97]); // Append the Morse code to the code string
            strcat(code, " "); // Add a space between characters
        }
        else if (character == ' ') { // If the character is a space
            strcat(code, "   "); // Add three spaces to represent a word gap
        }
    }

    printf("Your romantic message in Morse code is: \n%s", code); // Output the Morse code message

    return 0;
}