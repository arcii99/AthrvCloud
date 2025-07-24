//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* encrypt(void* arg);
const char *input_str = "This is a secret message.";
char *encrypted_str;
const int Shift = 3;

int main()
{
    pthread_t tid1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid1, &attr, encrypt, NULL);
    pthread_join(tid1, NULL);
    printf("Original message: %s\n", input_str);
    printf("Encrypted message: %s\n", encrypted_str);
    return 0;
}

void* encrypt(void* arg)
{
    encrypted_str = (char*) malloc(strlen(input_str) + 1);
    for (int i = 0; i < strlen(input_str); i++)
    {
        if ((input_str[i] >= 'A' && input_str[i] <= 'Z') || (input_str[i] >= 'a' && input_str[i] <= 'z'))
        {
            if (input_str[i] >= 'a' && input_str[i] <= 'z')
            {
                encrypted_str[i] = ((input_str[i] - 'a' + Shift) % 26) + 'a';
            }
            else
            {
                encrypted_str[i] = ((input_str[i] - 'A' + Shift) % 26) + 'A';
            }
        }
        else
        {
            encrypted_str[i] = input_str[i];
        }
    }
    encrypted_str[strlen(input_str)] = '\0';
    pthread_exit(0);
}