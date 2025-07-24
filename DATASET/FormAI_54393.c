//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main(void) {
    
    char password[PASSWORD_LENGTH + 1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+={}[]<>?,.";

    srand(time(NULL));
    
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int index = rand() % (int) sizeof(charset - 1);
        password[i] = charset[index];
    }
    
    password[PASSWORD_LENGTH] = '\0';
    
    printf("Your cryptic password is: %s\n", password);
    
    return 0;
}