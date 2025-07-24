//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// The following function converts a given string to its hash value
// using the traditional Cyclic Redundancy Check (CRC) algorithm
unsigned int generateCRC(char* str)
{
    unsigned int crc = 0xFFFFFFFF;
    int i;

    for(i = 0; i < strlen(str); i++)
    {
        unsigned char ch = str[i];
        crc = crc ^ ch;

        for(int j=0; j < 8; j++)
        {
            if(crc & 1)
            {
                crc = (crc >> 1) ^ 0xEDB88320;
            }
            else
            {
                crc = crc >> 1;
            }
        }
    }

    return ~crc;
}

int main()
{
    char message[256];
    unsigned int hash;

    printf("Enter a message to generate its hash: ");
    fgets(message, 256, stdin);

    hash = generateCRC(message); // Generate hash

    printf("Hash value of the message is: %08X\n", hash); // Print hash value

    return 0;
}