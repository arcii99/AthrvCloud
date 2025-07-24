//FormAI DATASET v1.0 Category: Spell checking ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char input_text[1000];

    printf("My love, please enter your text below:\n");
    fgets(input_text, sizeof(input_text), stdin);

    char dictionary[5][20] = {"amore", "bacio", "cuore", "gioia", "tesoro"};

    char* word = strtok(input_text, " \n");

    printf("My love, I will now check your text for spelling errors...\n");

    while(word != NULL)
    {
        int match = 0;
        for(int i=0; i<5; i++)
        {
            if(strcmp(word, dictionary[i]) == 0)
            {
                match = 1;
                break;
            }
        }

        if(match == 0)
        {
            printf("ERROR: My love, the word '%s' in your text is misspelled. Would you like me to suggest a correction?\n", word);
            printf("My love, please enter the correct spelling of '%s':\n", word);

            char correction[20];
            fgets(correction, sizeof(correction), stdin);

            for(int i=0; i<strlen(correction); i++)
            {
                if(correction[i] == '\n')
                {
                    correction[i] = '\0';
                    break;
                }
            }

            printf("My love, I have corrected the spelling of '%s' to '%s'.\n", word, correction);
        }

        word = strtok(NULL, " \n");
    }

    printf("My love, your text has no spelling errors. I love you, tesoro mio!\n");

    return 0;
}