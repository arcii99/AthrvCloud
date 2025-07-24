//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// define maximum input string length
#define MAX_INPUT_LEN 100

/* 
    Function to translate a sentence from English to C Cat language:
    1. Words that end with a consonant have "cat" appended to them.
    2. Words that end with a vowel have "meow" appended to them.
*/
void translateToCCatLanguage(char input[])
{
    int len = strlen(input);

    // loop through the sentence
    for(int i=0; i<len; i++)
    {
        // check if the current character is a space
        if(input[i] == ' ')
        {
            // if so, print it directly
            printf("%c", input[i]);
            continue;
        }

        // check if the current character is a vowel
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
        {
            // if so, print "meow"
            printf("meow");
        }
        else
        {
            // if not, print "cat"
            printf("cat");
        }

        // if the current character is not the last character
        if(i != len-1)
        {
            // check if the next character is a letter
            if(input[i+1] >= 'a' && input[i+1] <= 'z' || input[i+1] >= 'A' && input[i+1] <= 'Z')
            {
                // if so, print a space
                printf(" ");
            }
        }
    }

    printf("\n");
}

// main function
int main()
{
    char input[MAX_INPUT_LEN];

    printf("Enter a sentence in English: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // remove newline character
    input[strlen(input)-1] = '\0';

    printf("Translation to C Cat language: ");

    // translate to C Cat language
    translateToCCatLanguage(input);

    return 0;
}