//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REQUIRED_LENGTH 8
#define MAX_LENGTH 50

bool checkUppercase(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        if(s[i]>=65 && s[i]<=90) return true;
    }
    return false;
}

bool checkLowercase(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        if(s[i]>=97 && s[i]<=122) return true;
    }
    return false;
}

bool checkSpecialCharacter(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        if((s[i]>=33 && s[i]<=47) 
            || (s[i]>=58 && s[i]<=64) 
            || (s[i]>=91 && s[i]<=96) 
            || (s[i]>=123 && s[i]<=126)) return true;
    }
    return false;
}

bool checkNumeric(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        if(s[i]>=48 && s[i]<=57) return true;
    }
    return false;
}

bool checkPasswordStrength(char password[]) {
    int passwordLength = strlen(password);
    if(passwordLength < REQUIRED_LENGTH) {
        printf("Password length must be at least %d characters\n", REQUIRED_LENGTH);
        return false;
    }
    
    bool hasUppercase = checkUppercase(password);
    bool hasLowercase = checkLowercase(password);
    bool hasSpecialCharacter = checkSpecialCharacter(password);
    bool hasNumeric = checkNumeric(password);
    
    if(!hasUppercase || !hasLowercase || !hasSpecialCharacter || !hasNumeric) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one special character, and one numeric digit\n");
        return false;
    }
    
    return true;
}

void async_checkPasswordStrength(char* password) {
    printf("Processing password...\n");
    sleep(2);
    printf("Result: ");
    if(checkPasswordStrength(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }
}

int main() {
    char password[MAX_LENGTH];
    
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;
    
    async_checkPasswordStrength(password);

    return 0;
}