//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50  
#define STRENGTH_STR_SIZE 20  
#define MAX_TRIES 3  

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int count_digits(char* s) {
    int n_digits = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(*(s + i))) {
            n_digits++;
        }
    }
    return n_digits;
}

int count_uppercase(char* s) {
    int n_upper = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(*(s + i))) {
            n_upper++;
        }
    }
    return n_upper;
}

int password_strength(char* password) {
    int length = strlen(password);
    int n_digits = count_digits(password);
    int n_uppercase = count_uppercase(password);
    
    if (length < 8) {
        return 1;
    }
    else if (length < 12) {
        if (n_digits > 0 && n_uppercase > 0) {
            return 3;
        }
        else if (n_digits > 0 || n_uppercase > 0) {
            return 2;
        }
        else {
            return 1;
        }
    }
    else {
        if (n_digits > 0 && n_uppercase > 0) {
            return 4;
        }
        else if (n_digits > 0 || n_uppercase > 0) {
            return 3;
        }
        else {
            return 2;
        }
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char strength_str[STRENGTH_STR_SIZE];
    int tries_left = MAX_TRIES;
    int strength;

    printf("Welcome to the Password Strength Checker Program.\n");
    printf("You have %d tries left to enter a strong password.\n", tries_left);
    do {
        printf("Please enter your password: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = 0;  
        strength = password_strength(password);
        switch (strength) {
            case 1:
                strcpy(strength_str, "Weak");
                break;
            case 2:
                strcpy(strength_str, "Moderate");
                break;
            case 3:
                strcpy(strength_str, "Strong");
                break;
            case 4:
                strcpy(strength_str, "Very Strong");
                break;
        }
        if (strength < 3) {
            tries_left--;
            printf("Your password strength is %s. Try again.\n", strength_str);
            if (tries_left > 0) {
                printf("You have %d tries left.\n", tries_left);
            }
        }
        else {
            printf("Congratulations, your password strength is %s!\n", strength_str);
            break;
        }
    } while (tries_left > 0);
    if (tries_left == 0) {
        printf("You have exceeded the maximum number of tries. Exiting program.\n");
    }
    return 0;
}