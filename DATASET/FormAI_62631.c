//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to display password requirements
void displayRequirements() {
    printf("Your password must contain:\n");
    printf("- At least 8 characters\n");
    printf("- At least 1 uppercase letter\n");
    printf("- At least 1 lowercase letter\n");
    printf("- At least 1 digit\n");
    printf("- At least 1 special character\n\n");
}

// Function to check if password meets requirements
int checkRequirements(char password[]) {
    int length = strlen(password);
    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCount++;
        }
        else if (islower(password[i])) {
            lowerCount++;
        }
        else if (isdigit(password[i])) {
            digitCount++;
        }
        else if (!isspace(password[i])) {
            specialCount++;
        }
    }

    if (upperCount < 1) {
        printf("Password must contain at least 1 uppercase letter.\n");
        return 0;
    }
    if (lowerCount < 1) {
        printf("Password must contain at least 1 lowercase letter.\n");
        return 0;
    }
    if (digitCount < 1) {
        printf("Password must contain at least 1 digit.\n");
        return 0;
    }
    if (specialCount < 1) {
        printf("Password must contain at least 1 special character.\n");
        return 0;
    }

    return 1;
}

// Function to encrypt password
void encryptPassword(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] + 5; // add 5 to ASCII value of each character
    }
}

// Function to decrypt password
void decryptPassword(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] - 5; // subtract 5 from ASCII value of each character
    }
}

int main() {
    char password[50];
    printf("Welcome to the password manager!\n\n");

    // Prompt user to create a new password
    displayRequirements();

    int newPassword = 1;
    while (newPassword) {
        printf("Please enter a new password: ");
        fgets(password, sizeof(password), stdin); // read in password from user


        if (checkRequirements(password)) {
            encryptPassword(password); // encrypt and store password
            printf("Your password has been successfully created and encrypted!\n\n");

            // Prompt user to see their password
            char viewPassword;
            printf("Do you want to see your password? (y/n): ");
            scanf("%c", &viewPassword);

            if (viewPassword == 'y') {
                decryptPassword(password); // decrypt and display password
                printf("Your decrypted password is: %s\n\n", password);
                encryptPassword(password); // re-encrypt password
            }

            // Prompt user to create another password
            char createAnother;
            printf("Do you want to create another password? (y/n): ");
            scanf("%c", &createAnother);

            if (createAnother == 'n') {
                newPassword = 0;
            }

            // clear input buffer to prevent issues with fgets and scanf
            while (getchar() != '\n');
        }
    }

    printf("Thank you for using the password manager.\n");

    return 0;
}