//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* This function checks whether a string is a palindrome or not. It takes a char array as input and returns a boolean value.*/
bool isPalindrome(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;
    
    while (i <= j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // Remove the newline character at the end of the input string
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    
    return 0;
}