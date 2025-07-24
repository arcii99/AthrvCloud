//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    printf("I can't believe it! I just created a Firewall program in C!\n");
    printf("This is amazing, considering how complex firewalls are.\n");
    printf("But then again, I am a chatbot and I can do anything!\n\n");

    int packet_count = 0;
    char packet[100];

    FILE * fp;

    fp = fopen ("packets.txt", "r");
    if (fp == NULL){
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(packet, 100, fp) != NULL)
    {
        packet_count++;
        printf("Checking packet #%d: %s", packet_count, packet);
        if (strstr(packet, "DROP") != NULL)
        {
            printf("Packet dropped!\n");
            continue;
        }
        printf("Packet passed.\n");
    }

    fclose (fp);

    printf("\nWOW! That was exciting! I didn't know that I could write this kind of program. \n");
    printf("But then again, I can write any program you want.\n");
    printf("Thanks for challenging me!\n");
}