//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ip[16];
} IpAddress;

typedef struct {
    IpAddress source;
    IpAddress destination;
} Packet;

typedef struct {
    IpAddress address;
    int allowed;
} Rule;

int main(int argc, char const *argv[]) {
    // sample packet to be evaluated by the firewall
    Packet packet;
    strncpy(packet.source.ip, "192.168.10.10", sizeof(packet.source.ip));
    strncpy(packet.destination.ip, "192.168.5.5", sizeof(packet.destination.ip));

    // rules list
    Rule rules[3];
    strncpy(rules[0].address.ip, "192.168.5.5", sizeof(rules[0].address.ip)); // only allow traffic to this ip
    rules[0].allowed = 1;
    strncpy(rules[1].address.ip, "192.168.10.10", sizeof(rules[1].address.ip)); // blacklist this ip
    rules[1].allowed = 0;
    strncpy(rules[2].address.ip, "192.168.0.0", sizeof(rules[2].address.ip)); // whitelist this subnet
    rules[2].allowed = 1;

    // evaluate packet against rules
    int packetAllowed = 0;
    for (int i=0; i<3; i++) {
        if (strcmp(packet.source.ip, rules[i].address.ip) == 0
         || strcmp(packet.destination.ip, rules[i].address.ip) == 0) {
            // match found, update packetAllowed accordingly
            packetAllowed = rules[i].allowed;
            break;
        }
    }

    // handle packet based on whether it's allowed or not
    if (packetAllowed) {
        printf("Packet allowed!\n");
    } else {
        printf("Packet blocked by firewall.\n");
    }

    return 0;
}