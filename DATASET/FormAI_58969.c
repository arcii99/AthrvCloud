//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000

struct rule {
    char *source_ip;
    char *dest_ip;
    int source_port;
    int dest_port;
    char *protocol;
    char *action; // ACCEPT or DROP
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

// Function to add a new rule to the firewall
void add_rule(struct firewall *fw, char *src, char *dst, int sport, int dport, char *proto, char *act) {
    struct rule r;
    r.source_ip = malloc(strlen(src) + 1);
    r.dest_ip = malloc(strlen(dst) + 1);
    r.source_port = sport;
    r.dest_port = dport;
    r.protocol = malloc(strlen(proto) + 1);
    r.action = malloc(strlen(act) + 1);

    strcpy(r.source_ip, src);
    strcpy(r.dest_ip, dst);
    strcpy(r.protocol, proto);
    strcpy(r.action, act);

    fw->rules[fw->num_rules++] = r;
}

// Function to check if a packet matches a rule in the firewall
int matches_rule(struct rule r, char *src, char *dst, int sport, int dport, char *proto) {
    if (strcmp(r.source_ip, src) != 0 && strcmp(r.source_ip, "*") != 0) {
        return 0;
    }

    if (strcmp(r.dest_ip, dst) != 0 && strcmp(r.dest_ip, "*") != 0) {
        return 0;
    }

    if (r.source_port != sport && r.source_port != -1) {
        return 0;
    }

    if (r.dest_port != dport && r.dest_port != -1) {
        return 0;
    }

    if (strcmp(r.protocol, proto) != 0 && strcmp(r.protocol, "*") != 0) {
        return 0;
    }

    return 1;
}

// Function to allow or drop a packet based on the firewall rules
void handle_packet(struct firewall fw, char *src, char *dst, int sport, int dport, char *proto) {
    int i;
    for (i = 0; i < fw.num_rules; i++) {
        if (matches_rule(fw.rules[i], src, dst, sport, dport, proto)) {
            printf("%s packet from %s:%d to %s:%d using %s protocol matches rule %d: %s\n", fw.rules[i].action, src, sport, dst, dport, proto, i+1, fw.rules[i].action);
            return;
        }
    }

    printf("No rule matched for packet from %s:%d to %s:%d using %s protocol. Dropping packet.\n", src, sport, dst, dport, proto);
}

int main() {
    struct firewall fw;
    fw.num_rules = 0;

    // Example rules
    add_rule(&fw, "192.168.1.1", "*", -1, 80, "*", "ACCEPT");
    add_rule(&fw, "*", "*", 53, 53, "UDP", "ACCEPT");
    add_rule(&fw, "*", "*", -1, -1, "*", "DROP");

    // Example packets
    handle_packet(fw, "192.168.1.1", "8.8.8.8", 1234, 80, "TCP");
    handle_packet(fw, "192.168.2.1", "8.8.8.8", 1234, 80, "TCP");
    handle_packet(fw, "192.168.1.1", "8.8.8.8", 53, 53, "UDP");
    handle_packet(fw, "192.168.1.1", "8.8.8.8", 1234, 5678, "TCP");
    handle_packet(fw, "192.168.1.1", "8.8.8.8", 1234, 80, "HTTP");

    return 0;
}