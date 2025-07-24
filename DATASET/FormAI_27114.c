//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check password strength
int checkPasswordStrength(char *password)
{
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, specialchar = 0;

    // check if password length is within the range of 8 to 16 characters
    if(length < 8 || length > 16) {
        printf("Your password must be between 8 to 16 characters.\n");
        return 0;
    }

    // loop through each character to check for strength criteria
    for(int i=0; i<length; i++) {
        if(isupper(password[i]))
            uppercase++;
        else if(islower(password[i]))
            lowercase++;
        else if(isdigit(password[i]))
            digit++;
        else
            specialchar++;
    }

    // check if password has at least one uppercase letter
    if(uppercase == 0) {
        printf("Your password must have at least one uppercase letter.\n");
        return 0;
    }

    // check if password has at least one lowercase letter
    if(lowercase == 0) {
        printf("Your password must have at least one lowercase letter.\n");
        return 0;
    }

    // check if password has at least one digit
    if(digit == 0) {
        printf("Your password must have at least one digit.\n");
        return 0;
    }

    // check if password has at least one special character
    if(specialchar == 0) {
        printf("Your password must have at least one special character.\n");
        return 0;
    }

    // if all strength criteria are met, password is strong
    printf("Your password is strong.\n");
    return 1;
}

int main()
{
    char password[20];
    printf("Enter a password: ");
    fgets(password, 20, stdin);

    // remove the newline character from fgets input
    password[strcspn(password, "\n")] = 0;

    checkPasswordStrength(password);
    return 0;
}