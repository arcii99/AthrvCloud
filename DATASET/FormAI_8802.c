//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main()
{
    char alien_language[100];
    int i, j, k, l;
    
    printf("Please input the alien language: ");
    scanf("%s", alien_language);
    
    int len = strlen(alien_language);
    for(i=2; i<=len; i++)
    {
        if(len%i == 0)
        {
            k = len/i;
            for(j=1; j<=k; j++)
            {
                for(l=(j-1)*i+2; l<=j*i; l++)
                {
                    if(alien_language[l-1] > alien_language[l-2])
                    {
                        continue;
                    }
                    else
                    {
                        goto end;
                    }
                }
                continue;
                end:
                break;
            }
            if(j > k)
            {
                printf("The translation key is %d", i);
                break;
            }
        }
    }
    if(i > len)
    {
        printf("Cannot translate the alien language");
    }
    return 0;
}