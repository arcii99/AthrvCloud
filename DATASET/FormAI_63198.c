//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include<stdio.h>
#include<string.h>

int main()
{
    char input_string[100];
    int count = 0;
    int i;

    printf("\nWelcome to the Creative Word Count Tool\n");
    printf("\nPlease enter a sentence:\n");
    fgets(input_string, 100, stdin);

    for (i = 0; i <= strlen(input_string); i++)
    {
        if ((input_string[i] == ' ' && input_string[i+1] != ' ') || input_string[i] == '\0')
        {
            count++;
        }
    }

    printf("\nTotal words in the sentence: %d\n", count);
    printf("\nThank you for using the Creative Word Count Tool.\n");

    return 0;
}