//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char inputText[1000];
    char art[6][20] = {
           "____   ____",
           "\\   \\ /   /",
            "\\   Y   /",
            " \\     /",
            "  \\   /",
            "   \\_/",
        };
    printf("Enter text to convert to ASCII art: ");
    fgets(inputText, 1000, stdin);

    // Convert input text to uppercase
    int i = 0;
    while (inputText[i] != '\0')
    {
        inputText[i] = toupper(inputText[i]);
        i++;
    }

    // Print ASCII art
    for (int row = 0; row < 6; row++)
    {
        for (i = 0; inputText[i] != '\0'; i++)
        {
            int asciiValue = (int)inputText[i] - 65; // Get ASCII value of character and subtract 65 to get its index in the alphabet
            if (asciiValue >= 0 && asciiValue <= 25)
            {
                printf("%c ", art[row][asciiValue]);
            }
            else
            {
                printf("  "); // If character is not a letter, print spaces
            }
        }
        printf("\n");
    }

    return 0;
}