//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c;
    int width, height;

    printf("Enter width and height of art: ");
    scanf("%d %d", &width, &height);

    printf("\nEnter your text: ");

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (isalpha(c))
        {
            printf("Invalid input, text must not contain alphabets!");
            return 1;
        }
    }

    if (c == EOF)
    {
        printf("Invalid input, text must not contain alphabets!");
        return 1;
    }

    // Start generating ASCII art
    int i, j;
    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= width; j++)
        {
            int a = rand() % 220 + 33; // Generate random ASCII character
            printf("%c", a);
        }

        printf("\n"); // Move to next line
    }

    return 0;
}