//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: satisfied
#include <stdio.h>
#include <string.h>

/*
 * Function to check if the input is a valid IP address
 */
int isValidIpAddress(char ipAddress[]) {
    int octet1, octet2, octet3, octet4;
    if (sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        return 0;
    }
    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        return 0;
    }
    return 1;
}

/*
 * Structure to store details of each packet
 */
struct Packet {
    char sourceIp[20];
    char destinationIp[20];
    char protocol[10];
};

int main() {
    struct Packet packets[100];
    char input[100];
    int packetCount = 0;
    int intrusionCount = 0;
    printf("Enter a packet in the following format: <sourceIp> <destinationIp> <protocol>\n");
    printf("Enter 'exit' to stop entering packets.\n");
    while (1) {
        printf("Packet %d: ", packetCount+1);
        scanf(" %[^\n]", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        char sourceIp[20], destinationIp[20], protocol[10];
        if (sscanf(input, "%s %s %s", sourceIp, destinationIp, protocol) != 3) {
            printf("Invalid input format. Please try again.\n");
            continue;
        }
        if (!isValidIpAddress(sourceIp) || !isValidIpAddress(destinationIp)) {
            printf("Invalid IP address. Please try again.\n");
            continue;
        }
        if (strcmp(protocol, "TCP") != 0 && strcmp(protocol, "UDP") != 0) {
            printf("Protocol must be either TCP or UDP. Please try again.\n");
            continue;
        }
        strcpy(packets[packetCount].sourceIp, sourceIp);
        strcpy(packets[packetCount].destinationIp, destinationIp);
        strcpy(packets[packetCount].protocol, protocol);
        packetCount++;
    }
    printf("\n\n------------------------------\n\n");
    printf("Intrusion Detection Report\n");
    printf("----------------------------\n");
    printf("Total packets received: %d\n", packetCount);
    for (int i = 0; i < packetCount; i++) {
        if (strcmp(packets[i].destinationIp, "10.0.0.5") == 0 && strcmp(packets[i].protocol, "TCP") == 0) {
            printf("Intrusion detected in packet %d. Source IP: %s, Destination IP: %s, Protocol: %s\n", 
                i+1, packets[i].sourceIp, packets[i].destinationIp, packets[i].protocol);
            intrusionCount++;
        }
    }
    printf("----------------------------\n");
    printf("Total number of intrusions detected: %d\n", intrusionCount);
    return 0;
}