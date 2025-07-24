//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

// function to check if the given string is a palindrome or not
int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;
    
    // loop to check if the ith and (n-i-1)th characters of the string are equal
    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[128];
    printf("Enter a string: ");
    fgets(str, 128, stdin);

    // remove the newline character added by fgets()
    str[strcspn(str, "\n")] = 0; 
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome!", str);
    } else {
        printf("%s is not a palindrome.", str);
    }
    
    return 0;
}