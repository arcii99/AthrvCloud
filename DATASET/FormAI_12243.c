//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 50

bool containsUpperCase(char* password){
    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i])){
            return true;
        }
    }
    return false;
}

bool containsLowerCase(char* password){
    for(int i = 0; i < strlen(password); i++){
        if(islower(password[i])){
            return true;
        }
    }
    return false;
}

bool containsNumbers(char* password){
    for(int i = 0; i < strlen(password); i++){
        if(isdigit(password[i])){
            return true;
        }
    }
    return false;
}

bool containsSpecialChars(char* password){
    for(int i = 0; i < strlen(password); i++){
        if(!(isalnum(password[i]))){
            return true;
        }
    }
    return false;
}

bool checkPasswordStrength(char* password){
    bool isStrong = true;
    int strengthScore = 0;

    if(strlen(password) < 8){
        isStrong = false;
        printf("Password is too short.\n");
    }

    if(containsUpperCase(password)){
        strengthScore++;
    }else{
        isStrong = false;
        printf("Password must contain at least one uppercase letter.\n");
    }

    if(containsLowerCase(password)){
        strengthScore++;
    }else{
        isStrong = false;
        printf("Password must contain at least one lowercase letter.\n");
    }

    if(containsNumbers(password)){
        strengthScore++;
    }else{
        isStrong = false;
        printf("Password must contain at least one number.\n");
    }

    if(containsSpecialChars(password)){
        strengthScore++;
    }else{
        isStrong = false;
        printf("Password must contain at least one special character.\n");
    }

    if(isStrong){
        printf("Password is strong!\n");
        printf("Strength score: %d\n",strengthScore);
        return true;
    }else{
        return false;
    }
}

int main(){
    char inputPassword[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    fgets(inputPassword, MAX_PASSWORD_LENGTH, stdin);

    // remove newline character from inputPassword
    inputPassword[strcspn(inputPassword, "\n")] = 0;

    checkPasswordStrength(inputPassword);

    return 0;
}