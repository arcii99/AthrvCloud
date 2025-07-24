//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int i, j;
    char temp;

    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int isPalindrome(char *str) {
    char reverseStr[strlen(str)];
    strcpy(reverseStr, str);
    reverse(reverseStr);

    return strcmp(str, reverseStr) == 0;
}

int main() {
    char str[100];

    printf("Welcome to the Palindrome Checker program!\n");
    printf("Please enter a string to check if it is a palindrome: ");

    fgets(str, 100, stdin); 
    str[strcspn(str, "\n")] = 0; 

    if(isPalindrome(str)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is NOT a palindrome.\n", str);
    }

    return 0;
}