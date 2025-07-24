//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8 //minimum length of password required
#define MAX_LENGTH 20 //maximum length of password allowed
#define MIN_DIGITS 2 //minimum number of digits required in password

int is_valid_password(char *password);

int main() {
    char password[MAX_LENGTH + 1];
    int valid;
    
    printf("Enter your password (between %d and %d characters long, with at least %d digits): ", MIN_LENGTH, MAX_LENGTH, MIN_DIGITS);
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; //remove trailing newline from input
    
    valid = is_valid_password(password);
    
    if (valid) {
        printf("Your password meets all requirements.\n");
    } else {
        printf("Your password is not valid.\n");
    }
    
    return 0;
}

int is_valid_password(char *password) {
    int i;
    int len = strlen(password);
    int digits = 0;
    
    if (len < MIN_LENGTH || len > MAX_LENGTH) {
        return 0; //password length is not within acceptable range
    }
    
    for (i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            digits++;
        } else if (!isalnum(password[i])) {
            return 0; //password contains non-alphanumeric characters
        }
    }
    
    if (digits < MIN_DIGITS) {
        return 0; //password does not contain enough digits
    }
    
    return 1; //password meets all requirements
}