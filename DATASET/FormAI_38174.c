//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check if the user entered password match 
// with the actual password
int checkPass(char *pass, char *actualPass){
    if(strcmp(pass, actualPass) == 0){
        printf("Password verified! Login successful.\n");
        return 1;
    }
    printf("Invalid password, please enter the correct password.\n");
    return 0;
}

// function to prompt the user for password
void enterPass(char *actualPass){
    printf("Enter your password to login: ");
    char *input = malloc(50*sizeof(char));
    fgets(input, 50, stdin);
    if(input[strlen(input)-1] == '\n'){
        input[strlen(input)-1] = '\0';
    }
    if(checkPass(input, actualPass) == 0){
        enterPass(actualPass);
    }
}

// main function
int main(){
    char *realPass = "12345";       // this is the actual password
    printf("***Welcome to Password Management System***\n");
    enterPass(realPass);            // calling the enterPass function
    return 0;
}