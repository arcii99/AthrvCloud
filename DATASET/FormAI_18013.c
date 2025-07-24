//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100 //maximum length of the string


int is_palindrome_recursive(char *str, int start, int end)
{
    //if the start position exceeds the end position, all characters of the substring has been compared
    if(start >= end) {
        return 1;
    }
    //if the characters on both ends are not equal, it is not a palindrome
    if(str[start] != str[end]) {
        return 0;
    }
    //recursively call the function with the start position incremented and the end position decremented
    return is_palindrome_recursive(str, start+1, end-1);
}

int main()
{
    char string[MAX_LENGTH];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(string, MAX_LENGTH, stdin); //accepts input string from user until it reaches the \n character

    //removing the newline character at the end of the input string
    string[strcspn(string, "\n")] = 0;

    int n = strlen(string);
    int result = is_palindrome_recursive(string, 0, n-1);
    if(result == 1) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }
    return 0;
}