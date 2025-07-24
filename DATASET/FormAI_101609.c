//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to check the strength of password
void checkStrength(char password[])
{
    int i, digitCount = 0, charCount = 0, upperCount = 0, lowerCount = 0, specialCount = 0;
    int passwordLength = strlen(password);

    // Check if password is at least 8 characters long
    if (passwordLength < 8) {
        printf("Weak password. Password should be at least 8 characters long.\n");
        return;
    }

    // Check the character count
    for (i = 0; i < passwordLength; i++) {
        char ch = password[i];

        // Check if character is a digit
        if (isdigit(ch)) {
            digitCount++;
        }

        // Check if character is an upper case letter
        else if (isupper(ch)) {
            upperCount++;
        }

        // Check if character is a lower case letter
        else if (islower(ch)) {
            lowerCount++;
        }

        // Check if character is a special character
        else {
            specialCount++;
        }

        // Increase the character count
        charCount++;
    }

    // Check if the password contains at least 1 digit
    if (digitCount == 0) {
        printf("Weak password. Password should contain at least 1 digit.\n");
        return;
    }

    // Check if the password contains at least 1 upper case letter
    if (upperCount == 0) {
        printf("Weak password. Password should contain at least 1 upper case letter.\n");
        return;
    }

    // Check if the password contains at least 1 lower case letter
    if (lowerCount == 0) {
        printf("Weak password. Password should contain at least 1 lower case letter.\n");
        return;
    }

    // Check if the password contains at least 1 special character
    if (specialCount == 0) {
        printf("Weak password. Password should contain at least 1 special character.\n");
        return;
    }

    // If the password passes all tests, it is a strong password
    printf("Strong password!\n");
}

// Main function
int main()
{
    char password[50];

    // Get the password from user
    printf("Enter your password:\n");
    fgets(password, 50, stdin);

    // Remove trailing newline character
    password[strcspn(password, "\n")] = 0;

    // Call the checkStrength function
    checkStrength(password);

    return 0;
}