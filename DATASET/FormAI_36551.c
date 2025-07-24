//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int length, lower = 0, upper = 0, digits = 0, symbols = 0;
    int strength_score = 0;
    
    printf("Enter a password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(int i=0; i<length; i++) {
        // Check for Lowercase characters
        if(password[i] >= 'a' && password[i] <= 'z')
            lower = 1;
        // Check for Uppercase characters
        else if(password[i] >= 'A' && password[i] <= 'Z')
            upper = 1;
        // Check for digits
        else if(password[i] >= '0' && password[i] <= '9')
            digits = 1;
        // Check for symbols
        else
            symbols = 1;
    }
    
    // Calculating strength score based on presence of different types of characters
    strength_score = lower + upper + digits + symbols;
    
    // Printing password strength based on the strength score
    if(strength_score == 1)
        printf("Password strength: Weak\n");
    else if(strength_score == 2)
        printf("Password strength: Moderately Weak\n");
    else if(strength_score == 3)
        printf("Password strength: Moderately Strong\n");
    else if(strength_score == 4)
        printf("Password strength: Strong\n");
    else
        printf("Invalid password\n"); // Password should contain atleast one character
    
    return 0;
}