//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

char* generatePassword(int length) {
    srand(time(NULL));
    char *password = malloc(sizeof(char) * length + 1);
    const char characterSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+|}{[]\\/';:,.<>?`~";
    for(int i=0; i<length; i++) {
        password[i] = characterSet[rand()%sizeof(characterSet)];
    }
    password[length] = '\0';
    return password;
}

int main(void) {
    printf("Welcome to the Secure Password Generator!\n");
    printf("How many passwords would you like to generate? ");

    int numPasswords;
    scanf("%d", &numPasswords);

    for (int i=0; i<numPasswords; i++) {
        printf("Your secure password is: %s\n", generatePassword(PASSWORD_LENGTH));
    }

    printf("Thank you for using the Secure Password Generator!\n");
    return 0;
}