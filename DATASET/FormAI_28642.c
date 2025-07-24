//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Immersive Text to Morse code conversion program
int main()
{
    printf("Welcome to the Immersive Text to Morse Code Conversion Program\n");
    printf("==============================================================\n");

    // The Morse code mappings
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                         ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                         "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                         ".----", "..---", "...--", "....-", ".....",
                         "-....", "--...", "---..", "----.", "-----"};

    char userInput[100];
    printf("\nEnter a string of text to convert to Morse code: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // remove the newline character from the input

    // Converting the string to Uppercase
    for(int i = 0; i < strlen(userInput); i++)
    {
        userInput[i] = toupper(userInput[i]);
    }

    printf("\nMorse code conversion of \"%s\" is:\n", userInput);
    printf("--------------------------------------\n");

    // Converting each character of the input string to Morse code and printing it out
    for(int i = 0; i < strlen(userInput); i++)
    {
        if(userInput[i] >= 'A' && userInput[i] <= 'Z')
        {
            printf("%s ", morseCode[userInput[i] - 'A']);
        }
        else if(userInput[i] >= '0' && userInput[i] <= '9')
        {
            printf("%s ", morseCode[userInput[i] - '0' + 26]);
        }
        else if(userInput[i] == ' ')
        {
            printf(" / ");
        }
        else
        {
            printf(" --- ");
        }
    }

    printf("\n\nThank you for using the Immersive Text to Morse Code Conversion Program\n");

    return 0;
}