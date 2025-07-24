//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void generatePassword(int length){
    char symbols[] = "!@#$%^&*()_+{}[];:<>,.?/~`";
    char numbers[] = "0123456789";
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char password[length+1];
    int i, r;
    srand(time(NULL)); //initialize random seed

    //generate random password
    for(i=0; i<length; i++){
        r = rand()%4; //generate random number between 0-3
        if(r == 0){ //add symbol
            password[i] = symbols[rand()%strlen(symbols)];
        }
        else if(r == 1){ //add number
            password[i] = numbers[rand()%strlen(numbers)];
        } 
        else if(r == 2){ //add lowercase letter
            password[i] = letters[rand()%26];
        }
        else if(r == 3){ //add uppercase letter
            password[i] = letters[rand()%26+26];
        }
    }
    password[length] = '\0'; //null terminate password

    //print generated password
    printf("Generated Password: %s\n", password);
}


int main(){
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);
    while(length<8){
        printf("Password length must be at least 8. Enter password length again: ");
        scanf("%d", &length);
    }
    generatePassword(length);
    return 0;
}