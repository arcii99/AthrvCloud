//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000 // Maximum string length 

// Function to convert a string to upper case
void toUpperCase(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // Subtract 32 to convert to upper case
        }
    }
}

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char temp;
    for(int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Convert the string to upper case
    toUpperCase(str);
    printf("Uppercase version: %s\n", str);

    // Reverse the string
    reverse(str);
    printf("Reversed version: %s\n", str);

    if(isPalindrome(str)) {
        printf("String is a palindrome.\n");
    } else {
        printf("String is not a palindrome.\n");
    }

    return 0;
}