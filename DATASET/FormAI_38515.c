//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() 
{
    char alien_language[] = "xXxYyYZzZ";
    char english_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char message[50];
    printf("Welcome to the Alien Language Translator! Please enter your message (max 50 characters):\n");
    gets(message);
    int length = strlen(message);
    printf("\n------- Translation: -------\n");
    for(int i=0; i<length; i++) 
    {
        int is_upper = 0;
        if(message[i] >= 'A' && message[i] <= 'Z') 
        {
            is_upper = 1;
            message[i] = tolower(message[i]);
        }
        char translation = message[i];
        for(int j=0; j<26; j++) 
        {
            if(message[i] == english_alphabet[j]) 
            {
                translation = alien_language[j];
                break;
            }
        }
        if(is_upper) 
        {
            printf("%c", toupper(translation));
        } 
        else 
        {
            printf("%c", translation);
        }
    }
    printf("\n----------------------------\n");
    return 0;
}