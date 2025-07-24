//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to check if a password is strong */
int isStrong(char *password)
{
    int len = strlen(password);
    int hasDigit = 0, hasUppercase = 0, hasLowercase = 0, hasSpecialChar = 0;
    
    // Check if password length is greater than or equal to 8
    if (len < 8) {
        return 0;
    }
    
    // Check if password contains at least one digit, uppercase letter,
    // lowercase letter, and special character
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (ispunct(password[i])) {
            hasSpecialChar = 1;
        }
    }
    
    // Return 1 if password is strong and 0 otherwise
    if (hasDigit && hasUppercase && hasLowercase && hasSpecialChar) {
        return 1;
    }
    return 0;
}

int main()
{
    char password[50];
    printf("Enter a password: ");
    // Use fgets to read input string and remove new line character
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = '\0';
    
    if (isStrong(password)) {
        printf("The password is strong.\n");
    } else {
        printf("The password is not strong.\n");
    }
    
    return 0;
}