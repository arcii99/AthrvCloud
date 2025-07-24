//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// function to check if a string is a palindrome
bool isPalindrome(char *string){
    int length = strlen(string);
    // loop through the string from both ends and compare characters
    for(int i = 0, j = length - 1; i < j; i++, j--){
        // if characters don't match, return false
        if(string[i] != string[j]){
            return false;
        }
    }
    // if loop completes without returning false, string is a palindrome
    return true;
}

int main(void){

    char input[100];
    // prompt user for input
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input);
    // check if input string is a palindrome
    if(isPalindrome(input)){
        printf("%s is a palindrome!\n", input);
    }else{
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}