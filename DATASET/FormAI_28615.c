//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

int main()
{
    char phrase[1000];
    
    printf("Enter a phrase in Alien Language: ");
    fgets(phrase, 1000, stdin);
    
    // Removing the newline character from the end of the input
    phrase[strcspn(phrase, "\n")] = 0;
    
    int len = strlen(phrase);
    int count = 0;
    
    printf("Translation in English: ");
    
    for(int i=0; i<len; i++)
    {
        if(phrase[i] == 'a')
        {
            printf("9");
            count++;
        }
        else if(phrase[i] == 'b')
        {
            printf("8");
            count++;
        }
        else if(phrase[i] == 'c')
        {
            printf("7");
            count++;
        }
        else if(phrase[i] == 'd')
        {
            printf("6");
            count++;
        }
        else if(phrase[i] == 'e')
        {
            printf("5");
            count++;
        }
        else if(phrase[i] == 'f')
        {
            printf("4");
            count++;
        }
        else if(phrase[i] == 'g')
        {
            printf("3");
            count++;
        }
        else if(phrase[i] == 'h')
        {
            printf("2");
            count++;
        }
        else if(phrase[i] == 'i')
        {
            printf("1");
            count++;
        }
        else
        {
            printf("%c", phrase[i]);
        }
    }
    
    printf("\nNumber of characters translated: %d\n", count);
    
    return 0;
}