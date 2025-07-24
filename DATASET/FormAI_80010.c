//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Function to check whether a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}