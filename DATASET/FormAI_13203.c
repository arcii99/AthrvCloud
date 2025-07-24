//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter a password to check: ");

    char password[50];
    fgets(password, sizeof(password), stdin);

    // Removing the trailing newline character
    password[strcspn(password, "\n")] = 0;

    // Password length check
    int len = strlen(password);
    if(len < 8){
        printf("Weak Password! Password length should be at least 8 characters.\n");
    }else{
        printf("Good Job! Your password's length is acceptable.\n");
    }

    // Password complexity check
    int i, upper = 0, lower = 0, digit = 0, special = 0;
    for(i=0; i<len; i++){
        if(isupper(password[i])){
            upper = 1;
        }else if(islower(password[i])){
            lower = 1;
        }else if(isdigit(password[i])){
            digit = 1;
        }else{
            special = 1;
        }
    }

    if(upper == 1 && lower == 1 && digit == 1 && special == 1){
        printf("Congratulations! Your password is very strong.\n");
    }else if((upper == 1 && lower == 1 && digit == 1) || (upper == 1 && lower == 1 && special == 1) || (upper == 1 && digit == 1 && special == 1) || (lower == 1 && digit == 1 && special == 1)){
        printf("Great! Your password is strong, but could be stronger.\n");
    }else{
        printf("Uh-Oh! Your password is weak. Please make sure it contains at least 1 uppercase letter, 1 lowercase letter, 1 digit and 1 special character.\n");
    }

    return 0;
}