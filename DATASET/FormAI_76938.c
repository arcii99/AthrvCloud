//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Function to convert text input to morse-coded output
void textToMorse(char* input)
{
    // Array to store morse code equivalents of letters
    const char* morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                                 "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                                 "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                                 "-.--", "--.."};

    // Iterate through each letter in the input string
    for (int i = 0; i < strlen(input); i++)
    {
        char letter = input[i];
        int index = -1;

        // Check if the letter is a lowercase character
        if (letter >= 'a' && letter <= 'z')
        {
            index = (int)letter - (int)'a';
        }
        // Check if the letter is an uppercase character
        else if (letter >= 'A' && letter <= 'Z')
        {
            index = (int)letter - (int)'A';
        }
        // If the character is not a letter, print a space for readability
        else
        {
            printf(" ");
            continue;
        }

        // Print the morse code equivalent of the letter
        printf("%s ", morseCode[index]);
    }
}

int main()
{
    printf("Please enter a message to convert to morse code:\n");

    // Read input from user
    char input[100];
    fgets(input, sizeof(input), stdin);

    printf("\nMorse code equivalent:\n");

    // Convert the input to morse code and print it
    textToMorse(input);

    return 0;
}