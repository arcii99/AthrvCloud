//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
int is_palindrome(char s[]);

int main()
{
    char s[100];
    printf("Enter a word or phrase: ");
    fgets(s, 100, stdin);

    // Remove the newline character from the end of the string
    s[strcspn(s, "\n")] = '\0';

    if (is_palindrome(s))
    {
        printf("%s is a palindrome.\n", s);
    }
    else
    {
        printf("%s is not a palindrome.\n", s);
    }

    return 0;
}

// Reverse string s
void reverse(char s[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Check if string s is a palindrome
int is_palindrome(char s[])
{
    char temp[100];
    strcpy(temp, s); // Make a copy of the original string
    reverse(temp); // Reverse the string
    if (strcmp(s, temp) == 0) // Compare the original string to the reversed string
    {
        return 1; // The string is a palindrome
    }
    else
    {
        return 0; // The string is not a palindrome
    }
}