//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main(){

    char password[20];
    int password_length;
    int uppercase=0, lowercase=0, numbers=0, symbols=0;

    printf("Enter the password: ");
    fgets(password, 20, stdin);
    password_length = strlen(password) - 1;

    if(password_length < 8){
        printf("Weak Password Length. Try Again with at least 8 characters\n");
        return 0;
    }

    for(int i = 0; i < password_length; i++){
        if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lowercase++;
        else if(password[i] >= '0' && password[i] <= '9')
            numbers++;
        else
            symbols++;
    }

    if(uppercase == 0 || lowercase == 0 || numbers == 0 || symbols == 0){
        printf("Weak Password. Must include UpperCase, LowerCase, Numbers and Symbols\n");
        return 0;
    }

    printf("Strong Password\n");
    return 0;
}