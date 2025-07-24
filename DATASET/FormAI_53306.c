//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void passwordStrengthChecker(char password[]) {
    int len = strlen(password); // get length of password
    int hasUpperCase = 0; // boolean flag to check if password has at least one uppercase character
    int hasLowerCase = 0; // boolean flag to check if password has at least one lowercase character
    int hasDigit = 0; // boolean flag to check if password has at least one digit
    int hasSpecial = 0; // boolean flag to check if password has at least one special character
    float strengthScore = 0; // variable to calculate password strength score

    // loop through each character in password
    for(int i = 0; i < len; i++) {
        // check if character is uppercase letter
        if(isupper(password[i])) {
            hasUpperCase = 1; // set flag to true
            strengthScore += 2; // add 2 points to strength score
        }
        // check if character is lowercase letter
        else if(islower(password[i])) {
            hasLowerCase = 1; // set flag to true
            strengthScore += 2; // add 2 points to strength score
        }
        // check if character is digit
        else if(isdigit(password[i])) {
            hasDigit = 1; // set flag to true
            strengthScore += 2; // add 2 points to strength score
        }
        // check if character is special character
        else if(!isalnum(password[i])) {
            hasSpecial = 1; // set flag to true
            strengthScore += 3; // add 3 points to strength score
        }
    }

    // check if password length is at least 8 characters
    if(len >= 8) {
        strengthScore += 5; // add 5 points to strength score
    }

    // check if password contains at least one uppercase, lowercase, digit, and special character
    if(hasUpperCase && hasLowerCase && hasDigit && hasSpecial) {
        strengthScore += 10; // add 10 points to strength score
    }

    // calculate strength percentage
    float strengthPercentage = (strengthScore / 25) * 100;

    // print password and its strength percentage
    printf("Password: %s\nStrength: %.2f%%\n", password, strengthPercentage);
}

int main() {
    // prompt user to enter password
    printf("Enter Password: ");
    
    // declare variable for password
    char password[100];
    
    // read input from user
    fgets(password, 100, stdin);
    
    // remove '\n' from password
    password[strcspn(password, "\n")] = 0;

    // check password strength
    passwordStrengthChecker(password);

    return 0;
}