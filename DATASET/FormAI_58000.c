//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

char* generatePassword() {
    char* password = malloc(PASSWORD_LENGTH + 1);
    int i, randNum;
    srand(time(NULL));
    
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        randNum = rand() % 62;
        if (randNum < 26) {
            password[i] = 'A' + randNum;
        } else if (randNum < 52) {
            password[i] = 'a' + (randNum - 26);
        } else {
            password[i] = '0' + (randNum - 52);
        }
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int main() {
    char* password = generatePassword();
    printf("Generated password: %s", password);
    free(password);
    return 0;
}