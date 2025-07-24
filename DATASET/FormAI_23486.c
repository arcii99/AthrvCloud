//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    // Define variables for password and length
    char password[100];
    int length, flag_lower=0, flag_upper=0, flag_digit=0, flag_special=0;

    // Take password as input from user
    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // Remove newline character at the end of password
    password[strcspn(password, "\n")] = 0;

    // Calculate length of password
    length = strlen(password);

    // Check if password meets all conditions
    for(int i=0; i<length; i++) {

        // Check if character is lowercase alphabet
        if(islower(password[i])) {
            flag_lower = 1;
        }

        // Check if character is uppercase alphabet
        if(isupper(password[i])) {
            flag_upper = 1;
        }

        // Check if character is digit
        if(isdigit(password[i])) {
            flag_digit = 1;
        }

        // Check if character is special character
        if(!isalnum(password[i])) {
            flag_special = 1;
        }
    }

    // Print strength of password based on conditions met
    if(length>=8 && flag_lower && flag_upper && flag_digit && flag_special) {
        printf("Strong password\n");
    }
    else if((length>=6 && length<8) && flag_lower && flag_upper && flag_digit) {
        printf("Moderate password\n");
    }
    else {
        printf("Weak password\n");
    }

    return 0;
}