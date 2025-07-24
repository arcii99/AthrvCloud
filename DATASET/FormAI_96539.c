//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    int length = strlen(string);
    int i, j;
    int palindrome = 1;

    for(i=0, j=length-1; i<length/2 && j>=length/2; i++, j--)
    {
        if(string[i] != string[j])
        {
            palindrome = 0;
            break;
        }
    }

    if(palindrome)
    {
        printf("%s is a palindrome!\n", string);
    }
    else
    {
        printf("%s is not a palindrome!\n", string);
    }

    return 0;
}