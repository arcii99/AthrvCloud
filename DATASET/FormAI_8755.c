//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to remove special characters from a string
void removeSpecialChars(char str[MAX_LEN])
{
    int i, j;
    for (i = 0, j = 0; str[i]; i++)
        if (!(ispunct(str[i]) || isspace(str[i])))
            str[j++] = tolower(str[i]);
    str[j] = '\0';
}

// Function to check if a string is a palindrome
int isPalindrome(char str[MAX_LEN])
{
    int i, len = strlen(str);
    for (i = 0; i < len/2; i++)
        if (str[i] != str[len-i-1])
            return 0;
    return 1;
}

int main()
{
    char str[MAX_LEN];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(str, MAX_LEN, stdin);
    removeSpecialChars(str); // Remove special characters and convert to lower case
    if (isPalindrome(str))
        printf("%s is a palindrome!\n", str);
    else
        printf("%s is not a palindrome!\n", str);

    return 0;
}