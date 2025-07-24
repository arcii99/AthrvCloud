//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 12

int main() {
    char charset[63] = "0123456789"
                        "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char password[LENGTH + 1];
    srand(time(NULL));

    printf("Generating a secure password...\n\n");
    for(int i = 0; i < LENGTH; i++) {
        password[i] = charset[rand() % 62];
    }
    password[LENGTH] = '\0';

    printf("Your password is: %s\n", password);

    return 0;
}