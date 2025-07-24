//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 10

char* generate_password() {
    char* password = malloc(sizeof(char) * PASSWORD_LENGTH);

    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=";

    char allChars[] = {0};
    strcat(allChars, lowercase);
    strcat(allChars, uppercase);
    strcat(allChars, numbers);
    strcat(allChars, symbols);

    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int index = rand() % strlen(allChars);
        password[i] = allChars[index];
    }

    return password;
}

int main() {
    char* password = generate_password();

    printf("Generated Password: %s\n", password);

    free(password);

    return 0;
}