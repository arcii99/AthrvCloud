//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the given string is palindrome or not
int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1]))
            return 0;
    }
    return 1;
}

int main(){
    char str[100];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%[^\n]%*c", str); // reading multiple words input using scanf

    if (isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}