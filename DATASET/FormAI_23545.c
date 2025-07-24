//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int calc_checksum(char* buffer, int length, unsigned int checksum)
{
    int i;
    unsigned int sum = checksum;
    
    for(i=0; i<length; i++)
    {
        sum += (unsigned char)buffer[i];
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    
    return sum;
}

int main()
{
    char input_str[256];    // to store the input string
    unsigned int checksum = 0;  // to store the initial checksum value
    unsigned int final_checksum;    // to store the final checksum value
    int i;
    
    printf("Enter the input string: ");
    fgets(input_str, sizeof(input_str), stdin);
    input_str[strcspn(input_str, "\n")] = 0;   // to remove the newline character
    
    // print the input string as hexadecimal values
    printf("Input string as hexadecimal values: ");
    for (i = 0; i < strlen(input_str); ++i)
        printf("%02X ", input_str[i] & 0xFF);
    printf("\n");
    
    // calculate the checksum
    final_checksum = calc_checksum(input_str, strlen(input_str), checksum);
    
    // print the checksum value as a hexadecimal value
    printf("Checksum value: %04X\n", final_checksum);
    
    return 0;
}