//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 200
#define MAX_IP_LENGTH 15

// Struct for each firewall rule
typedef struct {
    char direction[5]; // Either "inbound" or "outbound"
    char protocol[4]; // Either "tcp" or "udp"
    char port[6]; // Port number or range (e.g. "80" or "1000-2000")
    char ip_address[MAX_IP_LENGTH + 1]; // IP address or range (e.g. "192.168.0.1" or "192.168.0.1-192.168.0.5")
} rule_t;

// Check if a port number is valid
bool is_valid_port(char *port) {
    int len = strlen(port);

    if (len < 1 || len > 5) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (port[i] < '0' || port[i] > '9') {
            return false;
        }
    }

    int port_num = atoi(port);
    if (port_num < 1 || port_num > 65535) {
        return false;
    }

    return true;
}

// Check if an IP address is valid
bool is_valid_ip(char *ip) {
    int len = strlen(ip);

    if (len < 7 || len > MAX_IP_LENGTH) {
        return false;
    }

    int dots = 0;
    for (int i = 0; i < len; i++) {
        if (ip[i] == '.') {
            dots++;
        } else if (ip[i] < '0' || ip[i] > '9') {
            return false;
        }
    }
    if (dots != 3) {
        return false;
    }

    char *token = strtok(ip, ".");
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0 || num > 255) {
            return false;
        }
        token = strtok(NULL, ".");
    }

    return true;
}

// Check if a firewall rule is valid
bool is_valid_rule(rule_t *rule) {
    if (strcmp(rule->direction, "inbound") != 0 && strcmp(rule->direction, "outbound") != 0) {
        return false;
    }
    if (strcmp(rule->protocol, "tcp") != 0 && strcmp(rule->protocol, "udp") != 0) {
        return false;
    }
    if (!is_valid_port(rule->port)) {
        return false;
    }
    if (strlen(rule->ip_address) == 0 || !is_valid_ip(rule->ip_address)) {
        return false;
    }

    return true;
}

// Read firewall rules from a CSV file and store in an array
void read_rules(rule_t *rules, char *filename, int *num_rules) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char line[MAX_RULE_LENGTH + 1];
    *num_rules = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = 0;

        // Parse the line into fields (direction, protocol, port, ip_address)
        char *token;
        rule_t rule;
        int field_num = 0;

        token = strtok(line, ",");
        while (token != NULL && field_num < 4) {
            switch (field_num) {
                case 0:
                    strcpy(rule.direction, token);
                    break;
                case 1:
                    strcpy(rule.protocol, token);
                    break;
                case 2:
                    strcpy(rule.port, token);
                    break;
                case 3:
                    strcpy(rule.ip_address, token);
                    break;
            }
            token = strtok(NULL, ",");
            field_num++;
        }

        // Check if the rule is valid and add it to the array
        if (is_valid_rule(&rule) && *num_rules < MAX_RULES) {
            rules[*num_rules] = rule;
            (*num_rules)++;
        }
    }

    fclose(fp);
}

// Check if a given IP address is within a range of IP addresses
bool is_ip_in_range(char *ip, char *range_start, char *range_end) {
    char *token1 = strtok(ip, ".");
    char *token2 = strtok(range_start, ".");
    char *token3 = strtok(range_end, ".");

    while (token1 != NULL && token2 != NULL && token3 != NULL) {
        int num1 = atoi(token1);
        int num2 = atoi(token2);
        int num3 = atoi(token3);

        if (num1 < num2 || num1 > num3) {
            return false;
        }

        token1 = strtok(NULL, ".");
        token2 = strtok(NULL, ".");
        token3 = strtok(NULL, ".");
    }

    return true;
}

// Check if a packet matches a firewall rule
bool packet_matches_rule(char *direction, char *protocol, int port, char *ip_address, rule_t *rule) {
    if (strcmp(direction, rule->direction) != 0) {
        return false;
    }
    if (strcmp(protocol, rule->protocol) != 0) {
        return false;
    }
    if (port < 0 || port > 65535) {
        return false;
    }
    char port_str[6];
    sprintf(port_str, "%d", port);
    if (strstr(rule->port, "-") == NULL) {
        if (strcmp(rule->port, port_str) != 0) {
            return false;
        }
    } else {
        char port_start[6];
        char port_end[6];
        sscanf(rule->port, "%[^-]-%s", port_start, port_end);
        int port_start_num = atoi(port_start);
        int port_end_num = atoi(port_end);
        if (port < port_start_num || port > port_end_num) {
            return false;
        }
    }
    if (strstr(rule->ip_address, "-") == NULL) {
        if (strcmp(rule->ip_address, ip_address) != 0) {
            return false;
        }
    } else {
        char ip_start[MAX_IP_LENGTH + 1];
        char ip_end[MAX_IP_LENGTH + 1];
        sscanf(rule->ip_address, "%[^-]-%s", ip_start, ip_end);
        if (!is_ip_in_range(ip_address, ip_start, ip_end)) {
            return false;
        }
    }

    return true;
}

// Check if a packet should be allowed or denied based on firewall rules
bool check_packet(char *direction, char *protocol, int port, char *ip_address, rule_t *rules, int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        if (packet_matches_rule(direction, protocol, port, ip_address, &rules[i])) {
            return true; // Packet matches a rule, so allow it
        }
    }

    return false; // No rules match the packet, so deny it
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    rule_t rules[MAX_RULES];
    int num_rules;

    read_rules(rules, filename, &num_rules);

    printf("Enter packet details (direction, protocol, port, IP address):\n");
    char direction[8];
    char protocol[5];
    char port_str[6];
    char ip_address[MAX_IP_LENGTH + 1];
    scanf("%s %s %s %s", direction, protocol, port_str, ip_address);
    int port = atoi(port_str);

    if (check_packet(direction, protocol, port, ip_address, rules, num_rules)) {
        printf("Packet allowed.\n");
    } else {
        printf("Packet denied.\n");
    }

    return 0;
}