//FormAI DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define DICTIONARY_SIZE 5

char dictionary[DICTIONARY_SIZE][MAX_WORD_SIZE] = {"hello", "world", "computer", "science", "programming"};

bool isInDictionary(char word[MAX_WORD_SIZE])
{
    for(int i = 0; i < DICTIONARY_SIZE; i++)
    {
        if(strcmp(dictionary[i], word) == 0)
        {
            return true;
        }
    }

    return false;
}

bool isLetter(char c)
{
    return isalpha(c) != 0;
}

int main()
{
    printf("Welcome to the immersive C spell checking program!\n\n");

    char input[MAX_WORD_SIZE];

    while(true)
    {
        printf("Please enter a word to check (type 'exit' to quit): ");
        scanf("%49s", input);

        if(strcmp(input, "exit") == 0)
        {
            printf("Thank you for using the C spell checking program.\n");
            break;
        }

        int length = strlen(input);

        // remove punctuation and convert to lowercase
        for(int i = 0; i < length; i++)
        {
            if(!isLetter(input[i]))
            {
                for(int j = i; j < length - 1; j++)
                {
                    input[j] = input[j+1];
                }
                length--;
                i--;
            }
            else
            {
                input[i] = tolower(input[i]);
            }
        }

        if(isInDictionary(input))
        {
            printf("The word %s is correctly spelled.\n", input);
        }
        else
        {
            printf("The word %s is not found in the dictionary.\n", input);
        }
    }

    return 0;
}