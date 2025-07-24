//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPalindrome(char *s) {
    int l = strlen(s);
    for(int i=0; i<l/2; i++) {
        if(s[i]!=s[l-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    char s[100];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0'; // Removing trailing newline character
    
    if(isPalindrome(s)==1) {
        printf("%s is a palindrome\n", s);
    } else {
        printf("%s is not a palindrome\n", s);
    }
    
    return 0;
}