//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>

int main()
{
    int i, len, sum = 0, checksum;
    char msg[100];

    /* User input */
    printf("Enter message to calculate checksum: ");
    fgets(msg, sizeof(msg), stdin);

    /* Calculating the length of message */
    for (len = 0; msg[len] != '\0'; len++)
    {
        sum = sum + (int)msg[len]; /* Computing sum of message */
    }

    /* Calculating checksum */
    checksum = sum % 255;

    /* Displaying the checksum */
    printf("Checksum of message is: %d\n", checksum);

    return 0;
}