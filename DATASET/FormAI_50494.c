//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int main(void) {
    char input[MAX_INPUT_LENGTH];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, punctuation = 0;
    
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get user input
    
    for (int i = 0; i < strlen(input); i++) {
        char current = input[i];
        
        if (current >= 'A' && current <= 'Z' || current >= 'a' && current <= 'z') { // Check if character is a letter
            current = tolower(current); // Convert to lowercase to simplify counting
            
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (current >= '0' && current <= '9') { // Check if character is a digit
            digits++;
        } else if (current == ' ') { // Check if character is a space
            spaces++;
        } else { // If character is not a letter, digit or space, assume it is punctuation
            punctuation++;
        }
    }
    
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\nPunctuation: %d\n", vowels, consonants, digits, spaces, punctuation);
    
    return 0;
}