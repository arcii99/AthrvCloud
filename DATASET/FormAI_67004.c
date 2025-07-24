//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100 // maximum length of the input string

// function to check if the given string is a palindrome
int check_palindrome(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (str[i] != str[length-1-i]) {
            return 0; // not a palindrome
        }
    }
    return 1; // palindrome
}

int main()
{
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin); // read string from user input
    str[strcspn(str, "\n")] = 0; // remove newline character from the end of the string
    
    if (check_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}