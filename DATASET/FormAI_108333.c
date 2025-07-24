//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); // get user input

    printf("\n\n");
    int i, j, k;
    for (i = 1; i <= strlen(sentence); i++)
    {
        // print the top row of characters
        for (j = 0; j < i; j++)
        {
            printf("%c", sentence[j]);
        }

        // print the bottom row of characters
        for (k = strlen(sentence) - i - 1; k >= 0; k--)
        {
            printf("%c", sentence[k]);
        }

        printf("\n"); // print newline character
    }

    printf("\n"); // print an extra newline character

    return 0;
}