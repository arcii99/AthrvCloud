//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

bool isPalindrome(char str[])
{
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(tolower(str[i]) != tolower(str[len-i-1])) {
            return false;
        }
    }
    return true;
}

void inputString(char str[])
{
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    if(str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
}

void printStatus(bool result)
{
    if(result) {
        printf("The entered string is a palindrome!\n");
    } else {
        printf("The entered string is not a palindrome!\n");
    }
}

int main()
{
    char str[MAX_LENGTH];
    inputString(str);
    bool result = isPalindrome(str);
    printStatus(result);
    return 0;
}