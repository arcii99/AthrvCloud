//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
/* C Checksum Calculator */

#include <stdio.h>

/* Function to calculate the CRC16 checksum */
unsigned short crc16(unsigned char *data, int length)
{
    unsigned short generator = 0x1021; /* CRC16 generator polynomial */
    unsigned short crc = 0xFFFF; /* Initial value */
    int i, j;
    
    for (i = 0; i < length; i++)
    {
        crc ^= (*(data+i) << 8);
        
        for (j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ generator;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    
    return crc;
}

int main()
{
    unsigned char data[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    int length = sizeof(data)/sizeof(data[0]);
    unsigned short checksum = crc16(data, length);
    
    printf("Data: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", data[i]);
    }
    printf("\n");
    
    printf("Checksum (CRC16): %04X\n", checksum);
    
    return 0;
}