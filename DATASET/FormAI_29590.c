//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convertToMorseCode(char *message)
{
    // Creating array for Morse Code Alphabets
    const char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    printf("Morse Code for the given message:\n");

    // Iterating through each character in the message
    for(int i=0;i<strlen(message);i++)
    {
        // Retrieving ASCII Value of current character
        int asciiValue = (int)message[i];
        
        // Checking if the Character is a Space
        if(asciiValue == 32)
        {
            printf(" ");
        }
        // Checking if the Character lies within A - Z range
        else if(asciiValue >= 65 && asciiValue <= 90)
        {
            // Converting to Uppercase
            asciiValue = asciiValue + 32;
            // Printing Morse Code for the current character
            printf("%s ", morseCode[asciiValue - 97]);
        }
        // Checking if the Character lies within a - z range
        else if(asciiValue >= 97 && asciiValue <= 122)
        {
            // Printing Morse Code for the current character
            printf("%s ", morseCode[asciiValue - 97]);
        }
    }
}

int main()
{
    // Initializing variables
    char message[100];

    // Getting input from the user
    printf("Enter the message to convert to Morse Code (Maximum 100 characters):\n");
    fgets(message,100,stdin);
    
    // Calling the function to convert given message to Morse Code
    convertToMorseCode(message);
    
    return 0;
}