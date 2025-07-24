//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Prototypes
void print_intro();
void translate(char* input);

int main()
{
    print_intro();  // Print introduction

    char input[100];

    // Get user input
    printf("Enter your alien language word: ");
    fgets(input, 100, stdin);

    // Remove trailing newline character from input
    input[strcspn(input, "\n")] = '\0';

    translate(input);

    return 0;
}

// Print introduction
void print_intro()
{
    printf("Welcome to the C Alien Language Translator!\n");
    printf("This program will translate any words or phrases you input into the alien language.\n\n");
}

// Translate input into alien language
void translate(char* input)
{
    char output[100];

    // Translate input into alien language 
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'a')
            output[i] = 'z';
        else if (input[i] == 'b')
            output[i] = 'y';
        else if (input[i] == 'c')
            output[i] = 'x';
        else if (input[i] == 'd')
            output[i] = 'w';
        else if (input[i] == 'e')
            output[i] = 'v';
        else if (input[i] == 'f')
            output[i] = 'u';
        else if (input[i] == 'g')
            output[i] = 't';
        else if (input[i] == 'h')
            output[i] = 's';
        else if (input[i] == 'i')
            output[i] = 'r';
        else if (input[i] == 'j')
            output[i] = 'q';
        else if (input[i] == 'k')
            output[i] = 'p';
        else if (input[i] == 'l')
            output[i] = 'o';
        else if (input[i] == 'm')
            output[i] = 'n';
        else if (input[i] == 'n')
            output[i] = 'm';
        else if (input[i] == 'o')
            output[i] = 'l';
        else if (input[i] == 'p')
            output[i] = 'k';
        else if (input[i] == 'q')
            output[i] = 'j';
        else if (input[i] == 'r')
            output[i] = 'i';
        else if (input[i] == 's')
            output[i] = 'h';
        else if (input[i] == 't')
            output[i] = 'g';
        else if (input[i] == 'u')
            output[i] = 'f';
        else if (input[i] == 'v')
            output[i] = 'e';
        else if (input[i] == 'w')
            output[i] = 'd';
        else if (input[i] == 'x')
            output[i] = 'c';
        else if (input[i] == 'y')
            output[i] = 'b';
        else if (input[i] == 'z')
            output[i] = 'a';
        else
            output[i] = '?';
    }

    // Print translated output
    printf("\nYour input in alien language: %s\n", output);
}