//FormAI DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50
#define MAX_IP_LEN 16

int main()
{
    char firewall_rules[MAX_RULES][MAX_IP_LEN];
    char incoming_packet[MAX_IP_LEN];

    // Add sample firewall rules
    strcpy(firewall_rules[0], "192.168.1.1");
    strcpy(firewall_rules[1], "10.0.0.1");
    strcpy(firewall_rules[2], "172.16.0.1");

    printf("Enter incoming packet IP: ");
    fgets(incoming_packet, MAX_IP_LEN, stdin);

    // Remove trailing newline character from input
    incoming_packet[strcspn(incoming_packet, "\n")] = 0;

    // Check if incoming packet is allowed by firewall rules
    int i;
    int is_allowed = 0;
    for (i = 0; i < MAX_RULES; i++)
    {
        if (strcmp(firewall_rules[i], incoming_packet) == 0)
        {
            is_allowed = 1;
            break;
        }
    }

    // Print firewall decision
    if (is_allowed == 1)
    {
        printf("Incoming packet %s is allowed by firewall rules.\n", incoming_packet);
    }
    else
    {
        printf("Incoming packet %s is blocked by firewall rules.\n", incoming_packet);
    }

    return 0;
}