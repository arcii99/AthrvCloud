//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0;
    
    printf("Enter password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        }
        else {
            special++;
        }
    }

    printf("\nPassword Strength Check Results:\n");
    
    if (length < 8) {
        printf("Password length is too short. It must be at least 8 characters long.\n");
    }
    else if (upper == 0 || lower == 0 || digit == 0 || special == 0) {
        printf("Weak Password!\n");
        printf("This password must have at least one uppercase, one lowercase, one digit and one special character.\n");
    }
    else {
        printf("Strong Password!\n");
    }

    return 0;
}