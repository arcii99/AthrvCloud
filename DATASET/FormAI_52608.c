//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define LENGTH 20

void password_check(char password[]);

int main(){
    char password[LENGTH];   // Password string
    
    printf("Welcome to Password Strength Checker!\n\n");
    printf("Please enter your password: ");
    fgets(password, LENGTH, stdin);   // Read password
    
    password_check(password);   // Call password checker function
    
    return 0;
}

void password_check(char password[]){
    int strength = 0, digits = 0, uppercase = 0, lowercase = 0, symbols = 0;
    
    // Check password length
    if(strlen(password) >= 8){
        strength++;
    }
    
    // Check for digits, uppercase, lowercase, and symbols
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            digits++;
        }
        else if(isupper(password[i])){
            uppercase++;
        }
        else if(islower(password[i])){
            lowercase++;
        }
        else{
            symbols++;
        }
    }
    
    if(digits > 0){
        strength++;
    }
    if(uppercase > 0){
        strength++;
    }
    if(lowercase > 0){
        strength++;
    }
    if(symbols > 0){
        strength++;
    }
    
    // Print password strength
    printf("\nYour password strength is: ");
    switch(strength){
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
            printf("Very Strong\n");
            break;
        default:
            printf("Error\n");
    }
}