//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

// Define a struct to represent a packet
typedef struct {
    char src_ip[16];
    char dest_ip[16];
    int src_port;
    int dest_port;
    char protocol[4];
    char data[MAX_PACKET_SIZE];
    int data_len;
} packet;

// Define a struct to represent a rule/policy
typedef struct {
    char src_ip[16];
    char dest_ip[16];
    int src_port;
    int dest_port;
    char protocol[4];
    int action; // 0 = block, 1 = allow
} rule;

// Define a function to check if a packet matches a rule
int packet_matches_rule(packet p, rule r) {
    if (strcmp(p.protocol, r.protocol) != 0) {
        return 0; // protocol mismatch
    }
    if (strcmp(p.src_ip, r.src_ip) != 0 && strcmp(r.src_ip, "*") != 0) {
        return 0; // source IP mismatch
    }
    if (strcmp(p.dest_ip, r.dest_ip) != 0 && strcmp(r.dest_ip, "*") != 0) {
        return 0; // destination IP mismatch
    }
    if (p.src_port != r.src_port && r.src_port != 0) {
        return 0; // source port mismatch
    }
    if (p.dest_port != r.dest_port && r.dest_port != 0) {
        return 0; // destination port mismatch
    }
    return 1; // all criteria matched
}

// Define a function to apply a set of rules to a packet
int apply_rules(packet p, rule* rules, int num_rules) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (packet_matches_rule(p, rules[i])) {
            return rules[i].action; // return block/allow action of first matching rule
        }
    }
    return 1; // allow by default if no rules match
}

// Define a main function to simulate the firewall
int main() {
    const int num_rules = 4;
    rule rules[num_rules];
    strcpy(rules[0].src_ip, "192.168.0.1"); // block traffic from a specific IP
    strcpy(rules[0].dest_ip, "*");
    rules[0].src_port = 0;
    rules[0].dest_port = 0;
    strcpy(rules[0].protocol, "*");
    rules[0].action = 0; // block
    strcpy(rules[1].src_ip, "*"); // allow traffic to a specific IP/port
    strcpy(rules[1].dest_ip, "192.168.0.2");
    rules[1].src_port = 0;
    rules[1].dest_port = 80;
    strcpy(rules[1].protocol, "TCP");
    rules[1].action = 1; // allow
    strcpy(rules[2].src_ip, "192.168.0.*"); // block traffic from a subnet
    strcpy(rules[2].dest_ip, "*");
    rules[2].src_port = 0;
    rules[2].dest_port = 0;
    strcpy(rules[2].protocol, "*");
    rules[2].action = 0; // block
    strcpy(rules[3].src_ip, "*"); // allow all other traffic
    strcpy(rules[3].dest_ip, "*");
    rules[3].src_port = 0;
    rules[3].dest_port = 0;
    strcpy(rules[3].protocol, "*");
    rules[3].action = 1; // allow

    while (1) {
        packet p;
        printf("Enter source IP address: ");
        scanf("%s", p.src_ip);
        printf("Enter destination IP address: ");
        scanf("%s", p.dest_ip);
        printf("Enter source port number: ");
        scanf("%d", &p.src_port);
        printf("Enter destination port number: ");
        scanf("%d", &p.dest_port);
        printf("Enter protocol (TCP/UDP/ICMP): ");
        scanf("%s", p.protocol);
        printf("Enter data (up to %d bytes): ", MAX_PACKET_SIZE);
        scanf("%s", p.data);
        p.data_len = strlen(p.data);

        if (apply_rules(p, rules, num_rules)) {
            printf("Packet allowed!\n");
        } else {
            printf("Packet blocked!\n");
        }
    }

    return 0;
}