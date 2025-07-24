//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0;

    // Take user input for password
    printf("Enter password: ");
    scanf("%s", password);
    
    length = strlen(password);

    if(length < 8) {
        printf("Password is too short!\n");
        return 0;
    }

    // Check password strength
    for(i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        } else if(password[i] >= '0' && password[i] <= '9') {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if(upper && lower && digit && special) {
        printf("Strong password!\n");
    } else if((upper && lower && digit) || (upper && lower && special) || (upper && digit && special) || (lower && digit && special)) {
        printf("Moderate password!\n");
    } else {
        printf("Weak password!\n");
    }

    return 0;
}