//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_palindrome(char *str);

int main() {
    char str[1000];

    printf("Enter a sentence to check for palindrome: ");
    gets(str);

    if(is_palindrome(str))
        printf("Yes, '%s' is a palindrome.\n", str);
    else
        printf("No, '%s' is not a palindrome.\n", str);

    return 0;
}

/*
    This function checks if a string is a palindrome by comparing the first
    character with the last character, then the second with the second to last,
    and so on until the middle of the string is reached. If all characters
    match, the string is a palindrome.
*/
int is_palindrome(char *str) {
    int i, j, len;

    len = strlen(str);

    // Convert all characters to lowercase
    for(i = 0; i < len; i++)
        str[i] = tolower(str[i]);

    // Remove all non-alphabetic characters
    for(i = j = 0; i < len; i++)
        if(isalpha(str[i]))
            str[j++] = str[i];
    str[j] = '\0';
    
    // Check if the string is a palindrome
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--)
        if(str[i] != str[j])
            return 0;

    return 1;
}