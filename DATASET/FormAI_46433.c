//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of the string to be checked

int checkPalindrome(char str[]) { // Function to check if the string is a palindrome
    int length = strlen(str); // Get the length of the string
    
    for(int i = 0; i < length/2; i++) { // Traverse only half of the string length
        
        if(str[i] != str[length-i-1]) { // Check if the characters at i and length-i-1 are same
            return 0; // Return 0 if not a palindrome
        }
    }
    
    return 1; // Return 1 if a palindrome
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", &str); // Get the input string
    
    if(checkPalindrome(str)) { // If the string is a palindrome
        printf("%s is a palindrome!", str);
    } else { // If the string is not a palindrome
        printf("%s is not a palindrome!", str);
    }
    
    return 0; // Exit the program
}