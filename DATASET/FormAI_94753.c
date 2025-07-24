//FormAI DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 100

struct firewall_rule {
    char ip_address[MAX_IP_LENGTH + 1];
    int port_number;
};

struct firewall {
    struct firewall_rule rules[MAX_RULES];
    int num_rules;
};

bool is_ip_address_valid(char* ip_address) {
    // check if IP address is valid
    // implementation not shown for brevity
    return true;
}

bool is_port_number_valid(int port_number) {
    // check if port number is valid
    // implementation not shown for brevity
    return true;
}

bool add_firewall_rule(struct firewall* f, char* ip_address, int port_number) {
    // check if IP address and port number are valid
    if (!is_ip_address_valid(ip_address) || !is_port_number_valid(port_number)) {
        return false;
    }
    // check if max number of rules has been reached
    if (f->num_rules >= MAX_RULES) {
        return false;
    }
    // add rule to firewall
    strcpy(f->rules[f->num_rules].ip_address, ip_address);
    f->rules[f->num_rules].port_number = port_number;
    f->num_rules++;
    return true;
}

bool is_packet_allowed(struct firewall* f, char* ip_address, int port_number) {
    // check if IP address and port number match any of the firewall rules
    for (int i = 0; i < f->num_rules; i++) {
        if (strcmp(f->rules[i].ip_address, ip_address) == 0 && f->rules[i].port_number == port_number) {
            return true;
        }
    }
    return false;
}

int main() {
    struct firewall f;
    f.num_rules = 0;
    
    // add firewall rules
    add_firewall_rule(&f, "192.168.1.1", 80);
    add_firewall_rule(&f, "192.168.1.2", 443);
    
    // simulate network traffic
    char* packet_ip_address = "192.168.1.1";
    int packet_port_number = 80;
    if (is_packet_allowed(&f, packet_ip_address, packet_port_number)) {
        printf("Packet with IP address %s and port number %d is allowed.\n", packet_ip_address, packet_port_number);
    } else {
        printf("Packet with IP address %s and port number %d is not allowed.\n", packet_ip_address, packet_port_number);
    }
    
    packet_ip_address = "192.168.1.3";
    packet_port_number = 8080;
    if (is_packet_allowed(&f, packet_ip_address, packet_port_number)) {
        printf("Packet with IP address %s and port number %d is allowed.\n", packet_ip_address, packet_port_number);
    } else {
        printf("Packet with IP address %s and port number %d is not allowed.\n", packet_ip_address, packet_port_number);
    }
    
    return 0;
}