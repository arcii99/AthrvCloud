//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define PASSWORD_LENGTH 10

int main()
{
    printf("Welcome to the C Secure Password Generator\n");
    printf("Generating your unique secure password...\n");
    
    char password[PASSWORD_LENGTH + 1];
    srand((unsigned int) time(NULL));
    
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|;:<>,.?/~`";
    
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int randomIndex = rand() % (int)(sizeof(charset) - 1);
        password[i] = charset[randomIndex];
    }

    password[PASSWORD_LENGTH] = '\0';
    printf("Your unique secure password is: %s\n", password);

    return 0;
}