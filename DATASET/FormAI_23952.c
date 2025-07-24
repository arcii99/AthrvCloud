//FormAI DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

char *encrypt(char *message, int shift);

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    int shift;
    printf("Enter message to encrypt (max length %d):\n", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline character
    printf("Enter shift amount:\n");
    scanf("%d", &shift);
    printf("Encrypted message: %s\n", encrypt(message, shift));
    return 0;
}

char *encrypt(char *message, int shift)
{
    char *encrypted = malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        char c = message[i];
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        encrypted[i] = c;
    }
    encrypted[length] = '\0';
    return encrypted;
}