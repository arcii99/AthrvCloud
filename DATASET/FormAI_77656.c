//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, lowercase = 0, uppercase = 0, digit = 0, specialchar = 0;
    
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    length = strlen(password);
    
    if (length < 8) {
        printf("Password is too short. It must be at least 8 characters long.\n");
        return 0;
    }
    
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        } else if (isupper(password[i])) {
            uppercase = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else if (ispunct(password[i])) {
            specialchar = 1;
        }
    }
    
    if (lowercase == 0) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    
    if (uppercase == 0) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    
    if (digit == 0) {
        printf("Password must contain at least one digit.\n");
    }
    
    if (specialchar == 0) {
        printf("Password must contain at least one special character.\n");
    }
    
    if (lowercase == 1 && uppercase == 1 && digit == 1 && specialchar == 1) {
        printf("Password meets all the strength requirements.\n");
    }
    
    return 0;
}