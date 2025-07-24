//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

int main() {
    char password[PASSWORD_LENGTH + 1];
    int i, random_num;

    srand(time(NULL));

    printf("Generating random secure password...\n");

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        random_num = rand() % 62;

        if (random_num < 10) {
            password[i] = random_num + '0';
        } else if (random_num < 36) {
            password[i] = random_num - 10 + 'a';
        } else {
            password[i] = random_num - 36 + 'A';
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("Your password is: %s\n", password);

    return 0;
}