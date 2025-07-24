//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Supporting function to calculate the checksum value */
unsigned short calculate_checksum(unsigned char *data, int length)
{
    int i;
    unsigned short checksum = 0;

    for(i = 0; i < length; i++)
    {
        checksum += data[i];
    }

    return checksum;
}

/* Main program to calculate the checksum */
int main()
{
    unsigned char input_data[50];
    int input_length, i;
    unsigned short checksum_value;

    printf("Enter the data to be used for calculating checksum: ");
    fgets(input_data, 50, stdin);

    input_length = strlen(input_data)-1; /* fgets reads newline character so subtracting 1 */
    checksum_value = calculate_checksum(input_data, input_length);

    printf("\nChecksum calculated successfully. Checksum value = %04X\n", checksum_value);
    return 0;
}