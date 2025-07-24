//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

char* translate(char word[20]) // Function to translate the given word to C Cat language
{
    char ccat[20] = "";
    int length = strlen(word);
    for (int i = 0; i<length; i++)
    {
        if (word[i] == 'a')
        {
            strcat(ccat, "meow"); // Adding "meow" to C Cat language string
        }
        else if (word[i] == 'e')
        {
            strcat(ccat, "purr"); // Adding "purr" to C Cat language string
        }
        else if (word[i] == 'i')
        {
            strcat(ccat, "hiss"); // Adding "hiss" to C Cat language string
        }
        else if (word[i] == 'o')
        {
            strcat(ccat, "yowl"); // Adding "yowl" to C Cat language string
        }
        else if (word[i] == 'u')
        {
            strcat(ccat, "growl"); // Adding "growl" to C Cat language string
        }
        else
        {
            strcat(ccat, " "); // Adding space to C Cat language string
        }
    }
    char* translated_word = ccat;
    return translated_word;
}

int main()
{
    char word[20];
    printf("Enter a word to translate to C Cat language: ");
    scanf("%s", word);
    char* ccat_word = translate(word); // Calling the translate function with the given word
    printf("The word \"%s\" in C Cat language is \"%s\"!\n", word, ccat_word);
    return 0;
}