//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int main()
{
    char input[MAX_WORD_LENGTH] = {0};
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {0};
    int count[MAX_WORDS] = {0};
    int uniqueWords = 0;
    int i = 0, j = 0, k = 0;
    char c;

    printf("Enter text (press CTRL+D when finished): \n");

    while ( ( c = getchar() ) != EOF )
    {
     if( isalpha(c) )
     {
            input[j++] = tolower(c);
     }
     else if ( j > 0 )
     {
         input[j] = '\0';
         int exists = 0;

         for ( i = 0; i < uniqueWords; ++i )
         {
             if ( strcmp(words[i], input) == 0 )
             {
                 exists = 1;
                 ++count[i];
                 break;
             }
         }
         if ( !exists )
         {
             strcpy(words[uniqueWords], input);
             count[uniqueWords++]++;
         }
         j = 0;
     }
    }

    printf("\n\nWord Frequency\n\n");

    for ( i = 0; i < uniqueWords; ++i )
    {
        printf("%s \t%d\n", words[i], count[i]);
    }

    return 0;
}