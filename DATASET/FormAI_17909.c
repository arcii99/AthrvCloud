//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to remove leading and trailing white spaces from a string
void removeSpaces(char *str)
{
    // pointers for beginning and ending of the string
    char *begin = str, *end = str + strlen(str) - 1;

    // remove leading white spaces
    while (*begin == ' ') {
        begin++;
    }

    // remove trailing white spaces
    while (*end == ' ' && end >= begin) {
        end--;
    }

    *(end + 1) = '\0'; // terminate the string after the last non-whitespace character
}

int main()
{
    char word[50];

    printf("Enter a word to check its spelling: ");
    fgets(word, sizeof(word), stdin);

    removeSpaces(word); // remove leading and trailing white spaces

    // loop through the characters of the word and check for spelling errors
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) { // if a non-alphabetic character is found
            printf("'%c' is not a valid character in a word.\n", word[i]);
            return 0;
        } else if (!islower(word[i])) { // if an uppercase character is found
            printf("'%c' is not a lowercase letter.\n", word[i]);
            return 0;
        }
    }

    printf("The spelling of '%s' is correct.\n", word);

    return 0;
}