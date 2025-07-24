//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    int len = strlen(password);
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasNumber = false;
    bool hasSpecialChar = false;

    for(int i=0; i<len; i++) {
        char c = password[i];

        if(c >= 'A' && c <= 'Z') {
            hasUpperCase = true;
        } else if(c >= 'a' && c <= 'z') {
            hasLowerCase = true;
        } else if(c >= '0' && c <= '9') {
            hasNumber = true;
        } else {
            hasSpecialChar = true;
        }
    }

    printf("\nPassword strength: ");

    if(len >= 8 && hasUpperCase && hasLowerCase && hasNumber && hasSpecialChar) {
        printf("STRONG");
    } else if(len >= 6 && hasUpperCase && hasLowerCase && hasNumber) {
        printf("MEDIUM");
    } else {
        printf("WEAK");
    }

    printf("\n");
    return 0;
}