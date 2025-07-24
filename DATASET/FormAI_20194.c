//FormAI DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

int main()
{
    char message[1000];
    char key[100];
    char encryptedMessage[1000];
    int messageLength, keyLength, i, j;

    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter the key: ");
    fgets(key, 100, stdin);

    messageLength = strlen(message) - 1;
    keyLength = strlen(key) - 1;

    if(messageLength % BLOCK_SIZE != 0 || keyLength != BLOCK_SIZE)
    {
        printf("Error: Message length must be a multiple of %d and key length must be equal to %d", BLOCK_SIZE, BLOCK_SIZE);
        return 0;
    }

    int blocks = messageLength / BLOCK_SIZE;

    unsigned char state[BLOCK_SIZE][BLOCK_SIZE];

    // initialize the state array
    for(i = 0; i < BLOCK_SIZE; i++)
    {
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            state[i][j] = 0;
        }
    }

    // encryption algorithm
    for(i = 0; i < blocks; i++)
    {
        // copy next block of message into state array
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            state[j][0] = message[i*BLOCK_SIZE + j];
        }

        // add round key
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            state[j][0] ^= key[j];
        }

        // shift rows
        unsigned char tmp[BLOCK_SIZE];
        for(j = 1; j < BLOCK_SIZE; j++)
        {
            memcpy(tmp, state[j], BLOCK_SIZE);
            memcpy(state[j], &tmp[j], BLOCK_SIZE - j);
            memcpy(&state[j][BLOCK_SIZE-j], tmp, j);
        }

        // mix columns
        unsigned char a[4], b[4], c, h;
        for(c = 0; c < BLOCK_SIZE; c++)
        {
            for(h = 0; h < 4; h++)
            {
                a[h] = state[c][(h << 2)];
                b[h] = state[c][((h << 2) + 1)];
            }

            state[c][0] = (unsigned char)(
                    (unsigned char)(a[0] << 1) ^ (unsigned char)(
                            (unsigned char)(a[1] ^ (unsigned char)(a[1] << 1)) ^ a[2] ^ a[3]) ^ 0x63);
            state[c][1] = (unsigned char)(
                    (unsigned char)(a[1] << 1) ^ (unsigned char)(
                            (unsigned char)(a[2] ^ (unsigned char)(a[2] << 1)) ^ a[3] ^ a[0]) ^ 0x63);
            state[c][2] = (unsigned char)(
                    (unsigned char)(a[2] << 1) ^ (unsigned char)(
                            (unsigned char)(a[3] ^ (unsigned char)(a[3] << 1)) ^ a[0] ^ a[1]) ^ 0x63);
            state[c][3] = (unsigned char)(
                    (unsigned char)(a[3] << 1) ^ (unsigned char)(
                            (unsigned char)(a[0] ^ (unsigned char)(a[0] << 1)) ^ a[1] ^ a[2]) ^ 0x63);

            for(h = 0; h < 4; h++)
            {
                state[c][((h << 2) + 1)] = (unsigned char)((
                        (unsigned char)(b[(h + 3) % 4]) ^ state[c][((h << 2) + 1)]) ^ a[h]);
                state[c][((h << 2) + 2)] = (unsigned char)((
                        (unsigned char)(b[(h + 2) % 4]) ^ state[c][((h << 2) + 2)]) ^ a[h]);
                state[c][((h << 2) + 3)] = (unsigned char)((
                        (unsigned char)(b[(h + 1) % 4]) ^ state[c][((h << 2) + 3)]) ^ a[h]);
                state[c][(h << 2)] = (unsigned char)((
                        (unsigned char)(b[h]) ^ state[c][(h << 2)]) ^ a[h]);
            }
        }

        // copy encrypted block to output
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            encryptedMessage[i*BLOCK_SIZE + j] = state[j][0];
        }
    }

    // print encrypted message
    printf("Encrypted message:\n");
    for(i = 0; i < messageLength; i++)
    {
        printf("%02x", encryptedMessage[i]);
    }

    return 0;
}