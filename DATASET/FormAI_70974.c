//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: secure
#include <stdio.h>
#include <string.h>

// Function to check if given password is strong or not
int isPasswordStrong(char *password)
{
    int i, length, lowerCase = 0, upperCase = 0, digits = 0, symbols = 0;
 
    length = strlen(password);
    
    // Check the password length
    if (length < 8) {
        printf("Password is too short!\n");
        return 0;
    }

    // Check for lowercase, uppercase, digits and symbols in the password
    for (i = 0; password[i]; i++) {
        if (password[i] >= 'a' && password[i] <= 'z')
            lowerCase++;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            upperCase++;
        else if (password[i] >= '0' && password[i] <= '9')
            digits++;
        else
            symbols++;
    }
 
    // If a character category is missing, inform the user
    if (lowerCase == 0) {
        printf("Password should contain lowercase letters!\n");
        return 0;
    }
    else if (upperCase == 0) {
        printf("Password should contain uppercase letters!\n");
        return 0;
    }
    else if (digits == 0) {
        printf("Password should contain digits!\n");
        return 0;
    }
    else if (symbols == 0) {
        printf("Password should contain symbols!\n");
        return 0;
    }
 
    // Password has passed all checks and is considered strong
    printf("Password is strong!\n");
    return 1;
}

// Main Function
int main()
{
    char password[100];
 
    printf("Enter a password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character from input

    // Check the strength of the password
    isPasswordStrong(password);
 
    return 0;
}