//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_LENGTH 16
#define MAX_RULE_NAME_LENGTH 32
#define MAX_RULES 100
#define MAX_PACKET_SIZE 1024

typedef struct {
    char rule_name[MAX_RULE_NAME_LENGTH];
    char source_ip[MAX_IP_LENGTH];
    char destination_ip[MAX_IP_LENGTH];
    int source_port;
    int destination_port;
    char protocol[4];
} rule;

rule rules[MAX_RULES];

int num_rules = 0;

void add_rule(char* rule_name, char* source_ip, char* destination_ip, int source_port, int destination_port, char* protocol) {
    if (num_rules < MAX_RULES) {
        strcpy(rules[num_rules].rule_name, rule_name);
        strcpy(rules[num_rules].source_ip, source_ip);
        strcpy(rules[num_rules].destination_ip, destination_ip);
        rules[num_rules].source_port = source_port;
        rules[num_rules].destination_port = destination_port;
        strcpy(rules[num_rules].protocol, protocol);
        num_rules++;
    }
}

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s - source IP: %s, destination IP: %s, source port: %d, destination port: %d, protocol: %s\n", rules[i].rule_name, rules[i].source_ip, rules[i].destination_ip, rules[i].source_port, rules[i].destination_port, rules[i].protocol);
    }
}

int is_valid_ip(char* ip) {
    int num_segments = 0;
    int num_digits = 0;
    int segment_start = 0;
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            if (num_digits == 0 || atoi(ip + segment_start) > 255) {
                return 0;
            }
            num_segments++;
            num_digits = 0;
            segment_start = i + 1;
            continue;
        }
        if (!isdigit(ip[i])) {
            return 0;
        }
        num_digits++;
    }
    if (num_digits == 0 || atoi(ip + segment_start) > 255 || num_segments != 3) {
        return 0;
    }
    return 1;
}

int is_valid_port(int port) {
    return port >= 0 && port <= 65535;
}

int is_valid_protocol(char* protocol) {
    for (int i = 0; i < strlen(protocol); i++) {
        if (!isalpha(protocol[i])) {
            return 0;
        }
    }
    return strlen(protocol) <= 3;
}

int is_packet_allowed(char* source_ip, char* destination_ip, int source_port, int destination_port, char* protocol) {
    for (int i = 0; i < num_rules; i++) {
        rule r = rules[i];
        if ((strcmp(r.source_ip, "*") == 0 || strcmp(r.source_ip, source_ip) == 0) && (strcmp(r.destination_ip, "*") == 0 || strcmp(r.destination_ip, destination_ip) == 0) && (r.source_port == -1 || r.source_port == source_port) && (r.destination_port == -1 || r.destination_port == destination_port) && (strcmp(r.protocol, "*") == 0 || strcmp(r.protocol, protocol) == 0)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    add_rule("Allow SSH", "*", "*", -1, 22, "tcp");
    add_rule("Block Telnet", "*", "*", -1, 23, "tcp");
    add_rule("Allow DNS (UDP)", "*", "*", -1, 53, "udp");
    add_rule("Allow DNS (TCP)", "*", "*", -1, 53, "tcp");
    print_rules();

    char packet[MAX_PACKET_SIZE];
    while (fgets(packet, MAX_PACKET_SIZE, stdin) != NULL) {
        strtok(packet, "\n");
        char source_ip[MAX_IP_LENGTH];
        char destination_ip[MAX_IP_LENGTH];
        int source_port, destination_port;
        char protocol[4];
        sscanf(packet, "%s %s %d %d %s", source_ip, destination_ip, &source_port, &destination_port, protocol);
        if (is_valid_ip(source_ip) && is_valid_ip(destination_ip) && is_valid_port(source_port) && is_valid_port(destination_port) && is_valid_protocol(protocol)) {
            if (is_packet_allowed(source_ip, destination_ip, source_port, destination_port, protocol)) {
                printf("%s:%d -> %s:%d (%s) allowed\n", source_ip, source_port, destination_ip, destination_port, protocol);
            } else {
                printf("%s:%d -> %s:%d (%s) blocked by firewall\n", source_ip, source_port, destination_ip, destination_port, protocol);
            }
        } else {
            printf("Invalid packet format\n");
        }
    }

    return 0;
}