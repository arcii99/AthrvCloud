//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin); // read the string

    int length = strlen(str) - 1; // remove the newline character
    char rev_str[length];
    int j = 0;

    for(int i = length - 1; i >= 0; i--) { // reverse the string
        if(isalpha(str[i])) {
            rev_str[j++] = tolower(str[i]);
        }
    }
    rev_str[j] = '\0'; // add null terminator

    int flag = 1;
    int mid = j / 2; // middle index of the reversed string
    for(int i = 0; i < mid; i++) { // check for palindrome
        if(rev_str[i] != rev_str[j - 1 - i]) {
            flag = 0;
            break;
        }
    }

    if(flag) printf("The string is a palindrome!");
    else printf("The string is not a palindrome.");

    return 0;
}