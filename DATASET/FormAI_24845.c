//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum Length of Input String

// Function to check if input string is a Palindrome
// Returns 1 if Palindrome, else returns 0
int isPalindrome(char *str) {
    int length = strlen(str); 
    for (int i=0; i<length/2; i++)
        if (toupper(str[i]) != toupper(str[length-i-1]))
            return 0;
    return 1;
}

int main() {

    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    if (isPalindrome(str)) {
        printf("%s is a Palindrome\n", str);
    } else {
        printf("%s is not a Palindrome\n", str);
    }

    return 0;
}