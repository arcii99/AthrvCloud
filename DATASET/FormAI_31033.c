//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* This program is a password strength checker which checks the strength of a user input password
   based on certain criteria. The program takes the password as input from the user and then checks
   if it meets the following criteria:
   1. Length of the password should be at least 8 characters 
   2. Password should contain at least one character from each of the following categories:
        a. Lowercase alphabets
        b. Uppercase alphabets
        c. Digits
        d. Special characters (punctuation marks, etc.)
   3. Password should not contain any spaces
*/

int main() {
    
    int pass_length = 0;    // Length of password variable
    int lower = 0, upper = 0, digits = 0, special = 0;   // Criteria variables
    
    char c;     // Temporarily store each character of password input
    
    printf("Enter a password: ");
    
    // Loop through each character of password input and check for criteria
    while ((c = getchar()) != '\n' && c != EOF) {
        
        if (c == ' ') {
            printf("Password should not contain any spaces.\n");
            exit(0);
        }
        
        pass_length++;
        
        if (islower(c))
            lower++;
        else if (isupper(c))
            upper++;
        else if (isdigit(c))
            digits++;
        else if (ispunct(c))
            special++;
    }
    
    // Check if password meets criteria
    if (pass_length < 8)
        printf("Password should be at least 8 characters long.\n");
    else if (lower == 0 || upper == 0 || digits == 0 || special == 0)
        printf("Password should contain at least one character from each category (lowercase alphabet, uppercase alphabet, digit, special character).\n");
    else
        printf("Password is strong!\n");
    
    return 0;
}