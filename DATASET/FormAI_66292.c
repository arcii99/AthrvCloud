//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

char* generate_password(void);

int main(void) {
    char* password = generate_password();

    printf("Secure Password: %s\n", password);
    free(password);
    return 0;
}

char* generate_password(void) {
    char* password = malloc(PASSWORD_LENGTH * sizeof(char));
    srand(time(NULL));

    for(int i = 0; i < PASSWORD_LENGTH; i++) {
        int rand_num = rand() % 3;

        switch(rand_num) {
            case 0: // Generate random lowercase letter
                password[i] = 'a' + (rand() % 26);
                break;
            case 1: // Generate random uppercase letter
                password[i] = 'A' + (rand() % 26);
                break;
            case 2: // Generate random number
                password[i] = '0' + (rand() % 10);
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Add null terminator
    return password;
}