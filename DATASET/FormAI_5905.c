//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[1000];
    unsigned int length, i;
    unsigned short chksum = 0;

    printf("Enter the message: ");
    scanf("%s", message);

    length = strlen(message);

    if (length % 2 == 1)
    {
        message[length] = 0;
        length++;
    }

    for (i = 0; i < length; i += 2)
    {
        unsigned short word = message[i];
        word = (word << 8) + message[i+1];
        chksum += word;
    }

    chksum = (chksum >> 16) + (chksum & 0xffff);
    chksum += (chksum >> 16);

    printf("\nThe message is: %s", message);
    printf("\nThe checksum is: %04x\n", ~chksum);

    return 0;
}