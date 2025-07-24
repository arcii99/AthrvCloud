//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin); // Take input from user
    
    for(int i = 0; i < 100; i++) { // Loop through each character in input
        if(input[i] == '\0') break; // End of string
        
        if(isalpha(input[i])) { // If character is a letter
            input[i] = tolower(input[i]); // Convert to lowercase
        }
        else if(isdigit(input[i])) { // If character is a digit
            int num = input[i] - '0'; // Convert from ASCII to int
            if(num % 2 == 0) { // If even number
                input[i] = 'x'; // Replace with 'x'
            }
            else { // If odd number
                input[i] = 'o'; // Replace with 'o'
            }
        }
        else { // If character is not a letter or digit
            input[i] = '_'; // Replace with '_'
        }
    }
    
    printf("Your sanitized input is: %s", input); // Output sanitized input
    
    return 0;
}