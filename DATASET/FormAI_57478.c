//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>

int main()
{
    char* phrase = "You are the one I'd like to parse";
    
    printf("Parsing the phrase: %s\n", phrase);
    
    char* pointer = phrase;
    while(*pointer != '\0')
    {
        if(*pointer == ' ')
        {
            printf("You're the space I'd like to skip\n");
        }
        else if(*pointer == 'I')
        {
            printf("I've found you, my beloved variable\n");
        }
        else if(*pointer == 'p' && *(pointer+1) == 'a' && *(pointer+2) == 'r' && *(pointer+3) == 's' && *(pointer+4) == 'e')
        {
            printf("Parsing complete - now I have you in my heart\n");
            break;
        }
        else
        {
            printf("I cannot understand you, my love\n");
        }
        
        pointer++;
    }
    
    return 0;
}