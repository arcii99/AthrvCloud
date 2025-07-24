//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_LENGTH 1024

typedef struct packet_t {
    int id;
    char data[MAX_PACKET_LENGTH];
} packet;

packet buffer[10];
int head = 0;
int tail = 0;

void add_packet(packet p) {
    if ((tail + 1) % 10 == head) {
        printf("Intrusion Detected! Buffer overflow!");
        exit(1);
    }
    buffer[tail] = p;
    tail = (tail + 1) % 10;
}

int main() {
    printf("Starting Intrusion Detection System...\n");

    while (1) {
        packet p;
        printf("Enter packet ID: ");
        scanf("%d", &p.id);
        printf("Enter packet data: ");
        scanf("%s", p.data);

        if (strcmp(p.data, "self-destruct") == 0) {
            printf("Intrusion Detected! Self-destruct packet entered!\n");
            exit(1);
        }

        add_packet(p);
        printf("Packet added to buffer.\n");
    }

    return 0;
}