//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Packet {
    int source_ip;
    int dest_ip;
    int protocol;
};

struct Log {
    int id;
    char timestamp[20];
    char message[100];
};

int main() {
    struct Packet packets[10];
    struct Log logs[10];

    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter source IP for packet %d: ", i+1);
        scanf("%d", &packets[i].source_ip);

        printf("Enter destination IP for packet %d: ", i+1);
        scanf("%d", &packets[i].dest_ip);

        printf("Enter protocol for packet %d (1: TCP, 2: UDP, 3: ICMP): ", i+1);
        scanf("%d", &packets[i].protocol);

        if (packets[i].source_ip == 123456 && packets[i].protocol == 1) {
            strcpy(logs[i].message, "Potential intrusion detected!");
            logs[i].id = i+1;
            time_t t = time(NULL);
            sprintf(logs[i].timestamp, "%s", asctime(localtime(&t)));
        }
    }

    printf("\nPacket information:\n");
    for (i = 0; i < 10; i++) {
        printf("Packet %d: source IP: %d, destination IP: %d, protocol: %d\n", i+1, packets[i].source_ip, packets[i].dest_ip, packets[i].protocol);
    }

    printf("\nLog information:\n");
    for (i = 0; i < 10; i++) {
        if (logs[i].id != 0) {
            printf("Log %d: %s at %s", logs[i].id, logs[i].message, logs[i].timestamp);
        }
    }

    return 0;
}