//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isPalindrome(char *s) {
    int len = strlen(s);
    for(int i=0; i<len/2; ++i) {
        if(s[i] != s[len-i-1]) {
            return FALSE;
        }
    }
    return TRUE;
}

int main() {
    char str[100];
    printf("Enter a string to check for palindrome: ");
    scanf("%s", str);
    if(isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}