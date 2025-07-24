//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

int main()
{
    char input_str[100], reversed_str[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", input_str);

    // Reverse the input string
    len = strlen(input_str);
    j = 0;
    for(i = len - 1; i >= 0; i--)
    {
        reversed_str[j++] = input_str[i];
    }
    reversed_str[j] = '\0';

    printf("Reversed string: %s\n", reversed_str);

    // Check if input string is equal to reversed string
    if(strcmp(input_str, reversed_str) == 0)
    {
        printf("The input string is a palindrome.");
    }
    else
    {
        printf("The input string is not a palindrome.");
    }

    return 0;
}