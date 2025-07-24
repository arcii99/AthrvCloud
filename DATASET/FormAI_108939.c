//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];

    printf("Enter some text to process:\n");
    fgets(text, 1000, stdin);

    // Remove newline character from input
    text[strcspn(text, "\n")] = '\0';

    int length = strlen(text);

    // Convert all lowercase letters to uppercase letters and vice versa
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 32;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += 32;
        }
    }

    // Count number of words in input
    int words = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ' || text[i] == '\t')
        {
            words++;
        }
    }
    words++;

    // Print processed text and number of words
    printf("\nProcessed text:\n%s\n", text);
    printf("Number of words: %d\n", words);

    return 0;
}