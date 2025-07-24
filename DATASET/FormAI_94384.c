//FormAI DATASET v1.0 Category: Firewall ; Style: irregular
/* This program will demonstrate a unique way of implementing a firewall in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char packet[100];
    int i;

    printf("Welcome to the firewall program!\n");

    while(1)
    {
        printf("\nEnter the packet to be filtered: ");
        fgets(packet, sizeof(packet), stdin);

        if(strlen(packet) == 1)
        {
            printf("Empty packet detected! Please try again.\n");
            continue;
        }

        for(i = 0; i < strlen(packet); i++)
        {
            if(i % 2 == 0)
            {
                packet[i] = packet[i] + 1;
            }
            else
            {
                packet[i] = packet[i] - 1;
            }
        }

        for(i = 0; i < strlen(packet); i++)
        {
            if(packet[i] == '@' || packet[i] == '#' || packet[i] == '$' || packet[i] == '%')
            {
                printf("\nPacket blocked! Contains invalid characters!\n");
                break;
            }
        }

        if(i == strlen(packet))
        {
            printf("\nPacket filtered successfully! Passes security check!\n");

            for(i = 0; i < strlen(packet); i++)
            {
                if(packet[i] == 'p')
                {
                    packet[i] = 'm';
                }
                else if(packet[i] == 'P')
                {
                    packet[i] = 'M';
                }
            }

            printf("\nPacket after filtering: %s\n", packet);
        }
    }

    printf("Exiting firewall program.");
    return 0;
}