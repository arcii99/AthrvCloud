//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function that checks whether the given character is an alphabet or not
int isAlphabet(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1; // If it is an alphabet, return true (1)
    }
    else {
        return 0; // If it is not an alphabet, return false (0)
    }
}

int main() {
    char str[100]; // Declare a character array to store the input string
    int i, j, len, flag = 1; // Declare some variables
    
    printf("Enter string: "); // Prompt the user to enter the string
    scanf("%[^\n]", str); // Read the input string
    
    len = strlen(str); // Calculate the length of the input string
    
    for(i = 0, j = len - 1; i < len / 2; i++, j--) {
        while(!isAlphabet(str[i])) {
            i++; // If the character at position i is not an alphabet, skip it and move to the next character
        }
        while(!isAlphabet(str[j])) {
            j--; // If the character at position j is not an alphabet, skip it and move to the previous character
        }
        if(str[i] != str[j]) {
            flag = 0; // If the characters do not match, set the flag to false (0)
            break; // Break out of the loop
        }
    }
    
    if(flag) {
        printf("%s is a palindrome.\n", str); // If the flag is true (1), the string is a palindrome
    }
    else {
        printf("%s is not a palindrome.\n", str); // If the flag is false (0), the string is not a palindrome
    }
    
    return 0; // Return 0 to indicate successful execution of the program
}