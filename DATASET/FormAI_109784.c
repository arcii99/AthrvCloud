//FormAI DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program prompts the user to enter a string and then converts every word in the string to uppercase letters.*/

void to_uppercase(char* string);

int main() {
    char input[100];
    
    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    // Call to_uppercase function
    to_uppercase(input);
    
    // Output the modified string
    printf("Modified string: %s\n", input);
    
    return 0;
}

void to_uppercase(char* string) {
    int i;
    int len = strlen(string);
    
    // Convert first letter of first word to uppercase
    string[0] = toupper(string[0]);
    
    // Loop over remaining characters
    for (i=1; i<len; i++) {
        // If current character is a space (indicating end of a word), convert next character (start of next word) to uppercase
        if (string[i] == ' ') {
            string[i+1] = toupper(string[i+1]);
        }
        // If current character is already uppercase, continue to next character
        else if (string[i] >= 'A' && string[i] <= 'Z') {
            continue;
        }
        // If current character is a lowercase letter, convert to uppercase
        else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = toupper(string[i]);
        }
    }
}