//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[100], temp;
    int len, i, j;

    // Ask the user for a string input
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    len = strlen(str);

    // Removes the trailing newline character from the string
    if(str[len-1] == '\n')
    {
        str[len-1] = '\0';
        len--;
    }

    // Reverses the string
    for(i=0, j=len-1; i<j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Capitalizes every alternate character in the reversed string
    for(i=0; i<len; i++)
    {
        if(i%2 == 0)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
    }

    // Prints the final string
    printf("The manipulated string is: %s\n", str);

    return 0;
}