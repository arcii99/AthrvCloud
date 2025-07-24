//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdint.h>

/* Function to calculate the checksum */
uint8_t calculate_checksum(uint8_t *data, uint16_t len)
{
    uint16_t i;
    uint8_t checksum = 0;
    
    /* Add up all the values in the buffer */
    for (i = 0; i < len; i++)
    {
        checksum += data[i];
    }
    
    /* Return the calculated checksum */
    return checksum;
}

int main()
{
    uint8_t data[] = {0xAA, 0x55, 0x01, 0x02, 0x03, 0x04}; /* Sample data to calculate checksum */
    uint16_t len = sizeof(data); /* Length of the data buffer */
    uint8_t checksum; /* Variable to store the calculated checksum */
    
    /* Calculate the checksum using the function */
    checksum = calculate_checksum(data, len);
    
    /* Print the calculated checksum */
    printf("Checksum: 0x%02X\n", checksum);
    
    return 0;
}