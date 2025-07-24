//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char password[50];
    int length, hasUpper = 0, hasLower = 0, hasNumber = 0, hasSpecialChar = 0;

    printf("Enter Password (maximum 50 characters): ");
    fgets(password, 50, stdin);

    length = strlen(password) - 1;
    if(length < 6 || length > 20){
        printf("Password length must be between 6 and 20 characters.\n");
        return 0;
    }

    for(int i = 0; i < length; i++){
        if(isupper(password[i])) hasUpper = 1;
        else if(islower(password[i])) hasLower = 1;
        else if(isdigit(password[i])) hasNumber = 1;
        else if(!isalpha(password[i]) && !isdigit(password[i])) hasSpecialChar = 1;
    }

    if(hasUpper && hasLower && hasNumber && hasSpecialChar){
        printf("Strong Password!\n");
    } else {
        printf("Weak Password!\n");
    }

    return 0;
}