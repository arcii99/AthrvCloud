//FormAI DATASET v1.0 Category: Text processing ; Style: active
/* This program prompts the user to enter a sentence or phrase,
   and then counts the number of vowels and consonants in that input */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    int vowels = 0;
    int consonants = 0;
    
    printf("Enter a sentence or phrase: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];
        if (isalpha(c))
        {
            switch(toupper(c))
            {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
    }
    
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    
    return 0;
}