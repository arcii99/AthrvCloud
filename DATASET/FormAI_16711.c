//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool palindromeCheck(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // removes the newline character from fgets
    
    bool isPalindrome = palindromeCheck(str);
    
    if (isPalindrome) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    
    return 0;
}