//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: decentralized
#include <stdio.h> 
#include <stdint.h> 
#include <stdlib.h> 

uint16_t checksum(char *buffer, int length);

int main() 
{ 
    char *data = "This is an example message.";
    int data_length = strlen(data);
    uint16_t result = checksum(data, data_length);
    printf("Checksum: %d\n", result);
    return 0; 
}

uint16_t checksum(char *buffer, int length) 
{ 
    uint32_t sum = 0;
    uint16_t *words = (uint16_t *)buffer;
    int num_words = length/2;

    for(int i = 0; i < num_words; i++) 
    { 
        sum += (uint32_t)words[i];
    }

    if(length % 2 == 1) 
    {
        sum += (uint32_t)buffer[length-1] << 8;
    }

    while(sum >> 16) 
    {
        // Fold sum to 16 bits
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    // Take one's complement
    return (uint16_t)(~sum);
}