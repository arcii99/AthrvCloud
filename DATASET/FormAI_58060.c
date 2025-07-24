//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int i, j, length, palindrome=0;

    printf("Enter the string: ");
    fgets(input, 1000, stdin);  // Accepts input from user including spaces

    length = strlen(input)-1;   // -1 to remove the newline character from input

    for(i=0; i<length; i++)
    {
        if(input[i] != input[length-i-1])
        {
            palindrome = 1;
            break;
        }
    }

    if(palindrome == 0)
    {
        printf("\nThe entered string is a Palindrome!\n");
    }
    else
    {
        printf("\nThe entered string is not a Palindrome.\n");
    }

    return 0;
}