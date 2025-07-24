//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

char* generate_password();

int main() {
    char* password = generate_password();
    printf("Your new password is: %s\n", password);
    free(password);
    return 0;
}

char* generate_password() {
    srand(time(NULL));
    char* password = malloc((PASSWORD_LENGTH + 1) * sizeof(char));
    int i, rand_num;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        rand_num = rand() % 3;

        switch (rand_num) {
            case 0:
                password[i] = 'a' + rand() % 26;
                break;
            case 1:
                password[i] = 'A' + rand() % 26;
                break;
            case 2:
                password[i] = '0' + rand() % 10;
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}