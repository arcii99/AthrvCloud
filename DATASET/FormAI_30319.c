//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

void generatePassword(char *password);

int main()
{
    char password[PASSWORD_LENGTH + 1];
    generatePassword(password);
    printf("Generated Password: %s \n", password);
    return 0;
}

void generatePassword(char *password)
{
    int i, randomIndex, randomNumber;
    char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    srand(time(NULL));

    for(i=0; i<PASSWORD_LENGTH; i++) {
        randomIndex = rand() % strlen(charSet);
        randomNumber = rand() % 26;

        password[i] = charSet[randomIndex];

        if(i == 0 || i == 3 || i == 6) {
            password[i] = 'A' + randomNumber;
        }
        if(i == 1 || i == 4 || i == 7) {
            password[i] = 'a' + randomNumber;
        }
        if(i == 2 || i == 5 || i == 8) {
            password[i] = '0' + randomNumber;
        }
    }

    password[PASSWORD_LENGTH] = '\0';
}