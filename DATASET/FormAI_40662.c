//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length) {
    char password[length];
    srand(time(NULL));

    for(int i = 0; i < length; i++) {
        int random = rand() % 3;

        if(random == 0) {
            password[i] = rand() % 10 + '0'; // numbers
        } else if(random == 1) {
            password[i] = rand() % 26 + 'A'; // uppercase letters
        } else {
            password[i] = rand() % 26 + 'a'; // lowercase letters
        }
    }

    printf("Your secure password: %s\n", password);
}

int main() {
    printf("Welcome to the Secure Password Generator!\n");

    int length;

    do {
        printf("Enter desired length of password (must be at least 8 characters): ");
        scanf("%d", &length);
    } while(length < 8);

    generatePassword(length);

    return 0;
}