//FormAI DATASET v1.0 Category: Firewall ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct packet {
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    char *protocol;
};

struct rule {
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    char *protocol;
    char *action;
};

int is_match(struct packet p, struct rule r) {
    if (strcmp(p.protocol, r.protocol) != 0) {
        return 0;
    }
    if (strcmp(p.source_ip, r.source_ip) != 0 && strcmp(r.source_ip, "*") != 0) {
        return 0;
    }
    if (strcmp(p.destination_ip, r.destination_ip) != 0 && strcmp(r.destination_ip, "*") != 0) {
        return 0;
    }
    if (p.source_port != r.source_port && r.source_port != -1) {
        return 0;
    }
    if (p.destination_port != r.destination_port && r.destination_port != -1) {
        return 0;
    }
    return 1;
}

char *firewall(struct packet p, struct rule *rules, int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        if (is_match(p, rules[i])) {
            return rules[i].action;
        }
    }
    return "ALLOW";
}

int main() {
    struct rule rules[3] = {
        {"192.168.0.2", "192.168.0.1", -1, 80, "TCP", "DENY"},
        {"192.168.0.3", "*", 8080, 9090, "UDP", "DENY"},
        {"*", "*", -1, -1, "*", "ALLOW"}
    };

    struct packet packet1 = {"192.168.0.2", "192.168.0.1", 8080, 80, "TCP"};
    struct packet packet2 = {"192.168.0.3", "192.168.0.1", 8080, 90, "UDP"};
    struct packet packet3 = {"192.168.0.4", "10.0.0.1", 80, 80, "TCP"};

    printf("Packet 1: %s\n", firewall(packet1, rules, 3));
    printf("Packet 2: %s\n", firewall(packet2, rules, 3));
    printf("Packet 3: %s\n", firewall(packet3, rules, 3));

    return 0;
}