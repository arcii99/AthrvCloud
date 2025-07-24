//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, i, num = 0, cap = 0, sym = 0;

    printf("Enter your password: ");
    fgets(password, 100, stdin);
    length = strlen(password) - 1;

    for(i=0; password[i]!='\0'; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            num++;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z') {
            cap++;
        }
        else if(password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&') {
            sym++;
        }
    }

    if(length >= 8 && num >= 1 && cap >= 1 && sym >= 1) {
        printf("Good password!\n");
    }
    else if(length < 8 && num == 0 && cap == 0 && sym == 0) {
        printf("Password is too weak! Please choose a password that is at least 8 characters long and contains at least one number, one uppercase letter, and one special character (@ # $ % &).\n");
    }
    else {
        printf("Password is weak! Please choose a password that contains at least 8 characters, one number, one uppercase letter, and one special character (@ # $ % &).\n");
    }

    return 0;
}