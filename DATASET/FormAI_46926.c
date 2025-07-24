//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <string.h>

//function to check palindrome
int isPalindrome(char s[]) {
    int i, len = strlen(s);
    //comparing first and last character until middle of the string
    for(i=0; i<len/2; i++) {
        if(s[i] != s[len-i-1]) {
            return 0;
        }
    }
    return 1; //returning 1 if the string is palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindrome(str)) {
        printf("%s is a palindrome.", str);
    }
    else {
        printf("%s is not a palindrome.", str);
    }

    return 0;
}