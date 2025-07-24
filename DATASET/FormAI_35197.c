//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char password[100];
    int length, i, has_uppercase, has_lowercase, has_digit, has_special;
    printf("Enter a password:");
    scanf("%s", password);

    length = strlen(password);
    has_uppercase = has_lowercase = has_digit = has_special = 0;

    for(i = 0; i < length; i++){
        if(isupper(password[i]))
            has_uppercase = 1;

        if(islower(password[i]))
            has_lowercase = 1;

        if(isdigit(password[i]))
            has_digit = 1;

        if(!isalnum(password[i]))
            has_special = 1;
    }

    if(length < 8 || length > 12){
        printf("Length should be between 8 to 12 characters.\n");
    }

    if(has_uppercase && has_lowercase && has_digit && has_special){
        printf("Password strength is strong.\n");
    }
    else{
        printf("Password strength is weak.\n");
        if(!has_uppercase){
            printf("Password should contain at least one uppercase letter.\n");
        }
        if(!has_lowercase){
            printf("Password should contain at least one lowercase letter.\n");
        }
        if(!has_digit){
            printf("Password should contain at least one digit.\n");
        }
        if(!has_special){
            printf("Password should contain at least one special character.\n");
        }
    }
    return 0;
}