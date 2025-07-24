//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: enthusiastic
/* Welcome to the Password Strength Checker program in C! */

#include <stdio.h>
#include <string.h>

void passwordCheck(char password[]) {
    int length = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;
        
        else if(password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;

        else if(password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;

        else
            hasSpecial = 1;
    }

    if(length < 8 || !hasLower || !hasUpper || !hasDigit || !hasSpecial)
        printf("Password is weak! Please try again.\n");

    else
        printf("Congratulations! Your password is strong!\n");
}

int main() {
    char password[50];

    printf("Welcome to the Password Strength Checker program!\n");
    printf("Please enter a password: ");

    scanf("%s", password);
    passwordCheck(password);

    return 0;
}