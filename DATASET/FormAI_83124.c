//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Alien Language Translator!\n\n");
    char alien_input[100]; // to store user input
    
    printf("Please provide the Alien language word to be translated into English: ");
    scanf("%s", alien_input);
    printf("\nTranslating word: %s\n\n", alien_input);
    
    int i = 0;
    char translation[100]; // to store translated word
    
    // converting each alien character to English
    while(alien_input[i] != '\0')
    {
        if(alien_input[i] == '#')
        {
            translation[i] = 'a';
        }
        else if(alien_input[i] == '*')
        {
            translation[i] = 'b';
        }
        else if(alien_input[i] == '&')
        {
            translation[i] = 'c';
        }
        else if(alien_input[i] == '$')
        {
            translation[i] = 'd';
        }
        else if(alien_input[i] == '@')
        {
            translation[i] = 'e';
        }
        else if(alien_input[i] == '+')
        {
            translation[i] = 'f';
        }
        else if(alien_input[i] == '-')
        {
            translation[i] = 'g';
        }
        else if(alien_input[i] == '/')
        {
            translation[i] = 'h';
        }
        else if(alien_input[i] == '*')
        {
            translation[i] = 'i';
        }
        else if(alien_input[i] == '&')
        {
            translation[i] = 'j';
        }
        else if(alien_input[i] == '#')
        {
            translation[i] = 'k';
        }
        else if(alien_input[i] == '@')
        {
            translation[i] = 'l';
        }
        else if(alien_input[i] == '%')
        {
            translation[i] = 'm';
        }
        else if(alien_input[i] == '/')
        {
            translation[i] = 'n';
        }
        else if(alien_input[i] == '+')
        {
            translation[i] = 'o';
        }
        else if(alien_input[i] == '*')
        {
            translation[i] = 'p';
        }
        else if(alien_input[i] == '&')
        {
            translation[i] = 'q';
        }
        else if(alien_input[i] == '$')
        {
            translation[i] = 'r';
        }
        else if(alien_input[i] == '#')
        {
            translation[i] = 's';
        }
        else if(alien_input[i] == '+')
        {
            translation[i] = 't';
        }
        else if(alien_input[i] == '-')
        {
            translation[i] = 'u';
        }
        else if(alien_input[i] == '/')
        {
            translation[i] = 'v';
        }
        else if(alien_input[i] == '*')
        {
            translation[i] = 'w';
        }
        else if(alien_input[i] == '&')
        {
            translation[i] = 'x';
        }
        else if(alien_input[i] == '$')
        {
            translation[i] = 'y';
        }
        else if(alien_input[i] == '#')
        {
            translation[i] = 'z';
        }
        else
        {
            translation[i] = alien_input[i]; // if character is not in alien language, retain it as it is
        }
        
        i++;
    }
    
    // printing the translated word
    printf("The translated word is: %s", translation);
    
    return 0;
}