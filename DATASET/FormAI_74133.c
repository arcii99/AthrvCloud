//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password meets the minimum requirements
int checkPassword(char password[])
{
    int len = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;
    
    if (len < 8)
        return 0; // Password too short
    
    for (int i = 0; i < len; i++) {
        if (isupper(password[i]))
            has_uppercase = 1;
        else if (islower(password[i]))
            has_lowercase = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else
            has_special = 1;
    }
    
    if (has_uppercase && has_lowercase && has_digit && has_special)
        return 1; // Password meets all requirements
    else
        return 0; // Password missing requirements
}

// Function to print the strength of the password
void printStrength(char password[])
{
    if (checkPassword(password))
        printf("The password '%s' is strong!\n", password);
    else
        printf("The password '%s' is weak.\n", password);
}

int main()
{
    char password[100];
    
    printf("Enter a password (at least 8 characters, with uppercase, lowercase, digit, and special character): ");
    fgets(password, 100, stdin);
    
    // Remove newline character from input
    password[strcspn(password, "\n")] = 0;
    
    printStrength(password);
    
    return 0;
}