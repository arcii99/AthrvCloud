//FormAI DATASET v1.0 Category: Word Count Tool ; Style: retro
#include<stdio.h>
#include<string.h>

int main()
{
    char text[1000];
    int wordCount = 0;

    printf("---------------------------\n");
    printf("|RETRO WORD COUNT TOOL| \n");
    printf("---------------------------\n");

    printf("Enter your text: ");
    fgets(text, 1000, stdin);

    if (strlen(text) > 0 && text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';

    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] == ' ')
            wordCount++;
    }

    printf("The text contains %d words.\n", wordCount+1);

    return 0;
}