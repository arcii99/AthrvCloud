//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int password_length, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_char_count = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check if password length is less than 8
    if(password_length < 8) {
        printf("Password is weak!\n");
        printf("Password must be at least 8 characters long!\n");
    } else {
        // Check password strength
        for(int i = 0; i < password_length; i++) {
            if(isdigit(password[i])) {
                digit_count++;
            } else if(isupper(password[i])) {
                uppercase_count++;
            } else if(islower(password[i])) {
                lowercase_count++;
            } else {
                special_char_count++;
            }
        }
        if(digit_count < 2) {
            printf("Password is weak!\n");
            printf("Password must contain at least 2 digits!\n");
        } else if(uppercase_count < 2) {
            printf("Password is weak!\n");
            printf("Password must contain at least 2 uppercase characters!\n");
        } else if(lowercase_count < 2) {
            printf("Password is weak!\n");
            printf("Password must contain at least 2 lowercase characters!\n");
        } else if(special_char_count < 2) {
            printf("Password is weak!\n");
            printf("Password must contain at least 2 special characters!\n");
        } else {
            printf("Password is strong!\n");
        }
    }
    return 0;
}