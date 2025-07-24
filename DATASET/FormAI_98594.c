//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Welcome to the C Alien Language Translator! \n");
    printf("Please enter the phrase you would like to translate: \n");
    fgets(input, 100, stdin);

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'C' || input[i] == 'c')
        {
            printf("Excellent, Watson! The C Alien language letter C has been identified.\n");
        }
        else if (input[i] == 'A' || input[i] == 'a')
        {
            printf("Another C Alien language letter has been detected, Watson. The letter A.\n");
        }
        else if (input[i] == 'T' || input[i] == 't')
        {
            printf("Well done, my dear Watson. The C Alien language letter T has been identified.\n");
        }
        else if (input[i] == 'G' || input[i] == 'g')
        {
            printf("Elementary, Watson. The C Alien language letter G has been located.\n");
        }
        else if (input[i] == 'U' || input[i] == 'u')
        {
            printf("Excellent work, Watson. Another C Alien language letter has been identified. The letter U.\n");
        }
        else if (input[i] == 'Z' || input[i] == 'z')
        {
            printf("Dash it all, Watson. We have located yet another C Alien language letter. The letter Z.\n");
        }
        else if (input[i] == 'P' || input[i] == 'p')
        {
            printf("Most impressive, Watson. The C Alien language letter P has been identified.\n");
        }
        else if (input[i] == 'L' || input[i] == 'l')
        {
            printf("Brilliant, Watson. The C Alien language letter L has been located.\n");
        }
        else if (input[i] == 'O' || input[i] == 'o')
        {
            printf("Capital work, Watson. The C Alien language letter O has been identified.\n");
        }
        else
        {
            printf("I am sorry, Watson. I am unable to identify this letter in the C Alien language. \n");
        }
    }

    printf("Translation complete! Thank you for using the C Alien Language Translator.");
    return 0;
}