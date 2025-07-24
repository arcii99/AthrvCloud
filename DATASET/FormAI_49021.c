//FormAI DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for holding firewall rules
struct FirewallRule {
    int sourceAddress[4];
    int destinationAddress[4];
    int protocolNumber;
    int sourcePort;
    int destinationPort;
    int action; // 0 = allow, 1 = block
};

int main() {
    // initialize an empty array of firewall rules
    struct FirewallRule firewallRules[10] = {0};

    // add a rule to the firewall
    firewallRules[0].sourceAddress[0] = 192;
    firewallRules[0].sourceAddress[1] = 168;
    firewallRules[0].sourceAddress[2] = 0;
    firewallRules[0].sourceAddress[3] = 0;
    firewallRules[0].destinationAddress[0] = 192;
    firewallRules[0].destinationAddress[1] = 168;
    firewallRules[0].destinationAddress[2] = 0;
    firewallRules[0].destinationAddress[3] = 1;
    firewallRules[0].protocolNumber = 6;
    firewallRules[0].sourcePort = 5000;
    firewallRules[0].destinationPort = 80;
    firewallRules[0].action = 0;

    // simulate incoming network traffic
    int incomingPacket[6];
    incomingPacket[0] = 192;
    incomingPacket[1] = 168;
    incomingPacket[2] = 0;
    incomingPacket[3] = 0;
    incomingPacket[4] = 192;
    incomingPacket[5] = 168;

    // loop over firewall rules and check if incoming packet should be allowed or blocked
    for (int i = 0; i < 10; i++) {
        if (firewallRules[i].sourceAddress[0] == incomingPacket[0] &&
            firewallRules[i].sourceAddress[1] == incomingPacket[1] &&
            firewallRules[i].sourceAddress[2] == incomingPacket[2] &&
            firewallRules[i].sourceAddress[3] == incomingPacket[3] &&
            firewallRules[i].destinationAddress[0] == incomingPacket[4] &&
            firewallRules[i].destinationAddress[1] == incomingPacket[5] &&
            firewallRules[i].protocolNumber == 6 &&
            firewallRules[i].sourcePort == 5000 &&
            firewallRules[i].destinationPort == 80) {

            if (firewallRules[i].action == 0) {
                printf("Packet allowed\n");
            } else {
                printf("Packet blocked\n");
            }
        }
    }

    return 0;
}