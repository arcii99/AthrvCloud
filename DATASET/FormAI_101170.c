//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

void translate_alienspeak(char *alienspeak)
{
    int i;
    int len = strlen(alienspeak);
    for(i = 0; i < len; i++)
    {
        if((alienspeak[i] >= 'a' && alienspeak[i] <= 'z') || (alienspeak[i] >= 'A' && alienspeak[i] <= 'Z'))
        {
            alienspeak[i]++;
        }
    }
}

int main()
{
    char alienspeak[100];
    printf("Welcome to the Alien Language Translator\n\n");
    printf("Enter the sentence you want to translate: ");

    fgets(alienspeak, 100, stdin);

    printf("\nBefore Translation: %s", alienspeak);

    translate_alienspeak(alienspeak);

    printf("\nAfter Translation: %s", alienspeak);
    
    printf("\n\n Thank you for using the Alien Language Translator!");
    return 0;
}