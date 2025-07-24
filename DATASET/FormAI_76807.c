//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int result = isPalindrome(str);
    if (result == 1) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}