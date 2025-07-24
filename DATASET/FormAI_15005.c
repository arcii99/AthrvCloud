//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char payload[100];
    int protocol_id;
    int packet_length;
} Packet;

int is_intrusion(Packet p) {
    if (p.protocol_id != 1) {
        return 1;
    }
    if (p.packet_length > 100) {
        return 1;
    }
    char blacklist[] = "hack";
    if (strstr(p.payload, blacklist) != NULL) {
        return 1;
    }
    char whitelist[] = "allow";
    if (strstr(p.payload, whitelist) != NULL) {
        return 0;
    }
    return 1;
}

void log_intrusion(Packet p) {
    printf("Intrusion detected:\n");
    printf("Payload: %s\n", p.payload);
    printf("Protocol ID: %d\n", p.protocol_id);
    printf("Packet length: %d\n", p.packet_length);
}

int main() {
    Packet p1 = {"This is a normal packet.", 1, 50};
    if (is_intrusion(p1)) {
        log_intrusion(p1);
    }
    Packet p2 = {"This is a hack attempt!", 1, 200};
    if (is_intrusion(p2)) {
        log_intrusion(p2);
    }
    Packet p3 = {"I am allowed to send 'hack' in the payload.", 1, 60};
    if (is_intrusion(p3)) {
        log_intrusion(p3);
    } else {
        printf("No intrusion detected.\n");
    }
    return 0;
}