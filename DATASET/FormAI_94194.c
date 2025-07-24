//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>

void translate(char *sentence)
{
    int i, j, len = strlen(sentence);
    
    for(i = 0; i < len; i++)
    {
        switch(sentence[i])
        {
            case 'a':
                printf("ALIEN_LETTER_1");
                break;
            case 'b':
                printf("ALIEN_LETTER_2");
                break;
            case 'c':
                printf("ALIEN_LETTER_3");
                break;
            //add more cases for the rest of the alien letters
            default:
                printf("%c", sentence[i]);
                break;
        }
    }
    
    printf("\n");
}

int main()
{
    char sentence[100];
    
    printf("Enter a sentence in human language: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    printf("In Alien Language: ");
    translate(sentence);
    
    return 0;
}