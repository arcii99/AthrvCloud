//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// function to reverse a string
void reverseString(char *string) {
    int length = strlen(string);
    for(int i = 0; i < length/2; i++) {
        char temp = string[i];
        string[i] = string[length-i-1];
        string[length-i-1] = temp;
    }
}

// function to check if string is a palindrome
int isPalindrome(char *string) {
    char reversedString[100];
    strcpy(reversedString, string);
    reverseString(reversedString);
    
    if(strcmp(reversedString, string) == 0) {
        return 1; // string is a palindrome
    } else {
        return 0; // string is not a palindrome
    }
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    if(isPalindrome(inputString)) {
        printf("%s is a palindrome!\n", inputString);
    } else {
        printf("%s is not a palindrome!\n", inputString);
    }
    return 0;
}