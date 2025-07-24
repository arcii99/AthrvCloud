//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 40
#define MIN_LEN 8

void generatePassword(char* password);

int main()
{
    char password[MAX_LEN+1];
    srand(time(NULL));
    generatePassword(password);
    printf("Generated Password: %s\n", password);

    return 0;
}

void generatePassword(char* password)
{
    for (int i = 0; i < MAX_LEN; i++) {
        int r = rand() % 94;
        password[i] = r + 33;
    }

    // Make sure the password is at least MIN_LEN characters long
    while (strlen(password) < MIN_LEN) {
        int r = rand() % MAX_LEN;
        password[r] = rand() % 94 + 33;
    }

    password[MAX_LEN] = '\0';
}