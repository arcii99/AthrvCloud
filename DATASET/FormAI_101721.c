//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to remove all vowels from a given string
void removeVowels(char *str) {
    int len = strlen(str);

    // Loop through each character of the string
    for(int i=0; i<len; i++) {
        switch(str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                // If the character is a vowel
                // Move all remaining characters one position back
                for(int j=i; j<len; j++) {
                    str[j] = str[j+1];
                }
                // Decrease the length of the string by one
                len--;
                // Decrement the index so that the same position is checked again
                i--;
                break;
            default:
                // If the character is not a vowel, continue to the next character
                continue;
        }
    }
}

int main() {
    char inputString[MAX_STRING_LENGTH];

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    // Remove all vowels from the string
    removeVowels(inputString);

    // Print the final string without vowels
    printf("String without vowels: %s", inputString);

    return 0;
}