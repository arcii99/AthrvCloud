//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, lowercase, uppercase, digits, specialChars = 0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    fgets(password, 100, stdin);
    length = strlen(password);

    for(int i = 0; i < length; i++) {
        if(islower(password[i]))
            lowercase++;
        else if(isupper(password[i]))
            uppercase++;
        else if(isdigit(password[i]))
            digits++;
        else if(password[i] >= ' ' && password[i] <= '/') //checking for special characters
            specialChars++;
    }

    printf("\nAnalyzing password strength...\n\n");

    if(length < 8) { //checking if password length is less than 8
        printf("Your password is too weak. It needs to be at least 8 characters long.\n");
        exit(0);
    } else if(lowercase == 0 || uppercase == 0 || digits == 0 || specialChars == 0) { //checking if password has no lowercase, uppercase, digits or special characters
        printf("Your password is weak. It must contain at least one of each: lowercase letter, uppercase letter, digit, and special character.\n");
        exit(0);
    } else {
        printf("Your password is strong. Well done! Keep it safe and secure.\n");
        exit(0);
    }

    return 0;
}