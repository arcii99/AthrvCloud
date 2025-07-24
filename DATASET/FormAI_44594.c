//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_LETTER 97
#define UPPER_LETTER 65
#define NUMBER 48
#define SYMBOL_START 33
#define SYMBOL_END 47

int main() {
    int password_length;
    printf("Welcome to the Secure Password Generator!\n");
    printf("How long would you like your password to be? (Minimum of 8 characters): ");
    scanf("%d", &password_length);

    while (password_length < 8) {
        printf("That password length is too short! Please enter a length of at least 8 characters: ");
        scanf("%d", &password_length);
    }

    srand(time(NULL));

    printf("Your password is: ");
    for (int i = 0; i < password_length; i++) {
        int random_num = rand() % 4;

        if (random_num == 0) {
            printf("%c", rand() % 26 + LOWER_LETTER);
        } else if (random_num == 1) {
            printf("%c", rand() % 26 + UPPER_LETTER);
        } else if (random_num == 2) {
            printf("%c", rand() % 10 + NUMBER);
        } else {
            printf("%c", rand() % (SYMBOL_END - SYMBOL_START + 1) + SYMBOL_START);
        }
    }

    printf("\n");
    return 0;
}