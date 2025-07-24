//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 14

void generatePassword(char password[], int length);
void shufflePassword(char password[]);

int main()
{
    int length = LENGTH;
    char password[LENGTH + 1];

    generatePassword(password, length);

    printf("Generated Password: %s\n", password);

    return 0;
}

void generatePassword(char password[], int length)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}[]|;:/?><,.`~";
    int charsetLength = strlen(charset) - 1;

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        password[i] = charset[rand() % charsetLength];
    }

    password[length] = '\0';

    shufflePassword(password);
}

void shufflePassword(char password[])
{
    int length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        int j = rand() % length;

        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}