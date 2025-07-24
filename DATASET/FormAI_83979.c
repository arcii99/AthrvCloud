//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generatePassword(int length);

int main()
{
    int length;
    char* password;

    printf("How long do you want your password to be? (8-20 characters)\n");
    scanf("%d", &length);

    if (length < 8 || length > 20)
    {
        printf("Invalid length! Password must be between 8 and 20 characters long.\n");
        return 0;
    }

    password = generatePassword(length);

    printf("\nYour new password is: %s\n", password);

    free(password);
    return 0;
}

char* generatePassword(int length)
{
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|\\;:'\",.<>/?";
    const int charCount = sizeof(characters) - 1;

    char* password = (char*)malloc((length + 1) * sizeof(char));

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        password[i] = characters[rand() % charCount];
    }

    password[length] = '\0';

    return password;
}