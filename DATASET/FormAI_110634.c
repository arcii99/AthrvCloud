//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // using fgets to handle spaces

    // Loop through each character in the string
    for (int i = 0; i < strlen(sentence); i++)
    {
        // If the current character is a space or the last character in the string, increment the word count
        if (sentence[i] == ' ' || i == strlen(sentence) - 1)
            count++;
    }

    printf("Word count: %d\n", count);

    return 0;
}