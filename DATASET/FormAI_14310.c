//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Password Strength Checker!\n\n");
    printf("Please enter a password: ");

    char password[100];
    fgets(password, 100, stdin);

    int len = strlen(password) - 1;

    int upper = 0;
    int lower = 0;
    int digits = 0;
    int symbols = 0;

    for(int i = 0; i < len; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        }
        if(password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        }
        if(password[i] >= '0' && password[i] <= '9') {
            digits++;
        }
        if(password[i] >= '!' && password[i] <= '/' ||
           password[i] >= ':' && password[i] <= '@' ||
           password[i] >= '[' && password[i] <= '`' ||
           password[i] >= '{' && password[i] <= '~') {
            symbols++;
        }
    }

    int strengthScore = 0;

    if(len >= 8) {
        strengthScore += 10;
    }
    else if(len >= 4) {
        strengthScore += 5;
    }

    if(upper >= 1) {
        strengthScore += 5;
    }
    if(lower >= 1) {
        strengthScore += 5;
    }
    if(digits >= 1) {
        strengthScore += 5;
    }
    if(symbols >= 1) {
        strengthScore += 5;
    }

    printf("\nYour password received a strength score of %d out of 30.\n", strengthScore);
    printf("A score of 20 or higher is considered a strong password.\n");

    return 0;
}