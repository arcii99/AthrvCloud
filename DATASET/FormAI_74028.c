//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(str[i] != str[len-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("*******************************************\n");
    printf("*** Welcome to the Palindrome Checker! ***\n");
    printf("*******************************************\n");
    printf("Please enter a word or phrase to check for palindrome:\n");

    char str[100];
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    if(isPalindrome(str)) {
        printf("\nCongratulations! \"%s\" is a palindrome!\n", str);
    } else {
        printf("\nSorry, \"%s\" is not a palindrome.\n", str);
    }

    printf("Thank you for using the Palindrome Checker. Goodbye!\n");

    return 0;
}