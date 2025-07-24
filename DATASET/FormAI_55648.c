//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>

// define the length of the message
#define MESSAGE_LENGTH 10

// define the polynomial
#define POLYNOMIAL 0x1021

// function to calculate the checksum
unsigned short calc_checksum(unsigned char message[], unsigned int length)
{
    unsigned short crc = 0xFFFF; // initialize crc to all ones
    
    for (int i = 0; i < length; i++)
    {
        crc ^= (unsigned short)(message[i] << 8); // step 1
        
        for (int j = 0; j < 8; j++) // step 2
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ POLYNOMIAL;
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
    unsigned char message[MESSAGE_LENGTH] = "hello!"; // example message
    unsigned short checksum = calc_checksum(message, MESSAGE_LENGTH); // calculate the checksum
    
    printf("Message: %s\n", message);
    printf("Checksum: 0x%X\n", checksum);
    
    return 0;
}