//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int isPalindrome(char str[])
{
    char reversed_str[MAX_SIZE];
    int len = strlen(str);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reversed_str[j] = tolower(str[i]);
    }
    reversed_str[j] = '\0';

    if(strcmp(str, reversed_str) == 0) {
        return 1;
    }
    return 0;
}

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if (isPalindrome(str)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }

    return 0;
}