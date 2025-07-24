//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 30
#define MAX_LINE_LENGTH 80

// Function to convert a character into its ASCII art representation
char *charToArt(char ch)
{
    static char art[8][7] = {
        {"      "},
        {"      "},
        {"      "},
        {"      "},
        {"      "},
        {"      "},
        {"      "},
        {"      "}};

    switch (ch)
    {
    case 'A':
        strcpy(art[0], "    _     ");
        strcpy(art[1], "   / \\    ");
        strcpy(art[2], "  / _ \\   ");
        strcpy(art[3], " / ___ \\  ");
        strcpy(art[4], "/_/   \\_\\ ");
        break;
    case 'B':
        strcpy(art[0], " ____   ");
        strcpy(art[1], "|    \\  ");
        strcpy(art[2], "|  _  \\ ");
        strcpy(art[3], "| |_| | ");
        strcpy(art[4], "|____/  ");
        break;
    case 'C':
        strcpy(art[0], "  _____ ");
        strcpy(art[1], " / ___/ ");
        strcpy(art[2], "/ __ \\  ");
        strcpy(art[3], "/ /_/ / ");
        strcpy(art[4], "\\____/  ");
        break;
    // Add more characters here
    default:
        strcpy(art[0], "        ");
        strcpy(art[1], "        ");
        strcpy(art[2], "        ");
        strcpy(art[3], "        ");
        strcpy(art[4], "        ");
        break;
    }

    return art;
}

int main()
{
    char input[MAX_LINE_LENGTH];
    char *asciiArt[MAX_LINES];

    // Read input string from user
    printf("Enter a string: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // Convert each character of the input string into ASCII art
    for (int i = 0; i < strlen(input); i++)
    {
        asciiArt[i] = charToArt(input[i]);
    }

    // Print the ASCII art
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < strlen(input); j++)
        {
            printf("%s ", asciiArt[j][i]);
        }
        printf("\n");
    }

    return 0;
}