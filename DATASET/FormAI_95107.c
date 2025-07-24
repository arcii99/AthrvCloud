//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 1000
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 6

typedef struct firewall_rule {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char source_port[MAX_PORT_LEN];
    char dest_port[MAX_PORT_LEN];
    char protocol[4];
    int action; // 1 for allow, 0 for block
} firewall_rule;

firewall_rule rules[MAX_RULES];
int num_rules = 0;

int is_ip_addr(char *ip) {
    int num_dots = 0;
    int num_digits = 0;
    int i = 0;

    while(ip[i] != '\0') {
        if(ip[i] == '.') {
            num_dots++;
            if(num_digits == 0) {
                return 0;
            }
            num_digits = 0;
        } else if(isdigit(ip[i])) {
            num_digits++;
            if(num_digits > 3) {
                return 0;
            }
        } else {
            return 0;
        }

        i++;
    }

    if(num_dots != 3 || num_digits == 0) {
        return 0;
    }

    return 1;
}

int is_port(char *port) {
    int len = strlen(port);

    if(len > 5) {
        return 0;
    }

    for(int i = 0; i < len; i++) {
        if(!isdigit(port[i])) {
            return 0;
        }
    }

    return 1;
}

void add_rule(char *source_ip, char *dest_ip, char *source_port, char *dest_port, char *protocol, int action) {
    if(!is_ip_addr(source_ip) || !is_ip_addr(dest_ip) || !is_port(source_port) || !is_port(dest_port)) {
        printf("Invalid rule\n");
        return;
    }

    strcpy(rules[num_rules].source_ip, source_ip);
    strcpy(rules[num_rules].dest_ip, dest_ip);
    strcpy(rules[num_rules].source_port, source_port);
    strcpy(rules[num_rules].dest_port, dest_port);
    strcpy(rules[num_rules].protocol, protocol);
    rules[num_rules].action = action;

    num_rules++;

    printf("Rule added successfully\n");
}

int packet_is_allowed(char *source_ip, char *dest_ip, char *source_port, char *dest_port, char *protocol) {
    for(int i = 0; i < num_rules; i++) {
        if(strcmp(rules[i].source_ip, source_ip) == 0 || 
            strcmp(rules[i].source_ip, "*") == 0) {
            if(strcmp(rules[i].dest_ip, dest_ip) == 0 ||
                strcmp(rules[i].dest_ip, "*") == 0) {
                if(strcmp(rules[i].source_port, source_port) == 0 ||
                    strcmp(rules[i].source_port, "*") == 0) {
                    if(strcmp(rules[i].dest_port, dest_port) == 0 ||
                        strcmp(rules[i].dest_port, "*") == 0) {
                        if(strcmp(rules[i].protocol, protocol) == 0 ||
                            strcmp(rules[i].protocol, "*") == 0) {
                            return rules[i].action;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    add_rule("192.168.0.1", "*", "*", "*", "*", 1);
    add_rule("192.168.0.*", "*", "*", "*", "*", 0);
    add_rule("*", "192.168.0.2", "*", "*", "*", 1);
    add_rule("*", "*", "*", "80", "*", 1);

    int result = packet_is_allowed("192.168.0.1", "192.168.0.3", "8080", "80", "tcp");

    if(result) {
        printf("Packet allowed\n");
    } else {
        printf("Packet blocked\n");
    }

    return 0;
}