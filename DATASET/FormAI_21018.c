//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include<stdio.h>
#include<string.h>

int main() {
    // Initialize the firewall rules as an array of struct
    struct firewall_rules {
        char protocol[10];
        char source[20];
        char destination[20];
        int port;
    } rules[10];

    // Add some initial rules to the firewall
    strcpy(rules[0].protocol, "TCP");
    strcpy(rules[0].source, "127.0.0.1");
    strcpy(rules[0].destination, "192.168.0.1");
    rules[0].port = 80;

    strcpy(rules[1].protocol, "UDP");
    strcpy(rules[1].source, "192.168.0.1");
    strcpy(rules[1].destination, "127.0.0.1");
    rules[1].port = 53;

    // Define the packet that we will check against the firewall rules
    char packet_protocol[10] = "TCP";
    char packet_source[20] = "127.0.0.1";
    char packet_destination[20] = "192.168.0.1";
    int packet_port = 80;

    // Loop through the firewall rules to see if any match
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(rules[i].protocol, packet_protocol) == 0 &&
            strcmp(rules[i].source, packet_source) == 0 &&
            strcmp(rules[i].destination, packet_destination) == 0 &&
            rules[i].port == packet_port) {
            printf("Packet allowed by the firewall!\n");
            return 0;
        }
    }

    // If we get here, the packet was not allowed by the firewall
    printf("Packet blocked by the firewall!\n");
    return 1;
}