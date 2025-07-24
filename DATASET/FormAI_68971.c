//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASS_LENGTH 20

void generatePassword(char *password, int length);
int randomNumberInRange(int min, int max);

int main() {
    char password[MAX_PASS_LENGTH];
    int length;

    printf("Enter password length (1-%d): ", MAX_PASS_LENGTH);
    scanf("%d", &length);

    if (length < 1 || length > MAX_PASS_LENGTH) {
        printf("Password length must be between 1 and %d.\n", MAX_PASS_LENGTH);
        return 1;
    }

    generatePassword(password, length);

    printf("Your generated password is: %s\n", password);

    return 0;
}

void generatePassword(char *password, int length) {
    int i;
    char characters[72] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+[]{}\\|;:',.<>/?";
    int charsLength = sizeof(characters) - 1;

    srand((unsigned int)time(NULL));

    for (i = 0; i < length; i++) {
        int randIndex = randomNumberInRange(0, charsLength);
        password[i] = characters[randIndex];
    }

    password[length] = '\0';
}

int randomNumberInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}