//FormAI DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_PACKETS 1000

typedef struct {
    char protocol[10];
    char sourceIP[16];
    char destIP[16];
    char sourcePort[10];
    char destPort[10];
    bool allow;
} Rule;

typedef struct {
    char protocol[10];
    char sourceIP[16];
    char destIP[16];
    char sourcePort[10];
    char destPort[10];
} Packet;

int numRules = 0;
int numPackets = 0;

Rule rules[MAX_RULES];
Packet packets[MAX_PACKETS];

void addRule(char* protocol, char* sourceIP, char* destIP, char* sourcePort, char* destPort, bool allow) {
    if(numRules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }
    strcpy(rules[numRules].protocol, protocol);
    strcpy(rules[numRules].sourceIP, sourceIP);
    strcpy(rules[numRules].destIP, destIP);
    strcpy(rules[numRules].sourcePort, sourcePort);
    strcpy(rules[numRules].destPort, destPort);
    rules[numRules].allow = allow;
    numRules++;
}

void addPacket(char* protocol, char* sourceIP, char* destIP, char* sourcePort, char* destPort) {
    if(numPackets >= MAX_PACKETS) {
        printf("Error: Maximum number of packets exceeded.\n");
        return;
    }
    strcpy(packets[numPackets].protocol, protocol);
    strcpy(packets[numPackets].sourceIP, sourceIP);
    strcpy(packets[numPackets].destIP, destIP);
    strcpy(packets[numPackets].sourcePort, sourcePort);
    strcpy(packets[numPackets].destPort, destPort);
    numPackets++;
}

bool matchRule(Rule rule, Packet packet) {
    if(strcmp(rule.protocol, packet.protocol) != 0) return false;
    if(strcmp(rule.sourceIP, packet.sourceIP) != 0) return false;
    if(strcmp(rule.destIP, packet.destIP) != 0) return false;
    if(strcmp(rule.sourcePort, packet.sourcePort) != 0) return false;
    if(strcmp(rule.destPort, packet.destPort) != 0) return false;
    return true;
}

bool firewall(Packet packet) {
    for(int i = 0; i < numRules; i++) {
        if(matchRule(rules[i], packet)) {
            return rules[i].allow;
        }
    }
    return false;
}

int main() {
    addRule("TCP", "192.168.1.1", "192.168.1.2", "80", "*", true);
    addRule("UDP", "*", "*", "*", "*", false);
    addPacket("TCP", "192.168.1.1", "192.168.1.2", "80", "8080");
    addPacket("UDP", "192.168.1.3", "192.168.1.4", "53", "53");
    addPacket("TCP", "192.168.1.5", "192.168.1.6", "22", "22");
    for(int i = 0; i < numPackets; i++) {
        printf("Packet %d:\nProtocol: %s\nSource IP: %s\nDestination IP: %s\nSource Port: %s\nDestination Port: %s\n", i+1, packets[i].protocol, packets[i].sourceIP, packets[i].destIP, packets[i].sourcePort, packets[i].destPort);
        if(firewall(packets[i])) {
            printf("Allowed.\n\n");
        } else {
            printf("Blocked.\n\n");
        }
    }
    return 0;
}