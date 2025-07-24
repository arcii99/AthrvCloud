//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char password[50];
    bool hasUpperCase = false, hasLowerCase = false, hasDigit = false, hasSpecialChar = false;
    int strength = 0;
    
    printf("Hello there, let's check your password strength!\n");
    printf("Please enter your password (up to 50 characters): ");
    fgets(password, 50, stdin);
    
    // Check for uppercase letters
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            hasUpperCase = true;
            break;
        }
    }
    
    // Check for lowercase letters
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            hasLowerCase = true;
            break;
        }
    }
    
    // Check for digits
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            hasDigit = true;
            break;
        }
    }
    
    // Check for special characters
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = true;
            break;
        }
    }
    
    // Determine password strength based on criteria met
    if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
        strength = 4;
    } else if ((hasUpperCase && hasLowerCase && hasDigit) || (hasUpperCase && hasLowerCase && hasSpecialChar) || 
               (hasUpperCase && hasDigit && hasSpecialChar) || (hasLowerCase && hasDigit && hasSpecialChar)) {
        strength = 3;
    } else if ((hasUpperCase && hasLowerCase) || (hasUpperCase && hasDigit) || (hasUpperCase && hasSpecialChar) || 
               (hasLowerCase && hasDigit) || (hasLowerCase && hasSpecialChar) || (hasDigit && hasSpecialChar)) {
        strength = 2;
    } else if (hasUpperCase || hasLowerCase || hasDigit || hasSpecialChar) {
        strength = 1;
    }
    
    // Display password strength
    switch (strength) {
        case 1:
            printf("Your password is weak. Please consider adding more complexity.\n");
            break;
        case 2:
            printf("Your password is moderately strong. Good job!\n");
            break;
        case 3:
            printf("Your password is strong. Keep up the good work!\n");
            break;
        case 4:
            printf("Your password is extremely strong. Impressive!\n");
            break;
        default:
            printf("Hmm, something went wrong. Please try again with a different password.\n");
            break;
    }
    
    return 0;
}