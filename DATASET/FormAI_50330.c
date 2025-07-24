//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASS_LENGTH 15

// Function to generate a secure password
void generatePassword(char *password, int passwordLength) {
    char allCharacters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    srand(time(NULL));

    for (i = 0; i < passwordLength; i++) {
        password[i] = allCharacters[rand() % strlen(allCharacters)];
    }

    password[passwordLength] = '\0';
}

int main() {
    char password[PASS_LENGTH + 1];

    printf("Generating a secure password...\n");

    // Generate password
    generatePassword(password, PASS_LENGTH);

    printf("Generated Password: %s\n", password);

    return 0;
}