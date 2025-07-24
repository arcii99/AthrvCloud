//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>

int main()
{
    char input[100];
    printf("Enter your text: ");
    fgets(input, 100, stdin);

    // Convert text to ASCII art
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        char c = input[i];

        switch (c)
        {
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\\n/    \\\n");
                break;
            case 'B':
                printf("_____\n|    \\\n|___< \n|____/\n");
                break;
            case 'C':
                printf("  ___ \n /    \\\n|      \n \\___/ \n");
                break;
            case 'D':
                printf("_____\n|    \\\n|    |\n|____/\n");
                break;
            case 'E':
                printf("_____\n|___  \n|___  \n|____|\n");
                break;
            case 'F':
                printf("_____\n|___  \n|     \n|     \n");
                break;
            // Add more cases for other letters and symbols
            default:
                // If the character is not recognized, print a blank space
                printf("     \n     \n     \n     \n");
                break;
        }

        // Add some space between characters
        printf(" ");
    }

    printf("\n");

    return 0;
}