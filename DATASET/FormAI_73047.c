//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>
#include <stdint.h>

/* Calculate the C Checksum for a given message */
uint8_t calculate_checksum(const uint8_t *message, size_t length)
{
    uint8_t checksum = 0;
    for(size_t i = 0; i < length; i++)
    {
        checksum += message[i];
    }
    return 0xFF - checksum;
}

/* Display the contents of an array in hexadecimal format */
void display_hex(const uint8_t *array, size_t length)
{
    for(size_t i = 0; i < length; i++)
    {
        printf("%02X ", array[i]);
    }
    printf("\n");
}

int main()
{
    printf("Welcome to the C Checksum Calculator!\n");

    /* Initialize sample message */
    uint8_t message[11] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x10, 0x20, 0x30};
    printf("Message: ");
    display_hex(message, 11);

    /* Calculate and display the checksum */
    uint8_t checksum = calculate_checksum(message, 11);
    printf("Checksum: %02X\n", checksum);

    /* Modify the message and recalculate the checksum */
    message[5] = 0xFF;
    printf("Modified message: ");
    display_hex(message, 11);

    checksum = calculate_checksum(message, 11);
    printf("Checksum after modification: %02X\n", checksum);

    /* Prompt for user input to enter a custom message */
    printf("Enter a message to calculate the checksum for:\n");
    uint8_t custom_message[25];
    size_t length = 0;
    while(1)
    {
        int c = getchar();
        if(c == '\n' || c == EOF)
        {
            break;
        }
        if(length >= 25)
        {
            printf("Error: message too long\n");
            return 1;
        }
        custom_message[length++] = (uint8_t)c;
    }

    /* Calculate and display the checksum for the custom message */
    printf("Custom message: ");
    display_hex(custom_message, length);

    checksum = calculate_checksum(custom_message, length);
    printf("Checksum for custom message: %02X\n", checksum);

    return 0;
}