//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8

int main(){
    char password[100];
    int passwordLength, i, uppercaseCount = 0, lowercaseCount = 0, digitCount = 0, symbolCount = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    passwordLength = strlen(password);
    
    if(passwordLength < MIN_LENGTH){
        printf("Your password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }
    
    for(i = 0; i < passwordLength; i++){
        if(isupper(password[i])){
            uppercaseCount++;
        }
        else if(islower(password[i])){
            lowercaseCount++;
        }
        else if(isdigit(password[i])){
            digitCount++;
        }
        else{
            symbolCount++;
        }
    }
    
    printf("Password strength: ");
    if(uppercaseCount > 0 && lowercaseCount > 0 && digitCount > 0 && symbolCount > 0){
        printf("Strong\n");
    }
    else if(uppercaseCount > 0 && lowercaseCount > 0 && digitCount > 0){
        printf("Medium\n");
    }
    else{
        printf("Weak\n");
    }
    return 0;
}