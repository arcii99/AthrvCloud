//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, i, ch;
    time_t t;
    char password[30];
    char password_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*_";
    int num_characters = sizeof(password_characters) - 1;

    srand((unsigned) time(&t));

    printf("Please enter the desired length of the password (between 8 and 30 characters): ");
    scanf("%d", &length);

    if (length < 8 || length > 30) {
        printf("Password length should be between 8 and 30 characters. Exiting now.\n");
        return 0;
    }

    printf("Generating password...\n");

    for (i = 0; i < length; i++) {
        ch = rand() % num_characters;
        password[i] = password_characters[ch];
    }

    password[length] = '\0';

    printf("Your new password is: %s\n", password);

    return 0;
}