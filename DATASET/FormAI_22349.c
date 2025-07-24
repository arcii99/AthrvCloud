//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

int is_palindrome(char str[]);

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if(is_palindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}

int is_palindrome(char str[])
{
    int i, j;
    char clean_str[MAX_SIZE];

    // Remove spaces and non-alpha characters from string
    for(i = 0, j = 0; i < strlen(str); i++){
        if(isalpha(str[i])){
            clean_str[j] = tolower(str[i]);
            ++j;
        }
    }
    clean_str[j] = '\0'; // Add null terminator to end of clean string

    // Check if clean string is a palindrome
    int len = strlen(clean_str);
    for(i = 0, j = len - 1; i < j; i++, j--){
        if(clean_str[i] != clean_str[j]){
            return 0;
        }
    }
    return 1;
}