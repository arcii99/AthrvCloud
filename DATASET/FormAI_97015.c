//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main()
{
    char inputString[MAX_INPUT_LENGTH];
    char reversedString[MAX_INPUT_LENGTH];
    int i, j, length;

    // Get input from user
    printf("Enter a string to reverse: ");
    fgets(inputString, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from input
    if(inputString[strlen(inputString)-1] == '\n')
        inputString[strlen(inputString)-1] = '\0';

    length = strlen(inputString);

    // Reverse the input string
    for(i = length - 1, j = 0; i >= 0; i--, j++)
    {
        reversedString[j] = inputString[i];
    }
    reversedString[length] = '\0';

    // Print the reversed string
    printf("Reversed String: %s\n", reversedString);

    // Count the number of vowels in the input string
    int numVowels = 0;
    for(i = 0; i < length; i++)
    {
        if(inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u' || inputString[i] == 'A' || inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' || inputString[i] == 'U')
        {
            numVowels++;
        }
    }
    printf("Number of vowels: %d\n", numVowels);

    // Convert input string to uppercase
    char uppercaseString[MAX_INPUT_LENGTH];
    for(i = 0; i < length; i++)
    {
        uppercaseString[i] = toupper(inputString[i]);
    }
    uppercaseString[length] = '\0';
    printf("Uppercase String: %s\n", uppercaseString);

    // Compare input string to a known string
    char knownString[] = "hello world";
    if(strcmp(inputString, knownString) == 0)
    {
        printf("Input string matches known string.\n");
    }
    else
    {
        printf("Input string does not match known string.\n");
    }

    return 0;
}