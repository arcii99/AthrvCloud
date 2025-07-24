//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void generateArt(char *text);

int main()
{
    char text[MAX_LENGTH];

    // Get user input
    printf("Enter some text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0;

    // Generate ASCII art based on the user's text input
    generateArt(text);

    return 0;
}

void generateArt(char *text)
{
    int length = strlen(text);
    int i, j, k, l;

    // First row
    for (i = 0; i < length; i++)
    {
        printf("  ");
        for (j = 0; j < 4; j++)
        {
            printf("_");
        }
    }
    printf("\n");

    // Second row
    for (i = 0; i < length; i++)
    {
        printf(" /");
        for (j = 0; j < 4; j++)
        {
            printf(" ");
        }
    }
    printf("/\n");

    // Third row
    printf("|");
    for (i = 0; i < length; i++)
    {
        printf(" ");
        printf("%c", text[i]);
        printf(" ");
    }
    printf("|\n");

    // Fourth row
    for (i = 0; i < length; i++)
    {
        printf(" \\");
        for (j = 0; j < 4; j++)
        {
            printf(" ");
        }
    }
    printf("\\\n");

    // Fifth row
    for (i = 0; i < length; i++)
    {
        printf("  ");
        for (j = 0; j < 4; j++)
        {
            printf("-");
        }
    }
    printf("\n");
}