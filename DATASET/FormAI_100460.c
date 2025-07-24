//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char password[50];
    int length, lowercase=0, uppercase=0, digits=0, special=0, strength=0;

    // Get user input for password
    printf("Enter your password : ");
    fgets(password, 50, stdin);
    length = strlen(password)-1;

    // Check password length
    if(length < 8) {
        printf("Your password is weak! It must be at least 8 characters.\n");
        return 0;
    }

    // Check password character types
    for(int i=0; i<length; i++) {
        if(islower(password[i]))
            lowercase = 1;
        else if(isupper(password[i]))
            uppercase = 1;
        else if(isdigit(password[i]))
            digits = 1;
        else 
            special = 1;
    }

    // Calculate password strength based on character types
    strength = lowercase + uppercase + digits + special;

    // Output password strength
    printf("Your password strength is : ");
    switch(strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very strong\n");
            break;
    }

    return 0;
}