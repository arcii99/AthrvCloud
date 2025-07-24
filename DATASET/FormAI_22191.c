//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // max length of input C string

int main() {
    char input[MAX_LEN], copy[MAX_LEN];
    int num_vowels = 0, num_digits = 0, num_uppercase = 0, num_lowercase = 0, num_spaces = 0;
    
    printf("Enter a string (max length %d): ", MAX_LEN);
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from the end of input
    
    strcpy(copy, input); // make a copy of the input string
    
    // convert all characters in copy string to lowercase
    for (int i = 0; i < strlen(copy); i++) {
        copy[i] = tolower(copy[i]);
    }
    
    for (int i = 0; i < strlen(input); i++) {
        char curr_char = input[i];
        
        if (isalpha(curr_char)) {
            if (curr_char == 'a' || curr_char == 'e' || curr_char == 'i' || curr_char == 'o' || curr_char == 'u') {
                num_vowels++;
            } else if (isupper(curr_char)) {
                num_uppercase++;
            } else {
                num_lowercase++;
            }
        } else if (isdigit(curr_char)) {
            num_digits++;
        } else if (curr_char == ' ') {
            num_spaces++;
        }
    }
    
    printf("Input string: %s\n", input);
    printf("Lowercase copy: %s\n", copy);
    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of digits: %d\n", num_digits);
    printf("Number of uppercase letters: %d\n", num_uppercase);
    printf("Number of lowercase letters: %d\n", num_lowercase);
    printf("Number of spaces: %d\n", num_spaces);
    
    return 0;
}