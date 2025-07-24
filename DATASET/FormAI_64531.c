//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int i, j, n;

    printf("Enter a string: ");
    gets(str1);

    // Reversing the string
    n = strlen(str1);
    for(i=0, j=n-1; i<j; i++, j--)
    {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    // Removing spaces from the reversed string
    for(i=0, j=0; str1[i]!='\0'; i++)
    {
        if(str1[i] != ' ')
        {
            str2[j] = str1[i];
            j++;
        }
    }

    str2[j] = '\0';

    // Comparing the original and modified string
    if(strcmp(str1, str2) == 0)
        printf("The string is a palindrome.");
    else
        printf("The string is not a palindrome.");

    return 0;
}