//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <ctype.h>

int main()
{
    char sentence[100];
    printf("Hello! I'm the Happy Spell Checker Bot!\n");
    printf("Please enter a sentence:\n");
    fgets(sentence, 100, stdin);
    
    int i = 0;
    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(isalpha(sentence[i]) == 0 && sentence[i] != ' ')
        {
            printf("Oops! You have used a non-alphabetic character: <%c>  \n", sentence[i]);
        }
            
    }
    
    printf("Don't worry, I'll check your spelling too! Here are the corrected words:\n");
    
    char word[20];
    int j = 0;
    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(isalpha(sentence[i]))
        {
            word[j] = sentence[i];
            j++;
             
        }
        else
        {
            word[j] = '\0';
            j = 0;
            if(word[0] != '\0')
            {
                printf("%s ", word);
            }
            
            if(checkSpelling(word))
            {
                printf("\nOops! You have misspelled the word: <%s>\n", word);
            }
        }
            
    }
    
    printf("\n\nThanks for using Happy Spell Checker! Have a great day!");
    return 0;
}

int checkSpelling(char word[])
{
    char dictionary[5][20] = {"happy", "sunshine", "rainbow", "kittens", "butterfly"};
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        if(strcmp(dictionary[i], word) == 0)
        {
            return 0;
        }
    }
    return 1;
}