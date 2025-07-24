//FormAI DATASET v1.0 Category: Encryption ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypt(char* msg, int key)
{
    int len = strlen(msg);
    char* new_msg = (char*)malloc(len+1);
    strcpy(new_msg, msg);
    for(int i=0; i<len; i++)
    {
        int ascii_val = (int)new_msg[i];
        ascii_val = ((ascii_val + key - 32)%95) + 32;
        new_msg[i] = (char)ascii_val;
    }
    return new_msg;
}

int main()
{
    char msg[100];
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(msg, 100, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    char* enc_msg = encrypt(msg, key);

    printf("Encrypted message: %s", enc_msg);

    free(enc_msg);
    return 0;
}