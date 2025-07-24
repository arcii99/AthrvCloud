//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

void textToMorseCode(char message[], char morseCode[MAX_MESSAGE_LENGTH*4]);

int main(void)
{
    printf("Welcome to the Medieval Text to Morse code converter!\n");
    printf("Enter your message to convert to Morse Code (max length 100 characters):\n");

    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove newline character from end of message
    message[strcspn(message, "\n")] = '\0';

    char morseCode[MAX_MESSAGE_LENGTH*4];
    textToMorseCode(message, morseCode);

    printf("\nYour message in Morse Code is:\n");
    printf("%s\n", morseCode);

    printf("\nThank you for using the converter!\n");

    // Return success
    return EXIT_SUCCESS;
}

void textToMorseCode(char message[], char morseCode[MAX_MESSAGE_LENGTH*4])
{
    // Define morse code lookup table in medieval style
    const char *morseCodeLookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ,.:;'?-!/()\"=+@";

    const char *medievalMorseCode[] = {
        "._",   // A
        "_...", // B
        "_._.", // C
        "_..",  // D
        ".",    // E
        ".._.", // F
        "__.",  // G
        "....", // H
        "..",   // I
        ".___", // J
        "_._",  // K
        "._..", // L
        "__",   // M
        "_.",   // N
        "___",  // O
        ".__.", // P
        "__._", // Q
        "._.",  // R
        "...",  // S
        "_",    // T
        ".._",  // U
        "..._", // V
        ".__",  // W
        "_.._", // X
        "_.__", // Y
        "__..", // Z
        ".____",    // 1
        "..___",    // 2
        "...__",    // 3
        "...._",    // 4
        ".....",    // 5
        "_....",    // 6
        "__...",    // 7
        "___..",    // 8
        "____.",    // 9
        "_____",    // 0
        "|",        // Space
        "_._._.",   // Comma
        "_._._._",  // Period
        "_._._..",  // Colon
        "_._._._.", // Semicolon
        "_._.__.",  // Apostrophe
        "_.._._",   // Question mark
        "_._._.._", // Hyphen
        "_.._._.",  // Slash
        "_.__._",   // Left parentheses
        "_.__._.",  // Right parentheses
        "_.__._._.",// Quotation marks
        "._.._.",   // Equal sign
        ".__._.",   // Plus
        "._.__.",   // At sign
    };

    int messageLength = strlen(message);

    // Iterate over each character in message
    for (int i = 0; i < messageLength; i++)
    {
        // Find index of character in lookup table
        char* charPtr = strchr(morseCodeLookup, toupper(message[i]));

        // If character is found in lookup table
        if (charPtr)
        {
            int morseCodeIndex = charPtr - morseCodeLookup;
            strcat(morseCode, medievalMorseCode[morseCodeIndex]);
            strcat(morseCode, " "); // Add space between each Morse code letter
        }
    }
}