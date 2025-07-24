//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char* generatePassword() {
    char* password = malloc(sizeof(char) * PASSWORD_LENGTH);
    int i;
    char c;

    srand((unsigned) time(NULL));
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        do {
            c = rand() % 122 + 1;
        } while (!isdigit(c) && !isalpha(c) && c != '$' && c != '#');
        password[i] = c;
    }

    password[i] = '\0';
    return password;
}

int main() {
    char* password;

    printf("Generating a secure password...\n");
    password = generatePassword();
    printf("Your secure password is: %s\n", password);

    free(password);
    return 0;
}