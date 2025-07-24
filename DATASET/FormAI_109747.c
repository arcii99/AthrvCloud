//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i = 0;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_count = 0;
    
    printf("Enter input string: ");
    fgets(input, 100, stdin);
    
    while (input[i] != '\0') {
        // Convert all characters to lowercase
        input[i] = tolower(input[i]);
        
        // Count number of lowercase letters
        if (islower(input[i])) {
            lowercase_count++;
        }
        
        // Count number of uppercase letters
        if (isupper(input[i])) {
            uppercase_count++;
        }
        
        // Count number of digits
        if (isdigit(input[i])) {
            digit_count++;
        }
        
        // Count number of special characters
        if (!isalnum(input[i])) {
            special_count++;
        }
        
        // Filter out non-alphanumeric characters
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
        
        // Move to the next character in the input string
        i++;
    }
    
    // Print sanitized input string
    printf("Sanitized string: %s\n", input);
    
    // Print statistics on input string
    printf("Lowercase letters: %d\n", lowercase_count);
    printf("Uppercase letters: %d\n", uppercase_count);
    printf("Digits: %d\n", digit_count);
    printf("Special characters: %d\n", special_count);
    
    return 0;
}