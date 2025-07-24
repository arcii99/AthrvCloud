//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Function to check if the given string is a palindrome or not
bool isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;
 
    //Loop to check if the characters from both ends are same or not
    while (end > start) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Welcome! I am the Palindrome Checker.\n");
    printf("Give me a string and I'll tell you if it's a Palindrome or not.\n");
    printf("Enter the string:");

    //Read the input string from the user
    fgets(str, 100, stdin);
    
    //Remove the newline character from the input string
    str[strcspn(str, "\n")] = 0;

    //Check if the input string is a palindrome or not
    if (isPalindrome(str)) {
        printf("Congratulations! '%s' is a Palindrome.\n", str);
    } else {
        printf("Oops! '%s' is not a Palindrome.\n", str);
    }
    printf("Thank you for using the Palindrome Checker.\n");
    return 0;
}