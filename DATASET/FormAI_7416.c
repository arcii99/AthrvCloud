//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // maximum length of input string

bool isPalindrome(char str[]) {
    int i, j;
    int len = strlen(str);
    
    for (i = 0, j = len-1; i < j; i++, j--) {
        if (toupper(str[i]) != toupper(str[j])) { // convert both characters to uppercase before comparing
            return false;
        }
    }
    
    return true;
}

int main() {
    char str[MAX_LEN];
    
    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, MAX_LEN, stdin); // using fgets instead of scanf to prevent buffer overflow
    
    // remove newline character from input string
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
}