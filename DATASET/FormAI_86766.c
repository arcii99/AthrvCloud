//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main()
{
    char input[MAX_INPUT_LENGTH]; // To store user input
    char morseCode[MAX_INPUT_LENGTH]; // To store morse code generated from user input
    char *morseAlphabets[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // The Morse code equivalent of the alphabets
    
    printf("Enter the text to be converted to Morse code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // To get input from the user
    
    for (int i = 0; i < strlen(input) - 1; i++) // Loop to iterate through each character of the input string
    {
        if (input[i] == ' ') // If the character is a space, add a pipe symbol to the morseCode string
        {
            strncat(morseCode, "| ", 2);
        }
        else // Else, append the Morse code equivalent to the morseCode string
        {
            char upperChar = toupper(input[i]); // Convert the character to upper case to match the Morse code alphabet array
            
            if (upperChar >= 'A' && upperChar <= 'Z') // If the character is an alphabet, add the Morse code equivalent to the morseCode string
            {
                strncat(morseCode, morseAlphabets[upperChar - 'A'], strlen(morseAlphabets[upperChar - 'A']));
                strncat(morseCode, " ", 1);
            }
        }
    }
    
    printf("\nMorse code equivalent: %s", morseCode);
    
    return 0;
}