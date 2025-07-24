//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#define MINIMUM_PASSWORD_LENGTH 8

bool containsLowerCase(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            return true;
    }
    return false;
}

bool containsUpperCase(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            return true;
    }
    return false;
}

bool containsNumeric(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= '0' && str[i] <= '9')
            return true;
    }
    return false;
}

bool containsSpecialChar(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= '!' && str[i] <= '/')
            return true;
        else if(str[i] >= ':' && str[i] <= '@')
            return true;
        else if(str[i] >= '[' && str[i] <= '`')
            return true;
        else if(str[i] >= '{' && str[i] <= '~')
            return true;
    }
    return false;
}

void* passwordStrengthChecker(void *password) {
    char *pwd = (char *) password;
    int pwdStrength = 0;

    if(strlen(pwd) < MINIMUM_PASSWORD_LENGTH) {
        pwdStrength = -1;
        printf("[%ld] Password length is less than %d.\n", pthread_self(), MINIMUM_PASSWORD_LENGTH);
    } else {
        if(!containsLowerCase(pwd))
            pwdStrength++;
        if(!containsUpperCase(pwd))
            pwdStrength++;
        if(!containsNumeric(pwd))
            pwdStrength++;
        if(!containsSpecialChar(pwd))
            pwdStrength++;

        switch(pwdStrength) {
            case 0:
                printf("[%ld] Password strength is Excellent.\n", pthread_self());
                break;
            case 1:
                printf("[%ld] Password strength is Good.\n", pthread_self());
                break;
            case 2:
                printf("[%ld] Password strength is Weak.\n", pthread_self());
                break;
            case 3:
                printf("[%ld] Password strength is Very Weak.\n", pthread_self());
                break;
            default:
                printf("[%ld] Error.\n", pthread_self());
        }
    }
    pthread_exit(NULL);
}

int main() {
    char password1[] = "ThisIsAWeakPassword";
    char password2[] = "Strong#Password123";
    char password3[] = "ShortPass!";

    pthread_t threads[3];
    pthread_create(&threads[0], NULL, passwordStrengthChecker, (void *) password1);
    pthread_create(&threads[1], NULL, passwordStrengthChecker, (void *) password2);
    pthread_create(&threads[2], NULL, passwordStrengthChecker, (void *) password3);

    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}