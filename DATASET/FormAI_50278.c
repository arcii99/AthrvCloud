//FormAI DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum packet length
#define MAX_PACKET_LENGTH 1024

// Define maximum number of rules
#define MAX_RULES 64

// Define rule structure
struct rule {
    char src_ip[16];
    char dst_ip[16];
    char protocol[16];
    int src_port;
    int dst_port;
};

// Define global variables
struct rule rules[MAX_RULES];
int num_rules = 0;

// Function to add a new rule
void add_rule(char *src_ip, char *dst_ip, char *protocol, int src_port, int dst_port) {
    if (num_rules >= MAX_RULES) {
        fprintf(stderr, "Maximum number of rules reached.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(rules[num_rules].src_ip, src_ip);
    strcpy(rules[num_rules].dst_ip, dst_ip);
    strcpy(rules[num_rules].protocol, protocol);
    rules[num_rules].src_port = src_port;
    rules[num_rules].dst_port = dst_port;

    num_rules++;
}

// Function to check a packet against the firewall rules
int check_packet(char *src_ip, char *dst_ip, char *protocol, int src_port, int dst_port) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].src_ip, src_ip) == 0 &&
            strcmp(rules[i].dst_ip, dst_ip) == 0 &&
            strcmp(rules[i].protocol, protocol) == 0 &&
            (rules[i].src_port == 0 || rules[i].src_port == src_port) &&
            (rules[i].dst_port == 0 || rules[i].dst_port == dst_port)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char packet[MAX_PACKET_LENGTH];
    char src_ip[16];
    char dst_ip[16];
    char protocol[16];
    int src_port;
    int dst_port;

    // Add some rules
    add_rule("10.0.0.1", "10.0.0.2", "TCP", 0, 8080);
    add_rule("10.0.0.2", "10.0.0.1", "TCP", 8080, 0);
    add_rule("10.0.0.3", "10.0.0.4", "UDP", 0, 0);

    // Loop to receive packets
    while (fgets(packet, MAX_PACKET_LENGTH, stdin) != NULL) {
        // Parse packet
        sscanf(packet, "%s %s %s %d %d", src_ip, dst_ip, protocol, &src_port, &dst_port);

        // Check packet against rules
        if (check_packet(src_ip, dst_ip, protocol, src_port, dst_port)) {
            printf("ALLOWED\n");
        } else {
            printf("BLOCKED\n");
        }
    }

    return 0;
}