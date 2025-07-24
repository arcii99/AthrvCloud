//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char input[1000];
    int words = 1, characters = 0;
    
    printf("Welcome to the C Word Count Tool!\n\n");
    printf("Enter your text here:\n");
    fgets(input, sizeof(input), stdin);

    // Counting characters
    for(int i=0; input[i] !='\0';i++)
    {
        if(input[i] != ' ' && input[i] != '\n')
        {
            characters++;
        }
    }

    // Counting words
    for(int i=0; input[i] !='\0';i++)
    {
        if(input[i] == ' ' || input[i] == '\n')
        {
            words++;
        }
    }

    // Output
    printf("\nYour input has %d words and %d characters.\n", words, characters);

    return 0;
}