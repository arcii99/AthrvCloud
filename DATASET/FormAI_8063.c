//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
void reverseString(char str[]);
int countWords(char str[]);
void replaceChar(char str[], char oldChar, char newChar);

int main()
{
    char inputString[100];
    int numberOfWords;

    printf("Enter a string: ");
    fgets(inputString, 100, stdin); // get input from user

    printf("\nOriginal String: %s", inputString);

    reverseString(inputString); // call reverseString function

    printf("Reversed String: %s", inputString);

    numberOfWords = countWords(inputString); // call countWords function

    printf("\nNumber of words in the string: %d", numberOfWords);

    replaceChar(inputString, 'a', 'e'); // call replaceChar function

    printf("\nAfter replacing the character 'a' with 'e': %s", inputString);

    return 0;
}

/* function to reverse a string */
void reverseString(char str[])
{
    int length, i;
    char *begin, *end, temp;

    length = strlen(str);

    begin = str;
    end = str;

    // move the end pointer to the end of the string
    for (i = 0; i < length - 1; i++)
    {
        end++;
    }

    // swap characters from beginning and end till middle is reached
    for (i = 0; i < length / 2; i++)
    {
        temp = *end;
        *end = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}

/* function to count the number of words in a string */
int countWords(char str[])
{
    int count = 0, i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') // if space, newline or tab is found
        {
            count++; // increment count
        }
    }

    return count + 1; // add 1 to count as there will be one more word at the end of the string
}

/* function to replace a character in a string with a new character */
void replaceChar(char str[], char oldChar, char newChar)
{
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == oldChar) // if old character is found
        {
            str[i] = newChar; // replace it with new character
        }
    }
}