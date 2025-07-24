//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*Function prototypes*/
void checkLength(char password[]);
void checkLower(char password[]);
void checkUpper(char password[]);
void checkDigits(char password[]);
void checkSpecial(char password[]);

int main()
{
    char password[100];
    printf("Welcome to Password Strength Checker!\n");
    printf("Please enter your password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0; //Removing the newline character from the input
    
    /*Checking the password strength*/
    checkLength(password);
    checkLower(password);
    checkUpper(password);
    checkDigits(password);
    checkSpecial(password);

    return 0;
}

void checkLength(char password[])
{
    int len = strlen(password);
    printf("Your password length: %d\n", len);
    if(len<8){
        printf("Your password is weak because it does not meet the minimum length requirement.\n");
    }
    else{
        printf("Your password meets the length requirement.\n");
    }
}

void checkLower(char password[])
{
    int len = strlen(password);
    int i, count=0;
    for(i=0;i<len;i++){
        if(islower(password[i])){
            count++;
            break;
        }
    }
    if(count==0){
        printf("Your password is weak because it does not contain any lowercase letters.\n");
    }
    else{
        printf("Your password meets the lowercase requirement.\n");
    }
}

void checkUpper(char password[])
{
    int len = strlen(password);
    int i, count=0;
    for(i=0;i<len;i++){
        if(isupper(password[i])){
            count++;
            break;
        }
    }
    if(count==0){
        printf("Your password is weak because it does not contain any uppercase letters.\n");
    }
    else{
        printf("Your password meets the uppercase requirement.\n");
    }
}

void checkDigits(char password[])
{
    int len = strlen(password);
    int i, count=0;
    for(i=0;i<len;i++){
        if(isdigit(password[i])){
            count++;
            break;
        }
    }
    if(count==0){
        printf("Your password is weak because it does not contain any digits.\n");
    }
    else{
        printf("Your password meets the digit requirement.\n");
    }
}

void checkSpecial(char password[])
{
    int len = strlen(password);
    int i, count=0;
    for(i=0;i<len;i++){
        if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='&' || password[i]=='*'){
            count++;
            break;
        }
    }
    if(count==0){
        printf("Your password is weak because it does not contain any special characters.\n");
    }
    else{
        printf("Your password meets the special character requirement.\n");
    }
}