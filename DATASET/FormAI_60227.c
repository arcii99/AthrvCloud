//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char password[100];
    int length, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin); // Scans for entire line including spaces

    length = strlen(password) - 1; // Excluding the newline character from length

    for(int i = 0; i < length; i++){
        if(password[i] >= 65 && password[i] <= 90) upper++;
        else if(password[i] >= 97 && password[i] <= 122) lower++;
        else if(password[i] >= 48 && password[i] <= 57) digit++;
        else special++;
    }

    if(length < 8){
        printf("Password length must be at least 8 characters.\n");
        return 0;
    }

    if(upper == 0 || lower == 0 || digit == 0 || special == 0){
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        return 0;
    }

    printf("Password is strong.\n");

    return 0;
}