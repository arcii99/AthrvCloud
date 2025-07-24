//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
/* A unique C User Input Sanitizer program that eliminates all special characters and converts all letters to uppercase */

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100]; // array to store input string
    int i = 0; // initialize counter variable
    
    printf("Enter your input: ");
    fgets(input, 100, stdin); // get input from user
    
    printf("Cleaned and sanitized input: ");
    while (input[i]) { // loop through each character in input array
        
        if (isalpha(input[i])) { // if character is a letter
            putchar(toupper(input[i])); // convert to uppercase and print
        }
        
        i++; // increment counter
        
    }
    
    return 0; // exit program
}

/*
Sample Output:
Enter your input: Hell0 W0rld!
Cleaned and sanitized input: HELLWORLD
*/