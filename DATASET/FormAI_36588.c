//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h> 
#include <string.h> 

void palindromeCheck(char *string) 
{ 
    int length = strlen(string); 
    int flag = 0; 
  
    // Compare character by character from start and end 
    for(int i = 0; i < length/2; i++) { 
        if (string[i] != string[length-i-1]) { 
            flag = 1; 
            break; 
        } 
    } 
  
    // If the flag variable is equal to 0, then it is a palindrome
    if (flag == 0) { 
        printf("Nice! \"%s\" is a palindrome!\n", string); 
    } else { 
        printf("Oops! \"%s\" is not a palindrome :( \n", string); 
    } 
} 

int main() 
{ 
    char string[100]; 

    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a word or a phrase to check if it is a Palindrome:\n");
    fgets(string, 100, stdin);

    // Removing the trailing newline character from fgets
    string[strcspn(string, "\n")] = 0;

    // Remove any spaces, tabs, or special characters
    for (int i = 0, j = 0; i < strlen(string); i++) {
        if (isalnum(string[i])) {
            string[j++] = tolower(string[i]);
        }
    }
    string[strlen(string)] = '\0';

    palindromeCheck(string); 

    printf("Thank you for using the Palindrome Checker!\n"); 
    return 0; 
}