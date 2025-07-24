//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100 // Maximum length of the input string

// Function to check if a string is palindrome or not
int isPalindrome(char* str) {
    int len = strlen(str); // finding length of string
    int i=0, j=len-1; // initializing i and j pointers to both ends of the string
    while(i<j){
        if(str[i++] != str[j--]){ // checking if characters at i and j positions are equal or not
            return 0; // if not equal, return false
        }
    }
    return 1; // if all characters are equal, return true
}

int main() {
    char str[MAX_LENGTH]; // declaring input string of maximum length MAX_LENGTH
    printf("Enter a string: ");
    scanf("%s", str); // taking input string from user
    
    if(isPalindrome(str)){ // checking if input string is palindrome or not
        printf("%s is a palindrome\n", str);
    }else{
        printf("%s is not a palindrome\n", str);
    }
    
    return 0;
}