//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() 
{
    char kitty_phrases[10][20] = {"Meow", "Purr", "Hiss", "Scratch", "Bite", "Lick", "Play", "Sleep", "Wake Up", "Eat"};
    char english_phrases[10][20] = {"Hello", "I'm happy", "I'm angry", "I'm in pain", "Stop", "Let's cuddle", "Let's play", "I'm tired", "Good morning", "I'm hungry"};

    char input[20];
    int i, match = -1;

    printf("Enter a phrase in C Cat Language: ");
    scanf("%s", input);

    for(i = 0; i < 10; i++) 
    {
        if(strcmp(input, kitty_phrases[i]) == 0) 
        {
            match = i;
            break;
        }
    }

    if(match != -1) 
    {
        printf("Translated phrase in English: %s\n", english_phrases[match]);
    } 
    else 
    {
        printf("Sorry, I don't know what that means in English.\n");
    }
    return 0;
}