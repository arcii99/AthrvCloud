//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int upper = 0, lower = 0, digit = 0, special = 0;
    int i, score;

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i]))
            ++upper;
        else if (islower(password[i]))
            ++lower;
        else if (isdigit(password[i]))
            ++digit;
        else
            ++special;
    }

    score = strlen(password) + upper + lower + digit + special;
    printf("Password score: %d\n", score);

    if (score >= 100) {
        printf("Wow, you have an incredibly strong password!\n");
    } else if (score >= 80) {
        printf("Your password is very strong. Great job!\n");
    } else if (score >= 60) {
        printf("Your password is strong. Keep up the good work!\n");
    } else if (score >= 40) {
        printf("Your password is weak. Consider making it stronger.\n");
    } else {
        printf("Your password is very weak. Please create a stronger password.\n");
    }

    return 0;
}