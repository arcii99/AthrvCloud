//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password is strong
int check_password_strength(char *password)
{
    int len = strlen(password);
    
    // Password length should be at least 8 characters
    if (len < 8) {
        return 0;
    }

    int upper = 0, lower = 0, digits = 0, special = 0;
    for (int i = 0; i < len; i++) {
        char c = password[i];

        // Check for uppercase characters
        if (isupper(c)) {
            upper = 1;
        }
        // Check for lowercase characters
        else if (islower(c)) {
            lower = 1;
        }
        // Check for digits
        else if (isdigit(c)) {
            digits = 1;
        }
        // Check for special characters
        else if (ispunct(c) || isspace(c)) {
            special = 1;
        }
    }

    return (upper + lower + digits + special == 4);
}

int main(void)
{
    char password[100];

    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // Remove newline character from password
    strtok(password, "\n");

    if (check_password_strength(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. Please choose a stronger password.\n");
    }

    return 0;
}