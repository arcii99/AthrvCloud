//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[30];
    int len, i;
    int upper = 0, lower = 0, digit = 0, specChar = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    len = strlen(password);
    if (len < 8) {
        printf("Password length should be at least 8 characters.\n");
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (isupper(password[i]))
            upper++;
        else if (islower(password[i]))
            lower++;
        else if (isdigit(password[i]))
            digit++;
        else
            specChar++;
    }
    printf("Your password contains:\n");
    printf("%d uppercase letters\n", upper);
    printf("%d lowercase letters\n", lower);
    printf("%d digits\n", digit);
    printf("%d special characters\n", specChar);

    if (upper && lower && digit && specChar)
        printf("Your password is very strong!\n");
    else if (upper && lower && digit)
        printf("Your password is strong.\n");
    else if (upper && lower)
        printf("Your password is medium-strength.\n");
    else
        printf("Your password is weak. Please use a stronger password.\n");
    return 0;
}