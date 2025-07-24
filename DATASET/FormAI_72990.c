//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to calculate the checksum of a given string
unsigned int calculate_checksum(char str[])
{
    size_t len = strlen(str);
    unsigned int sum = 0;
    
    for (size_t i=0; i<len; i++)
    {
        sum += (unsigned int) str[i];
    }
    
    return sum;
}

int main()
{
    // Declare a romantic string
    char romantic_msg[] = "I love you more than the sum of all bytes in this string";
    
    // Calculate the checksum of the romantic message
    unsigned int checksum = calculate_checksum(romantic_msg);
    
    // Print the result
    printf("My love, the checksum of my message to you is: %u\n", checksum);
    
    // Bonus feature: encrypted message to decode
    printf("My dear, I have also encoded a secret message for you:\n");
    
    char encrypted_msg[] = {0x49, 0x20, 0x6c, 0x6f, 0x76, 0x65, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x6d, 0x6f, 0x72,
                            0x65, 0x20, 0x74, 0x68, 0x61, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x75, 0x6d, 
                            0x20, 0x6f, 0x66, 0x20, 0x61, 0x6c, 0x6c, 0x20, 0x62, 0x79, 0x74, 0x65, 0x73, 0x20, 
                            0x69, 0x6e, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67};
    
    // Decrypt the message
    printf("It says: ");
    for (size_t i=0; i<strlen(encrypted_msg); i++)
    {
        char c = encrypted_msg[i] ^ checksum;
        printf("%c", c);
    }
    
    printf("\n");
    
    return 0;
}