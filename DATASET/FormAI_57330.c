//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char password[100];
    int len, i, digit, upper, lower, special;
    printf("Enter your password: ");
    scanf("%s", password);
    len = strlen(password);

    // Checking for length of password
    if(len < 6){
        printf("\n\nWeak Password!\n");
        printf("Password should be at least 6 characters long\n");
        return 0;
    }

    // Checking for digits, Upper and Lowercase Letters and Special Characters
    for(i = 0, digit = 0, upper = 0, lower = 0, special = 0; i < len; i++){
        if(password[i] >= '0' && password[i] <= '9'){
            digit = 1;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            upper = 1;
        }
        else if(password[i] >= 'a' && password[i] <= 'z'){
            lower = 1;
        }
        else{
            special = 1;
        }
    }

    // Checking whether the password meets all criterias
    if(digit && upper && lower && special){
        printf("\n\nStrong password!\n");
        printf("Password meets all the requirements\n");
    }
    else{
        printf("\n\nWeak Password!\n");
        printf("Password should contain at least one digit, one uppercase letter, one lowercase letter and one special character\n");
    }

    return 0;
}