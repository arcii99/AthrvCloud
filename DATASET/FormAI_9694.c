//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <string.h>

//Conversion function
void convertToMorse(char* plainText)
{
    char morseArray[26][6] = {".-", "-...", "-.-.", "-..", ".", "..-.",
                              "--.", "....", "..", ".---", "-.-", ".-..",
                              "--", "-.", "---", ".--.", "--.-", ".-.",
                              "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Loop through each character in the plain text
    for (int i = 0; i < strlen(plainText); i++)
    {
        char c = plainText[i];

        if (c >= 'a' && c <= 'z')
        {
            //Convert to uppercase
            c = c - 32;
        }

        if (c == ' ')
        {
            printf("  ");
        }
        else
        {
            // Convert character to Morse code
            printf("%s ", morseArray[c - 'A']);
        }
    }
}

int main()
{
    printf("Welcome to the Morse Code Converter - Medieval Edition!\n");
    printf("Please enter a sentence to convert:\n");

    char input[100];
    fgets(input, 100, stdin);
    printf("Your message in Morse code is:\n");

    convertToMorse(input);

    printf("\nThank you for using the Morse Code Converter - Medieval Edition!\n");

    return 0;
}