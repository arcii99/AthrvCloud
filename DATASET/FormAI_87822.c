//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int score = 0;
    int length = 0;
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;
    printf("Please enter a password:\n");
    fgets(password, 100, stdin);
    length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
            score += 5;
        }
        if (islower(password[i])) {
            lowercase++;
            score += 5;
        }
        if (isdigit(password[i])) {
            number++;
            score += 5;
        }
        if (!isalnum(password[i])) {
            special++;
            score += 10;
        }
    }
    if (length >= 8) {
        score += 10;
    }
    if (length >= 12) {
        score += 10;
    }
    if (uppercase >= 1 && lowercase >= 1) {
        score += 10;
    }
    if (number >= 1 && special >= 1) {
        score += 10;
    }
    if (score >= 100) {
        printf("Your password is strong! Score: %d\n", score);
    } else {
        printf("Your password is weak. Score: %d\n", score);
    }
    return 0;
}