//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

char generatePassword() {
    char passwordCharacters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+=";
    int randomNumber = rand() % 69;
    return passwordCharacters[randomNumber];
}

int main() {
    srand(time(NULL));
    int passwordLength, i;
    char password[MAX_PASSWORD_LENGTH];

    printf("How long do you want your password to be? (Max: 20): ");
    scanf("%d", &passwordLength);

    if (passwordLength > MAX_PASSWORD_LENGTH) {
        printf("Sorry, the maximum password length is 20.\n");
        return 1;
    }

    for (i = 0; i < passwordLength; i++) {
        password[i] = generatePassword();
    }
    password[i] = '\0';

    printf("Your secure password is: %s\n", password);

    return 0;
}