//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a packet
#define MAX_PACKET_LENGTH 1024

// Declare the function that checks for intrusion
int check_for_intrusion(char* packet);

int main()
{
    char packet[MAX_PACKET_LENGTH];
    int intrusion_detected = 0;

    // Loop until an intrusion is detected
    while(!intrusion_detected)
    {
        // Ask the user to enter a packet
        printf("Enter a packet: ");
        fgets(packet, MAX_PACKET_LENGTH, stdin);

        // Check for intrusion
        intrusion_detected = check_for_intrusion(packet);

        // Print the result
        if(intrusion_detected)
        {
            printf("Intrusion detected in packet: %s", packet);
        }
        else
        {
            printf("Packet is safe.\n");
        }
    }

    return 0;
}

// Define the function that checks for intrusion
int check_for_intrusion(char* packet)
{
    // Define the keywords that might indicate an intrusion
    char* keywords[] = {"rm -rf", "sudo", "passwd", "system", "shutdown"};

    // Loop through all the keywords
    for(int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        // Check if the keyword is in the packet
        if(strstr(packet, keywords[i]) != NULL)
        {
            // Intrusion detected
            return 1;
        }
    }

    // No intrusion detected
    return 0;
}