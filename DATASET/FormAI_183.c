//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main()
{
    char alienLang[30] = "Xfip cikurlop zino";
    char translator[30][30] = {"hello", "world", "how", "are", "you", "doing", "today"};

    char *token = strtok(alienLang, " ");
    while(token != NULL)
    {
        for(int i = 0; i<7; i++)
        {
            if(strcmp(token, translator[i]) == 0)
            {
                printf("%c", i+97);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
    return 0;
}