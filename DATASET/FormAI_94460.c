//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

int main() {
    char password[PASSWORD_LENGTH + 1]; // +1 for '\0'
    const char symbols[] = "!@#$%^&*()_+{}[]|'\"/?><,.:;-=`~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

    srand(time(NULL));
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = symbols[rand() % sizeof(symbols)];
    }
    password[PASSWORD_LENGTH] = '\0';

    printf("The secure password is: %s\n", password);
    
    return 0;
}