//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// This is a program that translates text to the strange Alien language!
int main() 
{
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Please enter the text you would like to translate: ");

    char input[100];
    scanf("%[^\n]", input);
    getchar();

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) 
    {
        // Check if the character is a consonant
        if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u' 
            && input[i] != 'A' && input[i] != 'E' && input[i] != 'I' && input[i] != 'O' && input[i] != 'U'
            && ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))) 
        {
            printf("%c%c", input[i], 'o');
        } 
        // If the character is a vowel, just print it
        else 
        {
            printf("%c", input[i]);
        }
    }
    printf("\n\nTranslation complete! Happy communicating with Aliens.\n");
    return 0;
}