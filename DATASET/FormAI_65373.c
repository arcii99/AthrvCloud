//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {
    char password[PASSWORD_LENGTH + 1];
    int i, random_number;

    srand((unsigned int) time(NULL));

    printf("Generating secure password...\n");
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        random_number = rand() % 94 + 33;
        password[i] = (char) random_number;
    }
    password[PASSWORD_LENGTH] = '\0';

    printf("Your new password is: %s\n", password);
    return 0;
}