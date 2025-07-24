//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main()
{
    // Welcome message
    printf("Welcome to the C Cat Language Translator!\n\n");

    // Get input from user
    char input[100];
    printf("Enter a sentence in C Cat Language:\n");
    gets(input);

    // Declare and initialize output string
    char output[100] = "";

    // Convert C Cat Language to English
    char *token = strtok(input, " ");
    while(token != NULL)
    {
        if(strcmp(token, "meow") == 0)
        {
            strcat(output, "I ");
        }
        else if(strcmp(token, "purr") == 0)
        {
            strcat(output, "love ");
        }
        else if(strcmp(token, "hiss") == 0)
        {
            strcat(output, "hate ");
        }
        else if(strcmp(token, "scratch") == 0)
        {
            strcat(output, "dislike ");
        }
        else
        {
            strcat(output, token);
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }

    // Output translated sentence
    printf("\nTranslated sentence: %s\n", output);

    return 0;
}