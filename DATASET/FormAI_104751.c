//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include<stdio.h>
#include<string.h>
int main()
{
    char word[50];
    printf("Enter the phrase in Alien language: ");
    scanf("%s", word);
    if(strcmp(word,"eiBieerg") == 0)
    {
        printf("The phrase in English is: \"You are beautiful\"\n");
    }
    else if(strcmp(word,"sRuilho") == 0)
    {
        printf("The phrase in English is: \"I love you\"\n");
    }
    else if(strcmp(word,"noGresk") == 0)
    {
        printf("The phrase in English is: \"Good morning\"\n");
    }
    else if(strcmp(word,"tenmuimdiA") == 0)
    {
        printf("The phrase in English is: \"Thank you\"\n");
    }
    else
    {
        printf("Sorry, the translation for this phrase is not available.\n");
    }
    return 0;
}