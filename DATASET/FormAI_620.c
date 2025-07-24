//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, uppercase_count, lowercase_count, digit_count, special_char_count;
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    
    length = strlen(password) - 1;  // subtracting 1 to exclude newline character
    uppercase_count = lowercase_count = digit_count = special_char_count = 0;
    
    for(i = 0; i < length; i++) {
        if(isupper(password[i])) {
            uppercase_count++;
        } else if(islower(password[i])) {
            lowercase_count++;
        } else if(isdigit(password[i])) {
            digit_count++;
        } else if(!isalnum(password[i])) {  // checking for special character
            special_char_count++;
        } 
    }
    
    printf("\nPassword Strength Report:\n");
    printf("Password Length: %d\n", length);
    printf("Uppercase Characters: %d\n", uppercase_count);
    printf("Lowercase Characters: %d\n", lowercase_count);
    printf("Digits: %d\n", digit_count);
    printf("Special Characters: %d\n", special_char_count);
    
    if(length < 8) {  // checking for minimum length requirement
        printf("\nYour password is too short. It must be at least 8 characters long.\n");
    } else if(length >= 8 && length <= 10 && lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 && special_char_count == 0) {
        printf("\nYour password is weak. It needs to be stronger.\n");
    } else if(length >= 8 && length <= 10 && lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 && special_char_count > 0) {
        printf("\nYour password is good, but can be stronger.\n");
    } else if(length > 10 && lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 && special_char_count > 0) {
        printf("\nYour password is strong. Keep it up!\n");
    } else {
        printf("\nPlease use a stronger password.\n");
    }
    
    return 0;
}