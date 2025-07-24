//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char text[])
{
    char *morse[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","----"};
    // an array of Morse codes for each alphabet and digit (0-9), space is missing
    
    // Loop through each character of the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Convert the character to upper case and get its ASCII code
        char c = toupper(text[i]);
        int code = (int) c;
        
        // Check if the character is a space
        if (code == 32)
        {
            printf("    "); // four spaces for space
        }
        else
        {
            // Check if the character is an alphabet or digit
            if (code >= 65 && code <= 90) // ASCII codes for A-Z
            {
                printf("%s ", morse[code-65]); // print Morse code for alphabet
            }
            else if (code >= 48 && code <= 57) // ASCII codes for 0-9
            {
                printf("%s ", morse[code-22]); // print Morse code for digit
            }
            else
            {
                printf("!!INVALID!! "); // print invalid message for unknown character
            }
        }
    }
}

int main()
{
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin); // read text from user input
    
    printf("Morse code: ");
    textToMorse(text); // call the function to convert text to Morse code
    
    printf("\n");
    return 0;
}