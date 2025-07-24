//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BUFFER_SIZE 50

char player_one_name[BUFFER_SIZE], player_two_name[BUFFER_SIZE];

// Function to encrypt message using XOR operation
void encrypt(char *message, char *key)
{
    int message_len = strlen(message), key_len = strlen(key), i;
    for (i = 0; i < message_len; i++)
    {
        message[i] = message[i] ^ key[i % key_len];
    }
}

int main()
{
    char message[BUFFER_SIZE], key[KEY_SIZE];
    printf("Enter name of Player One: ");
    fgets(player_one_name, BUFFER_SIZE, stdin);
    printf("Enter name of Player Two: ");
    fgets(player_two_name, BUFFER_SIZE, stdin);

    printf("%s and %s, you are now connected.\n", player_one_name, player_two_name);
    printf("%s, please enter your message: ", player_one_name);
    fgets(message, BUFFER_SIZE, stdin);
    printf("Enter encryption key: ");
    fgets(key, KEY_SIZE, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("%s, please enter your message: ", player_two_name);
    fgets(message, BUFFER_SIZE, stdin);
    printf("Enter encryption key: ");
    fgets(key, KEY_SIZE, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Game over!\n");
    return 0;
}