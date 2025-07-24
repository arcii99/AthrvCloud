//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include<stdio.h>
#include<string.h>

int checkPassword(char password[]){

    int length = strlen(password);
    int upperCount = 0, lowerCount = 0, specialCount = 0, digitCount = 0; 
    int strength = 0;

    for(int i=0; i<length; i++){
        char ch = password[i];
        if(isupper(ch))    upperCount++;
        if(islower(ch))    lowerCount++;
        if(isdigit(ch))    digitCount++;
        if(ch == '@' || ch == '#' || ch == '$')    specialCount++;
    }

    if(upperCount > 0)      strength++;
    if(lowerCount > 0)      strength++;
    if(digitCount > 0)      strength++;
    if(specialCount > 0)    strength++;

    return strength;
}

int main(){
    char password[50];

    printf("Enter password: ");
    scanf("%s", password);

    int strength = checkPassword(password);

    if(strength == 0){
        printf("Password must contain atleast one uppercase letter, one lowercase letter, one special character(@#$) and one digit");
    }
    else if(strength < 3){
        printf("Weak Password");
    }
    else if(strength == 3){
        printf("Medium Password");
    }
    else{
        printf("Strong Password");
    }

    return 0;
}