//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int wordCount = 1, charCount = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    charCount = strlen(input);

    for (int i = 0; input[i] != '\0'; i++) 
    {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') 
        {
            wordCount++;
        }
    }

    printf("\nWord Count : %d \nCharacter Count : %d\n", wordCount, charCount);

    return 0;
}