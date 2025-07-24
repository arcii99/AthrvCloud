//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8

char generateCharacter() {
    int r = rand() % 94 + 33; // ASCII characters 33-126
    return (char) r;
}

int main() {
    srand(time(NULL)); // set seed for randomization

    char password[MAX_LENGTH];
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH; // generate length of password between min and max

    for (int i = 0; i < length; i++) {
        password[i] = generateCharacter(); // generate random characters for password
    }
    password[length] = '\0'; // terminate string

    printf("Your Cyberpunk Style Password: %s\n", password);

    return 0;
}