//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PASSWORD_LENGTH 16

// Generate a secure password
void generatePassword(char *password)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-{}[]<>";

    srand(time(NULL));

    for(int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    password[PASSWORD_LENGTH] = '\0';
}

int main()
{
    char password[PASSWORD_LENGTH + 1];

    generatePassword(password);

    printf("Your secure password is: %s\n", password);

    return 0;
}