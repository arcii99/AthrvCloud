//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 20

void generatePassword(char *password);

int main(){
    char password[PASSWORD_LENGTH + 1];
    srand(time(NULL));
    generatePassword(password);
    printf("Generated Password: %s\n", password);
    return 0;
}

void generatePassword(char *password){
    int i, randomNum, upper, lower, digit, special;
    char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:\"<>?-=[]\;',./";
    upper = lower = digit = special = 0;
    for(i = 0; i < PASSWORD_LENGTH; i++){
        randomNum = rand() % strlen(charSet);
        password[i] = charSet[randomNum];
        if(password[i] >= 'A' && password[i] <= 'Z'){
            upper = 1;
        }
        else if(password[i] >= 'a' && password[i] <= 'z'){
            lower = 1;
        }
        else if(password[i] >= '0' && password[i] <= '9'){
            digit = 1;
        }
        else{
            special = 1;
        }
    }
    if(!(upper & lower & digit & special)){
        generatePassword(password);
    }
    password[PASSWORD_LENGTH] = '\0';
}