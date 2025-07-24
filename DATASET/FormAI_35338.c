//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int password_strength(char *password);

int main(){
    char password[50];
    printf("Enter password (max 50 characters): ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0; // Removing newline character
    
    switch(password_strength(password)){
        case 0: printf("Password is very weak.\n"); break;
        case 1: printf("Password is weak.\n"); break;
        case 2: printf("Password is moderate.\n"); break;
        case 3: printf("Password is strong.\n"); break;
        case 4: printf("Password is very strong.\n"); break;
    }
    
    return 0;
}

int password_strength(char *password){
    int strength = 0;
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0;
    
    if(length >= 8){
        strength++; // At least 8 characters long
        for(int i=0; i<length; i++){
            if(isupper(password[i])) uppercase++;
            if(islower(password[i])) lowercase++;
            if(isdigit(password[i])) digits++;
            if(ispunct(password[i])) symbols++;
        }
        if(uppercase > 0 && lowercase > 0) strength++; // Both uppercase and lowercase characters
        if(digits > 0) strength++; // Contains numbers
        if(symbols > 0) strength++; // Contains special characters
        if(length >= 12) strength++; // At least 12 characters long
    }
    
    return strength;
}