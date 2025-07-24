//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50
#define MAX_IP_LEN 16
#define MAX_PORTS_LEN 16

struct firewall_rule {
    char source_ip[MAX_IP_LEN];
    char destination_ip[MAX_IP_LEN];
    char ports[MAX_PORTS_LEN];
};

struct firewall {
    struct firewall_rule rules[MAX_RULES];
    int num_rules;
};

void add_rule(struct firewall* fw, char* src_ip, char* dest_ip, char* ports) {
    if (fw->num_rules == MAX_RULES) {
        printf("Error: Maximum number of rules reached\n");
        return;
    }

    strncpy(fw->rules[fw->num_rules].source_ip, src_ip, MAX_IP_LEN-1);
    strncpy(fw->rules[fw->num_rules].destination_ip, dest_ip, MAX_IP_LEN-1);
    strncpy(fw->rules[fw->num_rules].ports, ports, MAX_PORTS_LEN-1);
    fw->num_rules++;
    printf("Rule added successfully\n");
}

int is_packet_allowed(struct firewall* fw, char* src_ip, char* dest_ip, char* port) {
    for (int i=0; i<fw->num_rules; i++) {
        // check if source and destination IP addresses match
        if (strcmp(fw->rules[i].source_ip, src_ip) == 0 &&
            strcmp(fw->rules[i].destination_ip, dest_ip) == 0) {
            // check if port is allowed
            char* token = strtok(fw->rules[i].ports, ",");
            while (token != NULL) {
                if (strcmp(token, port) == 0) {
                    // packet is allowed
                    return 1;
                }
                token = strtok(NULL, ",");
            }
        }
    }

    // packet is not allowed
    return 0;
}

int main() {
    // initialize firewall
    struct firewall fw;
    fw.num_rules = 0;

    // add some rules
    add_rule(&fw, "192.168.1.2", "192.168.1.5", "80,443");
    add_rule(&fw, "192.168.1.5", "192.168.1.2", "22");
    add_rule(&fw, "192.168.1.5", "192.168.1.2", "80");

    // simulate some packet traffic
    printf("Packet from 192.168.1.2 to 192.168.1.5 on port 80: ");
    if (is_packet_allowed(&fw, "192.168.1.2", "192.168.1.5", "80")) {
        printf("allowed\n");
    } else {
        printf("blocked\n");
    }

    printf("Packet from 192.168.1.2 to 192.168.1.5 on port 22: ");
    if (is_packet_allowed(&fw, "192.168.1.2", "192.168.1.5", "22")) {
        printf("allowed\n");
    } else {
        printf("blocked\n");
    }

    printf("Packet from 192.168.1.5 to 192.168.1.2 on port 8080: ");
    if (is_packet_allowed(&fw, "192.168.1.5", "192.168.1.2", "8080")) {
        printf("allowed\n");
    } else {
        printf("blocked\n");
    }

    return 0;
}