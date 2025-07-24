//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
/* Medieval ASCII Art Generator */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char inputString[50];
    printf("Enter a string to convert to ASCII art: ");
    fgets(inputString, 50, stdin);

    int i, j, k, l;
    for(i = 0; i < 5; i++) // 5 lines of ASCII art
    {
        for(j = 0; j < 15; j++) // 15 characters per line
        {
            for(k = 0; k < 5; k++) // 5 repetitions per character
            {
                for(l = 0; l < strlen(inputString); l++) // go through all characters in the input string
                {
                    char currentChar = inputString[l];
                    int asciiCode = (int) currentChar;
                    if(asciiCode < 65 || asciiCode > 90) // if not uppercase letter
                    {
                        printf("     "); // leave blank space
                    }
                    else
                    {
                        //Calculate corresponding ASCII code and print
                        int correspondingCode = 9472 + (asciiCode - 65) * 3 + i;
                        printf("%c", correspondingCode);
                        printf("%c", correspondingCode + 1);
                        printf("%c", correspondingCode + 2);
                        printf("%c", correspondingCode + 1);
                        printf("%c", correspondingCode);
                    }
                }
                printf(" "); // space between repeated characters
            }
            printf("\n"); // new line after each set of 5
        }
        printf("\n"); // blank line between lines of ASCII art
    }

    return 0;
}