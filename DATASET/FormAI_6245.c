//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    char ip[20], protocol[20];
    int port;

    // Read in user input
    printf("Enter IP Address: ");
    fgets(ip, 20, stdin);
    printf("Enter Protocol (TCP/UDP): ");
    fgets(protocol, 20, stdin);
    printf("Enter Port Number: ");
    scanf("%d", &port);

    // Remove the newline character from the input strings
    ip[strcspn(ip, "\n")] = '\0';
    protocol[strcspn(protocol, "\n")] = '\0';
    
    // Check if the IP address is valid
    if (strlen(ip) < 7 || strlen(ip) > 15) {
        printf("Invalid IP Address\n");
        return 0;
    }

    // Check if the protocol is valid
    if (strcmp(protocol, "TCP") != 0 && strcmp(protocol, "UDP") != 0) {
        printf("Invalid Protocol\n");
        return 0;
    }

    // Check if the port is valid
    if (port < 1 || port > 65535) {
        printf("Invalid Port Number\n");
        return 0;
    }

    // Print out the firewall rule
    printf("Firewall Rule:\n");
    printf("IP Address: %s\n", ip);
    printf("Protocol: %s\n", protocol);
    printf("Port Number: %d\n", port);
    printf("Action: Block\n");

    return 0;
}