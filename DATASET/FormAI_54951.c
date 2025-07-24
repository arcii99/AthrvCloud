//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {
    char password[PASSWORD_LENGTH + 1];
    // Set of characters to choose from
    char *character_set = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*";
    srand(time(NULL)); // Initialize random seed

    printf("Your secure password:\n");
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = character_set[rand() % (int)(sizeof(character_set) - 1)];
        printf("%c", password[i]);
    }
    password[PASSWORD_LENGTH] = '\0'; // Set end of string character
    printf("\n");

    return 0;
}