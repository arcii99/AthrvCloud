//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int length, has_uppercase, has_lowercase, has_number, has_special;
    int i;
    
    printf("Welcome to Password Strength Checker!\n\n");
    printf("Please enter your password: ");
    
    fgets(password, sizeof(password), stdin);
    length = strlen(password) - 1; // minus 1 to exclude newline character
    
    if (length < 8) {
        printf("\nYour password is too short!\n");
    } else {
        has_uppercase = has_lowercase = has_number = has_special = 0;
        for (i = 0; i < length; i++) {
            if (isupper(password[i])) {
                has_uppercase = 1;
            } else if (islower(password[i])) {
                has_lowercase = 1;
            } else if (isdigit(password[i])) {
                has_number = 1;
            } else if (!isalnum(password[i])) {
                has_special = 1;
            }
        }
        if (has_uppercase && has_lowercase && has_number && has_special) {
            printf("\nCongratulations! Your password is very strong!\n");
        } else if (has_uppercase && has_lowercase && has_number) {
            printf("\nYour password is strong, but it could be stronger with special characters.\n");
        } else if (has_uppercase && has_lowercase && has_special) {
            printf("\nYour password is strong, but it could be stronger with numbers.\n");
        } else if (has_uppercase && has_number && has_special) {
            printf("\nYour password is strong, but it could be stronger with lowercase letters.\n");
        } else if (has_lowercase && has_number && has_special) {
            printf("\nYour password is strong, but it could be stronger with uppercase letters.\n");
        } else if (has_uppercase && has_lowercase) {
            printf("\nYour password is moderately strong, but it could be stronger with numbers and/or special characters.\n");
        } else if (has_uppercase && has_number) {
            printf("\nYour password is moderately strong, but it could be stronger with lowercase letters and/or special characters.\n");
        } else if (has_uppercase && has_special) {
            printf("\nYour password is moderately strong, but it could be stronger with numbers and/or lowercase letters.\n");
        } else if (has_lowercase && has_number) {
            printf("\nYour password is moderately strong, but it could be stronger with uppercase letters and/or special characters.\n");
        } else if (has_lowercase && has_special) {
            printf("\nYour password is moderately strong, but it could be stronger with uppercase letters and/or numbers.\n");
        } else if (has_number && has_special) {
            printf("\nYour password is moderately strong, but it could be stronger with uppercase and/or lowercase letters.\n");
        } else if (has_uppercase) {
            printf("\nYour password is weak, please use lowercase letters, numbers and/or special characters to make it stronger.\n");
        } else if (has_lowercase) {
            printf("\nYour password is weak, please use uppercase letters, numbers and/or special characters to make it stronger.\n");
        } else if (has_number) {
            printf("\nYour password is weak, please use uppercase and/or lowercase letters and/or special characters to make it stronger.\n");
        } else if (has_special) {
            printf("\nYour password is weak, please use uppercase and/or lowercase letters and/or numbers to make it stronger.\n");
        } else { // just in case
            printf("\nInvalid password, please try again.\n");
        }
    }
    
    return 0;
}