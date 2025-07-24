//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[100], tempChar;
    int length, i, j;

    printf("Please enter the input string: ");
    scanf("%s", inputString);

    length = strlen(inputString);

    printf("Original String: %s\n", inputString);

    // Reversing the string
    for(i=0, j=length-1; i<j; i++, j--)
    {
        tempChar = inputString[i];
        inputString[i] = inputString[j];
        inputString[j] = tempChar;
    }

    printf("Reversed String: %s\n", inputString);

    // Finding and replacing all occurrences of 'a' with 'x'
    for(i=0; i<length; i++)
    {
        if(inputString[i] == 'a')
        {
            inputString[i] = 'x';
        }
    }

    printf("String after replacing all 'a's with 'x's: %s\n", inputString);

    // Reversing the string again
    for(i=0, j=length-1; i<j; i++, j--)
    {
        tempChar = inputString[i];
        inputString[i] = inputString[j];
        inputString[j] = tempChar;
    }

    printf("Reversed String again: %s\n", inputString);

    return 0;
}