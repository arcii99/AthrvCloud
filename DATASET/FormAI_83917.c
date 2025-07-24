//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *translate(char *alien_sentence);

int main()
{
    char alien_sentence[100];
    printf("Enter the sentence in Alien language:\n");
    fgets(alien_sentence, 100, stdin);
    char *english_sentence = translate(alien_sentence);
    printf("The sentence in English is:\n%s", english_sentence);
    return 0;
}

char *translate(char *alien_sentence)
{
    char *english_sentence = malloc(sizeof(char) * 100);
    for(int i=0; i<strlen(alien_sentence); i++)
    {
        if((alien_sentence[i] >= 'a' && alien_sentence[i] <= 'z') || (alien_sentence[i] >= 'A' && alien_sentence[i] <= 'Z'))
        {
            int ascii_value = (int) alien_sentence[i] + 3;
            if((alien_sentence[i] >= 'x' && alien_sentence[i] <= 'z') || (alien_sentence[i] >= 'X' && alien_sentence[i] <= 'Z'))
                ascii_value -= 26;
            english_sentence[i] = (char) ascii_value;
        }
        else if(alien_sentence[i] == ' ')
            english_sentence[i] = ' ';
        else if(alien_sentence[i] == '.')
            english_sentence[i] = '.';
        else
            english_sentence[i] = alien_sentence[i];
    }
    return english_sentence;
}