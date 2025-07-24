//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkLength(char password[]);
int checkUpperCase(char password[]);
int checkLowerCase(char password[]);
int checkDigit(char password[]);
int checkSpecialChar(char password[]);

int main() {
    char password[50];
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    if(checkLength(password) && checkUpperCase(password) && checkLowerCase(password)
        && checkDigit(password) && checkSpecialChar(password)) {
        printf("Congratulations! Your password is strong.\n");
    } else {
        printf("Sorry, your password does not meet the minimum requirement.\n");
    }

    return 0;
}

int checkLength(char password[]) {
    int length = strlen(password);
    if(length < 8 || length > 15) {
        printf("Your password must be at least 8 characters and not more than 15 characters.\n");
        return 0;
    }
    return 1;
}

int checkUpperCase(char password[]) {
    int i;
    for(i=0; password[i]!='\0'; i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    printf("Your password must have at least one uppercase letter.\n");
    return 0;
}

int checkLowerCase(char password[]) {
    int i;
    for(i=0; password[i]!='\0'; i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    printf("Your password must have at least one lowercase letter.\n");
    return 0;
}

int checkDigit(char password[]) {
    int i;
    for(i=0; password[i]!='\0'; i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    printf("Your password must have at least one digit.\n");
    return 0;
}

int checkSpecialChar(char password[]) {
    int i;
    for(i=0; password[i]!='\0'; i++) {
        if(!(isalnum(password[i]))) {
            return 1;
        }
    }
    printf("Your password must have at least one special character.\n");
    return 0;
}