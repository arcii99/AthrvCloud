//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define PACKET_SIZE 1024

struct rule {
    char protocol[10];
    char source_address[20];
    char destination_address[20];
    int source_port;
    int destination_port;
};

struct packet {
    char protocol[10];
    char source_address[20];
    char destination_address[20];
    int source_port;
    int destination_port;
    char data[PACKET_SIZE];
};

struct firewall {
    int num_rules;
    struct rule rules[MAX_RULES];
};

int allow_packet(struct packet p, struct firewall f) {
    int i;
    for (i = 0; i < f.num_rules; i++) {
        if (strcmp(f.rules[i].protocol, p.protocol) == 0 &&
            (strcmp(f.rules[i].source_address, p.source_address) == 0 ||
             strcmp(f.rules[i].source_address, "*") == 0) &&
            (strcmp(f.rules[i].destination_address, p.destination_address) == 0 ||
             strcmp(f.rules[i].destination_address, "*") == 0) &&
            (f.rules[i].source_port == p.source_port ||
             f.rules[i].source_port == -1) &&
            (f.rules[i].destination_port == p.destination_port ||
             f.rules[i].destination_port == -1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct firewall f;
    struct packet p;

    // Add some rules to the firewall
    f.num_rules = 5;

    strcpy(f.rules[0].protocol, "TCP");
    strcpy(f.rules[0].source_address, "192.168.1.1");
    strcpy(f.rules[0].destination_address, "*");
    f.rules[0].source_port = 80;
    f.rules[0].destination_port = -1;

    strcpy(f.rules[1].protocol, "UDP");
    strcpy(f.rules[1].source_address, "192.168.1.2");
    strcpy(f.rules[1].destination_address, "*");
    f.rules[1].source_port = -1;
    f.rules[1].destination_port = 53;

    strcpy(f.rules[2].protocol, "TCP");
    strcpy(f.rules[2].source_address, "*");
    strcpy(f.rules[2].destination_address, "10.0.0.1");
    f.rules[2].source_port = 22;
    f.rules[2].destination_port = -1;

    strcpy(f.rules[3].protocol, "TCP");
    strcpy(f.rules[3].source_address, "192.168.1.3");
    strcpy(f.rules[3].destination_address, "10.10.10.1");
    f.rules[3].source_port = 8080;
    f.rules[3].destination_port = 80;

    strcpy(f.rules[4].protocol, "UDP");
    strcpy(f.rules[4].source_address, "*");
    strcpy(f.rules[4].destination_address, "255.255.255.255");
    f.rules[4].source_port = -1;
    f.rules[4].destination_port = 53;

    // Check some packets against the firewall
    strcpy(p.protocol, "TCP");
    strcpy(p.source_address, "192.168.1.1");
    strcpy(p.destination_address, "192.168.2.1");
    p.source_port = 80;
    p.destination_port = 8080;
    printf("%s\n", allow_packet(p, f) ? "ALLOWED" : "DENIED");

    strcpy(p.protocol, "UDP");
    strcpy(p.source_address, "192.168.1.2");
    strcpy(p.destination_address, "10.10.10.1");
    p.source_port = 53;
    p.destination_port = 80;
    printf("%s\n", allow_packet(p, f) ? "ALLOWED" : "DENIED");

    strcpy(p.protocol, "TCP");
    strcpy(p.source_address, "192.168.1.3");
    strcpy(p.destination_address, "10.10.10.1");
    p.source_port = 8080;
    p.destination_port = 80;
    printf("%s\n", allow_packet(p, f) ? "ALLOWED" : "DENIED");

    strcpy(p.protocol, "UDP");
    strcpy(p.source_address, "192.168.1.4");
    strcpy(p.destination_address, "255.255.255.255");
    p.source_port = 53;
    p.destination_port = 53;
    printf("%s\n", allow_packet(p, f) ? "ALLOWED" : "DENIED");

    return 0;
}