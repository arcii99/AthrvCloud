//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[25];
    int length, hasSpecialChar, hasNumber, hasUppercase, i;
    length = hasSpecialChar = hasNumber = hasUppercase = i = 0;

    printf("Alas, fair maiden, what doth thy secret password be?\n");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Alack! Thy password must contain at least 8 characters.\n");
    }
    
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasNumber = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' ||
                   password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            hasSpecialChar = 1;
        }
    }
    
    if (hasUppercase == 0) {
        printf("Heaven forfend! Thy password must contain at least one uppercase character.\n");
    }

    if (hasNumber == 0) {
        printf("Saints preserve us! Thy password must contain at least one numerical character.\n");
    }
    
    if (hasSpecialChar == 0) {
        printf("Oh sweet sorrow! Thy password must contain at least one of these special characters: !@#$%%^&*\n");
    }

    if (length >= 8 && hasUppercase == 1 && hasNumber == 1 && hasSpecialChar == 1) {
        printf("Huzzah! Thy password is strong enough to protect thy sensitive data.\n");
    }

    return 0;
}