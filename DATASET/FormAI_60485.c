//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* str) {
    int len = strlen(str);
    char newStr[len+1]; // create new string with same length as input string
    int k = 0;
    // copy only alphanumeric characters from input string to new string
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            newStr[k++] = tolower(str[i]);
        }
    }
    newStr[k] = '\0'; // add null terminator to new string
    
    int left = 0; // left index
    int right = k-1; // right index (k is the length of the new string)
    while (left < right) { // continue until left index meets or passes right index
        if (newStr[left++] != newStr[right--]) {
            return false; // if characters don't match, return false
        }
    }
    return true; // if all characters match, return true
}

int main() {
    char input[100]; // create input string
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, 100, stdin); // get input from user
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input string
    
    if (isPalindrome(input)) {
        printf("The string '%s' is a palindrome.\n", input);
    } else {
        printf("The string '%s' is not a palindrome.\n", input);
    }
    return 0;
}