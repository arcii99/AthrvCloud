//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16

char* generatePassword();

int main() {
    char* password = generatePassword();
    printf("Your secure password is: %s", password);

    free(password);
    return 0;
}

char* generatePassword() {
    char* symbols = "!@#$%^&*()_+{}:<>?[];',./";
    char* lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
    char* uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = "0123456789";
    char* password = (char*) malloc(sizeof(char) * PASSWORD_LENGTH + 1);
    srand(time(NULL));

    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int random = rand() % 4;

        switch (random) {
            case 0:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
            case 1:
                password[i] = lowercaseLetters[rand() % strlen(lowercaseLetters)];
                break;
            case 2:
                password[i] = uppercaseLetters[rand() % strlen(uppercaseLetters)];
                break;
            case 3:
                password[i] = numbers[rand() % strlen(numbers)];
                break;
        }
    }

    password[i] = '\0';
    return password;
}