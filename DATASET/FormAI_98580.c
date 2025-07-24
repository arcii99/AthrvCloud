//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 256

void printMenu()
{
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

void generateKey(char *key)
{
    srand(50); // fixed seed for testing purposes
    for(int i = 0; i < KEY_LENGTH; i++)
    {
        key[i] = rand() % 256;
    }
}

void encrypt(char *message, char *key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] = message[i] ^ key[i % KEY_LENGTH];
    }
}

void decrypt(char *message, char *key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] = message[i] ^ key[i % KEY_LENGTH];
    }
}

int main()
{
    char key[KEY_LENGTH];
    generateKey(key);

    int choice;
    char message[100];

    while(1)
    {
        printMenu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter message to encrypt: ");
                fflush(stdin);
                fgets(message, 100, stdin);

                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter message to decrypt: ");
                fflush(stdin);
                fgets(message, 100, stdin);

                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}