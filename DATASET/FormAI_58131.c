//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int srcIP;
    int destIP;
    int srcPort;
    int destPort;
    char protocol;
} Packet;

typedef struct {
    int startIP;
    int endIP;
} IPRange;

typedef struct {
    IPRange* ranges;
    int numRanges;
} BlockedList;

int isBlocked(IPRange* ranges, int numRanges, int ip) {
    for (int i = 0; i < numRanges; i++) {
        if (ip >= ranges[i].startIP && ip <= ranges[i].endIP) {
            return 1;
        }
    }
    return 0;
}

Packet* readPacket() {
    Packet* packet = (Packet*)malloc(sizeof(Packet));
    printf("Enter source IP: ");
    scanf("%d", &(packet->srcIP));
    printf("Enter destination IP: ");
    scanf("%d", &(packet->destIP));
    printf("Enter source port: ");
    scanf("%d", &(packet->srcPort));
    printf("Enter destination port: ");
    scanf("%d", &(packet->destPort));
    printf("Enter protocol (TCP/UDP): ");
    scanf(" %c", &(packet->protocol));
    return packet;
}

void blockIP(BlockedList* blockedList) {
    printf("Enter the number of ranges to block: ");
    scanf("%d", &(blockedList->numRanges));

    blockedList->ranges = (IPRange*)malloc(blockedList->numRanges * sizeof(IPRange));

    for (int i = 0; i < blockedList->numRanges; i++) {
        printf("Enter start IP of range #%d : ", i+1);
        scanf("%d", &(blockedList->ranges[i].startIP));
        printf("Enter end IP of range #%d : ", i+1);
        scanf("%d", &(blockedList->ranges[i].endIP));
    }

    printf("IP ranges have been blocked successfully.\n");
}

int main() {
    BlockedList blockedList;
    blockedList.numRanges = 0;

    char choice;
    do {
        printf("What would you like to do? \n");
        printf("a) Block IP ranges\n");
        printf("b) Check if a packet is allowed through the firewall\n");
        printf("c) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                blockIP(&blockedList);
                break;
            case 'b':
                Packet* packet = readPacket();
                if (isBlocked(blockedList.ranges, blockedList.numRanges, packet->srcIP)
                    || isBlocked(blockedList.ranges, blockedList.numRanges, packet->destIP)) {
                    printf("Packet has been blocked due to blocked IP range.\n");
                } else {
                    printf("Packet is allowed through the firewall.\n");
                }
                free(packet);
                break;
            case 'c':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 'c');
    free(blockedList.ranges);
    return 0;
}