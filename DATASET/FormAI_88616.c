//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[100];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    
    // Remove trailing newline character
    string[strcspn(string, "\n")] = 0;
    
    int len = strlen(string);
    char reversedString[100];
    
    // Reverse the given string
    for(int i = 0; i < len; i++) {
        reversedString[i] = string[len-i-1];
    }
    
    reversedString[len] = '\0';
    
    printf("Original string: %s\n", string);
    printf("Reversed string: %s\n", reversedString);
    
    // Check if palindrome
    int isPalindrome = strcmp(string, reversedString) == 0 ? 1 : 0;
    
    if(isPalindrome) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    // Convert string to uppercase
    for(int i = 0; i < len; i++) {
        string[i] = toupper(string[i]);
    }
    
    printf("Uppercase string: %s\n", string);
    
    // Capitalize each word
    for(int i = 0; i < len; i++) {
        if(i == 0 || string[i-1] == ' ') {
            string[i] = toupper(string[i]);
        }
    }
    
    printf("Capitalized string: %s\n", string);
    
    // Count number of vowels
    int vowelCount = 0;
    
    for(int i = 0; i < len; i++) {
        char c = tolower(string[i]);
        
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }
    
    printf("Number of vowels: %d\n", vowelCount);
    
    return 0;
}