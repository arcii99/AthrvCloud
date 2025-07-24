//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    /* Welcome the user */
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    
    /* Get the user's input */
    char password[50];
    fgets(password, sizeof(password), stdin);
    
    /* Remove the trailing newline character */
    password[strcspn(password, "\n")] = '\0';
    
    /* Check the length of the password */
    int length = strlen(password);
    if (length < 8) {
        printf("Your password is too short. It must be at least 8 characters long.\n");
        return 0;
    }
    
    /* Check for uppercase letters */
    int has_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (has_uppercase == 0) {
        printf("Your password must contain at least one uppercase letter.\n");
        return 0;
    }
    
    /* Check for lowercase letters */
    int has_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (has_lowercase == 0) {
        printf("Your password must contain at least one lowercase letter.\n");
        return 0;
    }
    
    /* Check for digits */
    int has_digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }
    if (has_digit == 0) {
        printf("Your password must contain at least one digit.\n");
        return 0;
    }
    
    /* Check for symbols */
    int has_symbol = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_symbol = 1;
            break;
        }
    }
    if (has_symbol == 0) {
        printf("Your password must contain at least one symbol.\n");
        return 0;
    }
    
    /* If we make it here, the password is strong */
    printf("Your password is strong! Congratulations!\n");
    return 0;
}