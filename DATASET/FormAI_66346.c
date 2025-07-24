//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to capitalize each word in a string
void capitalize(char *str)
{
    // iterate through each character in the string
    for(int i = 0; i < strlen(str); i++)
    {
        // if the character is the first of a word, capitalize it
        if(i == 0 || str[i-1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
        else
        {
            str[i] = tolower(str[i]);
        }
    }
}

// function to reverse a string
void reverse(char *str)
{
    // calculate the length of the string
    int len = strlen(str);

    // iterate through each character in the string
    for(int i = 0; i < len/2; i++)
    {
        // swap the characters at opposite ends of the string
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// function to remove a character from a string
void removeChar(char *str, char c)
{
    int i, j;
    // iterate through each character in the string
    for(i = 0, j = 0; i < strlen(str); i++)
    {
        // if the character is not the one to be removed, keep it in the string
        if(str[i] != c)
        {
            str[j] = str[i];
            j++;
        }
    }
    // set the end of the string to NULL
    str[j] = '\0';
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    // remove the newline character at the end of the string
    str[strcspn(str, "\n")] = '\0';

    // capitalize each word in the string
    capitalize(str);
    printf("Capitalized string: %s\n", str);

    // reverse the string
    reverse(str);
    printf("Reversed string: %s\n", str);

    // remove all occurrences of the letter 'a' in the string
    removeChar(str, 'a');
    printf("String with 'a' removed: %s\n", str);

    return 0;
}