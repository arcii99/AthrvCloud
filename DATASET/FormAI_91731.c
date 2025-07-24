//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>

int main() {
    char password[15];
    int length, upper = 0, lower = 0, digit = 0, special = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);
    if (length < 8) {
        printf("Your password is too short!\n");
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        } else {
            special++;
        }
    }
    if (upper == 0) {
        printf("Your password should contain at least one uppercase letter!\n");
        return 0;
    }
    if (lower == 0) {
        printf("Your password should contain at least one lowercase letter!\n");
        return 0;
    }
    if (digit == 0) {
        printf("Your password should contain at least one digit!\n");
        return 0;
    }
    if (special == 0) {
        printf("Your password should contain at least one special character!\n");
        return 0;
    }
    printf("Password strength OK.\n");
    return 0;
}