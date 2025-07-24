//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    
    int length = strlen(password) - 1;
    int has_uppercase = 0,
        has_lowercase = 0,
        has_digit = 0,
        has_special_char = 0;
    
    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
        } else if(islower(password[i])) {
            has_lowercase = 1;
        } else if(isdigit(password[i])) {
            has_digit = 1;
        } else if(!isalpha(password[i]) && !isdigit(password[i])) {
            has_special_char = 1;
        }
    }
    
    if(length < 8) {
        printf("Password too short. Choose a password with at least 8 characters.\n");
    } else if(!has_uppercase) {
        printf("Password is weak. Choose a password with at least one uppercase character.\n");
    } else if(!has_lowercase) {
        printf("Password is weak. Choose a password with at least one lowercase character.\n");
    } else if(!has_digit) {
        printf("Password is weak. Choose a password with at least one digit.\n");
    } else if(!has_special_char) {
        printf("Password is weak. Choose a password with at least one special character.\n");
    } else {
        printf("Password meets the minimum requirements.\n");
    }
    
    return 0;
}