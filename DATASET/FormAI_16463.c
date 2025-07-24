//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <stdint.h>

/* Function to calculate the checksum value */
uint8_t calculate_checksum(uint8_t *data, int length)
{
    uint8_t checksum = 0;
    for(int i=0; i<length; i++){
        checksum -= data[i];
    }
    return checksum;
}

/* Driver program to test the function */
int main()
{
    // sample data array
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(data) / sizeof(data[0]);

    // calculate the checksum value
    uint8_t checksum = calculate_checksum(data, length);

    // print the result
    printf("Checksum value: 0x%02X\n", checksum);

    return 0;
}