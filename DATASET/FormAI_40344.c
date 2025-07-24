//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main(){
    char password[20];
    int length = 0, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter your new password: ");
    fgets(password, 20, stdin);
    length = strlen(password) - 1; // remove newline character from input

    // Check password length 
    if(length < 8){
        printf("\nYour password must be at least 8 characters long\n");
        return 0;
    }
    
    // Loop through password and check for uppercase, lowercase, digit and special characters
    for(int i = 0; i < length; i++){
        if(password[i] >= 65 && password[i] <= 90){ // ASCII code for uppercase letters
            upper = 1;
        }
        else if(password[i] >= 97 && password[i] <= 122){ // ASCII code for lowercase letters
            lower = 1;
        }
        else if(password[i] >= 48 && password[i] <= 57){ // ASCII code for digits
            digit = 1;
        }
        else{
            special = 1;
        }
    }

    // Check if all password requirements are met
    if(upper == 1 && lower == 1 && digit == 1 && special == 1){
        printf("\nCongratulations! Your new password is strong!\n");
    }
    else{
        printf("\nYour password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character\n");
    }
    
    return 0;
}