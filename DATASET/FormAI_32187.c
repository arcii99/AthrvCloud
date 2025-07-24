//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

void encrypt(char input[], int key);

int main()
{
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char input[], int key)
{
    int i;
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = ((input[i] - 'a') + key) % 26 + 'a';
        }
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = ((input[i] - 'A') + key) % 26 + 'A';
        }
        else if(input[i] >= '0' && input[i] <= '9')
        {
            input[i] = ((input[i] - '0') + key) % 10 + '0';
        }
    }
}