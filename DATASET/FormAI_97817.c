//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include<stdio.h>
#include<string.h>

int main() {
    char password[50];
    int password_length;
    int uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_char_count = 0;
    int i;

    printf("Enter your password: ");
    scanf("%s", password);

    password_length = strlen(password);

    // Counting the number of uppercase, lowercase, digits and special characters in the given password
    for(i = 0; i < password_length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_count++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lowercase_count++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        } else {
            special_char_count++;
        }
    }

    // Checking the password strength based on the above counts
    if(password_length >= 8 && uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1 && special_char_count >= 1) {
        printf("Strong password.\n");
    } else if(password_length >= 6 && uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1) {
        printf("Moderate password.\n");
    } else {
        printf("Weak password.\n");
    }

    return 0;
}