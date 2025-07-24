//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    int passwordStrength = 0;
    char password[50];
    printf("Enter a password:\n");
    scanf("%[^\n]%*c", password);

    //check password length
    if(strlen(password) >= 8) {
        passwordStrength++;
    }

    //check for uppercase letters
    for(int i = 0; i < strlen(password); i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            passwordStrength++;
            break;
        }
    }

    //check for lowercase letters
    for(int i = 0; i < strlen(password); i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            passwordStrength++;
            break;
        }
    }

    //check for digits
    for(int i = 0; i < strlen(password); i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            passwordStrength++;
            break;
        }
    }

    //check for special characters
    char specialCharacters[] = "!@#$%^&*()_+{}|:<>?-=[]\\;,./";
    for(int i = 0; i < strlen(password); i++) {
        for(int j = 0; j < strlen(specialCharacters); j++) {
            if(password[i] == specialCharacters[j]) {
                passwordStrength++;
                break;
            }
        }
        if(passwordStrength > 4) {
            break;
        }
    }

    //output password strength
    switch(passwordStrength) {
        case 0:
        case 1:
        case 2:
            printf("Password too weak\n");
            break;
        case 3:
            printf("Password is moderate\n");
            break;
        case 4:
            printf("Password is strong\n");
            break;
        case 5:
            printf("Password is very strong\n");
            break;
    }

    return 0;
}