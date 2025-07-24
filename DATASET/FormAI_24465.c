//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
/* C Cat Language Translator */
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000 // maximum number of characters to translate

int main()
{
    char input[MAX_CHARS], translated[MAX_CHARS];
    int i, j, k, l;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter the string to be translated: ");
    fgets(input, MAX_CHARS, stdin);

    // Translate each word in the input string
    i = 0; // index of first letter in word
    j = 0; // index of last digit in word
    k = 0; // index of next available position in translated string
    while (input[i] != '\0')
    {
        // find last digit in current word
        j = i;
        while (input[j] != ' ' && input[j] != '\n' && input[j] != '\0')
            j++;

        if (j > i) // if word has more than one letter (not counting space)
        {
            if (input[i] == 'm' && input[i+1] == 'e' && j == i+2) // meow -> hello
            {
                strcpy(&translated[k], "hello");
                k += 5;
            }
            else if (input[i] == 'p' && input[i+1] == 'u' && input[i+2] == 'r' && j == i+3) // purr -> smile
            {
                strcpy(&translated[k], "smile");
                k += 5;
            }
            else if (input[i] == 's' && input[i+1] == 'n' && input[i+2] == 'a' && input[i+3] == 'c' && input[i+4] == 'k' && j == i+5) // snack -> food
            {
                strcpy(&translated[k], "food");
                k += 4;
            }
            else // copy word without translation
            {
                strncpy(&translated[k], &input[i], j-i);
                k += j-i;
            }
        }
        // copy space or newline after word
        if (input[j] == ' ' || input[j] == '\n')
        {
            translated[k] = input[j];
            k++;
        }
        // move to next word
        i = j+1;
    }

    printf("\nThe translated string is: %s\n", translated);
    printf("\nThank you for using the C Cat Language Translator!\n");

    return 0;
}