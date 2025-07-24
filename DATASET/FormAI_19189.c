//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>

// calculates the CRC checksum of a given input string and returns the checksum value
unsigned int calculate_checksum(char* input_string, unsigned int str_len)
{
    unsigned int checksum = 0xFFFF; // initial value of the checksum
    
    for(int i = 0; i < str_len; i++)
    {
        checksum ^= input_string[i]; // XOR the current character with the checksum value
        
        for(int j = 0; j < 8; j++)
        {
            if(checksum & 0x0001) // if the least significant bit of checksum is 1
            {
                checksum = (checksum >> 1) ^ 0xA001; // perform the CRC-16 algorithm
            }
            else
            {
                checksum = checksum >> 1; // shift the checksum right by 1 bit
            }
        }
    }
    
    return checksum;
}

int main()
{
    char input_string[100]; // a character array to store the input string
    unsigned int str_len; // length of the input string
    unsigned int checksum; // checksum value of the input string
    
    printf("Enter the input string: ");
    scanf("%s", input_string); // read the input string from the user
    str_len = strlen(input_string); // calculate the length of the input string
    
    checksum = calculate_checksum(input_string, str_len); // calculate the checksum of the input string
    
    printf("Checksum value: %04X\n", checksum); // print the checksum value in hexadecimal format
    
    return 0;
}