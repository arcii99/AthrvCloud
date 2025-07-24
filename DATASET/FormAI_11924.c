//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
/*
 * C Checksum Calculator
 * Author: Chatbot
 * Date: September 25, 2021
 */

#include <stdio.h>

unsigned int calculate_checksum(unsigned char *data, int length);

int main(void)
{
    unsigned char data[] = {0x02, 0x05, 0x08, 0x13, 0x21, 0x34, 0x55, 0x89};
    int length = sizeof(data) / sizeof(unsigned char);

    unsigned int checksum = calculate_checksum(data, length);

    printf("The checksum of the data is: 0x%08X\n", checksum);

    return 0;
}

unsigned int calculate_checksum(unsigned char *data, int length)
{
    unsigned int sum1 = 0, sum2 = 0;

    // Perform the Fletcher-16 checksum algorithm
    for (int i = 0; i < length; i++)
    {
        sum1 = (sum1 + data[i]) % 255;
        sum2 = (sum2 + sum1) % 255;
    }

    // Combine sum1 and sum2 into a 16-bit checksum
    unsigned int checksum = (sum2 << 8) | sum1;

    return checksum;
}