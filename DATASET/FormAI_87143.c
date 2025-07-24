//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str, int len){
    char temp;
    for(int i = 0; i < len/2; i++){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to check if a given string is a palindrome
int checkPalindrome(char *str, int len){
    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len-i-1]){
            return 0; // Not a palindrome
        }
    }
    return 1; // A palindrome
}

int main(){
    char str[100];
    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    reverseString(str, len);
    int isPalindrome = checkPalindrome(str, len);
    
    if(isPalindrome){
        printf("The string %s is a palindrome!\n", str);
    } else {
        printf("The string %s is not a palindrome :(\n", str);
    }
    
    printf("Thank you for using the Palindrome Checker!\n");
    return 0;
}