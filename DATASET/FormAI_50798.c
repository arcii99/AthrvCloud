//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[100];
    int i, digits = 0, lower = 0, upper = 0, special = 0;

    printf("Enter password: \n");
    fgets(password, 100, stdin);

    for(i = 0; i < strlen(password); i++){
        if(isdigit(password[i])){
            digits++;
        }
        else if(islower(password[i])){
            lower++;
        }
        else if(isupper(password[i])){
            upper++;
        }
        else{
            special++;
        }
    }

    if(strlen(password) >= 10 && digits >= 2 && lower >= 2 && upper >= 2 && special >= 2){
        printf("Elementary, my dear Watson! This is a strong password.");
    }else if(strlen(password) >= 8 && digits >= 1 && lower >= 1 && upper >= 1){
        printf("Good work, Watson! This is a moderately strong password.");
    }else{
        printf("I'm sorry, Watson, but this is a weak password. Try again.");
    }

    return 0;
}