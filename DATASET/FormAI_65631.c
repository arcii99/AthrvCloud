//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main()
{
    char str[MAX_LENGTH];
    int i, j, flag = 0;

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // removing the '\n' character from the end of the input string
    if(str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';

    // Checking whether the string is a palindrome or not
    for (i = 0, j = strlen(str) - 1; i <= j; i++, j--)
    {
        // Ignoring the whitespaces or non-alphabetical characters
        while(str[i] < 'a' || str[i] > 'z')
            i++;
        while(str[j] < 'a' || str[j] > 'z')
            j--;

        if (str[i] != str[j])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("The entered string is not a palindrome!\n");
    else
        printf("The entered string is a palindrome!\n");

    return 0;
}