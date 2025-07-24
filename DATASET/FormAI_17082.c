//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 40

int main() {
    char password[MAX_LEN+1], ch;
    int len = 0, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter your password: ");

    while ((ch = getchar()) != '\n') {
        if (len >= MAX_LEN) {
            printf("Password too long. Maximum %d characters allowed.\n", MAX_LEN);
            return 1;
        }
        password[len++] = ch;
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
        else if (isdigit(ch))
            digit++;
        else if (!isspace(ch))
            special++;
    }
    password[len] = '\0';

    if (len < MIN_LEN) {
        printf("Password too short. Minimum %d characters required.\n", MIN_LEN);
        return 1;
    }

    if (upper < 1) {
        printf("Password too weak. It must contain at least one uppercase letter.\n");
        return 1;
    }

    if (lower < 1) {
        printf("Password too weak. It must contain at least one lowercase letter.\n");
        return 1;
    }

    if (digit < 1) {
        printf("Password too weak. It must contain at least one digit.\n");
        return 1;
    }

    if (special < 1) {
        printf("Password too weak. It must contain at least one special character.\n");
        return 1;
    }

    printf("Password strength is strong.\n");

    return 0;
}