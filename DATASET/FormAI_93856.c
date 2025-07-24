//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    int i, j;

    printf("Welcome to the Alien Language Translator!\n\n");

    printf("Please enter the alien language sentence you wish to translate:\n");
    fgets(input, sizeof(input), stdin); // allow user to input sentence up to 100 characters

    printf("\nTranslating...\n\n");

    for(i = 0; input[i] != '\n'; i++) // iterate through the sentence
    {
        if (input[i] == 'X') // if the character is 'X'
        {
            printf("The alien symbol X represents: Hello!\n");
        }
        else if (input[i] == 'Y') // if the character is 'Y'
        {
            printf("The alien symbol Y represents: Goodbye!\n");
        }
        else if (input[i] == 'Z') // if the character is 'Z'
        {
            printf("The alien symbol Z represents: Thank you!\n");
        }
        else if (input[i] == 'W') // if the character is 'W'
        {
            printf("The alien symbol W represents: Sorry!\n");
        }
        else if (input[i] == ' ') // if the character is a space
        {
            printf(" "); // print a space
        }
        else // if it is not X, Y, Z, W or space
        {
            printf("Invalid input detected.\n"); // print error message
            printf("The alien symbol '%c' is not recognized by this translator.\n", input[i]);
            printf("Please try again with a different sentence.\n");
            return 0; // end the program
        }
    }

    printf("\nTranslation complete!\n");

    return 0; // end the program
}