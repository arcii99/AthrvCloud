//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char alienDictionary[20][10] = {{"Blorg"},{"Zog"},{"Molt"},{"Grok"},{"Slerg"},{"Nop"},{"Xlkr"}};
    char englishDictionary[20][10] = {{"Hello"},{"Goodbye"},{"Friend"},{"Enemy"},{"Love"},{"Hate"},{"Peace"}};
    char userInput[20];
    int i,j,found;

    printf("Welcome to the Alien Language Translator!\n");

    while(1)
    {
        found = 0;
        printf("\nEnter a word in the Alien language to translate: ");
        scanf("%s", userInput);

        if(userInput[0] == '-') break;

        for(i = 0; i < 7; i++)
        {
            if(strcmp(alienDictionary[i], userInput) == 0)
            {
                printf("The translation is: %s", englishDictionary[i]);
                found = 1;
                break;
            }
        }

        if(found == 0) printf("Could not find a translation for the word.");

    }
    printf("Thank you for using the Alien Language Translator!");
    return 0;
}