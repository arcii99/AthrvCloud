//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    char input[100];
    int count = 0;
    printf("RETRO STYLE TEXT PROCESSING PROGRAM\n");
    printf("-----------------------------------\n");
    printf("Enter some text: ");
    fgets(input, 100, stdin);
    printf("Original text: %s\n", input);
    printf("Processed text: ");
    while ((c = input[count]) != '\0')
    {
        if (isupper(c))
        {
            putchar(tolower(c));
        }
        else if (islower(c))
        {
            putchar(toupper(c));
        }
        else if (c == ' ')
        {
            putchar(' ');
        }
        count++;
    }
    printf("\n");
    return 0;
}