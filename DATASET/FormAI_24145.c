//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char password[100]; 
    
    printf("Enter the password you want to check: ");
    fgets(password, 100, stdin); // read input from user

    // check password length
    if (strlen(password) < 8){
        printf("Password is too short. It should be at least 8 characters long.\n");
        return 0;
    }

    // check if password contains upper and lower case letters
    bool hasUpper = false;
    bool hasLower = false;
    for (int i = 0; i < strlen(password); i++){
        if (isupper(password[i])) {
            hasUpper = true;
        } else if (islower(password[i])) {
            hasLower = true;
        }
    }
    if (!hasUpper || !hasLower){
        printf("Password needs to have both upper and lower case letters.\n");
        return 0;
    }

    // check if password has digits
    bool hasDigit = false;
    for (int i = 0; i < strlen(password); i++){
        if (isdigit(password[i])){
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit){
        printf("Password should have at least one digit.\n");
        return 0;
    }

    // check if password has symbols/special characters
    bool hasSpecialChar = false;
    for (int i = 0; i < strlen(password); i++){
        if (!isalnum(password[i])){
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar){
        printf("Password should have at least one symbol.\n");
        return 0;
    }

    printf("Password is strong!\n");
    return 0;
}