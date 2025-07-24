//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to check password strength
void checkPasswordStrength(char password[])
{
    int i, digitCount = 0, upperCount = 0, lowerCount = 0, specCharCount = 0;
    int len = strlen(password);

    // Checking password length
    if (len < 8) {
        printf("Password is weak. Password length should be at least 8.\n");
        return;
    }

    // Counting uppercase, lowercase, digits and special characters
    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            upperCount++;

        else if (password[i] >= 'a' && password[i] <= 'z')
            lowerCount++;

        else if (password[i] >= '0' && password[i] <= '9')
            digitCount++;

        else
            specCharCount++;
    }

    // Checking password strength based on counts
    if (upperCount >= 1 && lowerCount >= 1 && digitCount >= 1 && specCharCount >= 1)
        printf("Password is strong\n");

    else if ((upperCount >= 1 && lowerCount >= 1 && digitCount >= 1) ||
             (upperCount >= 1 && lowerCount >= 1 && specCharCount >= 1) ||
             (upperCount >= 1 && digitCount >= 1 && specCharCount >= 1) ||
             (lowerCount >= 1 && digitCount >= 1 && specCharCount >= 1))
        printf("Password is moderately strong\n");

    else
        printf("Password is weak\n");
}

// Main function
int main()
{
    char password[100];

    // Reading password from user
    printf("Enter the password: ");
    fgets(password, 100, stdin);

    // Checking password strength
    checkPasswordStrength(password);

    return 0;
}