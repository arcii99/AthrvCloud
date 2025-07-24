//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ephemeral Firewall Program
int main() {
    // Set up firewall rules
    char* allowed_ips[] = {"192.168.0.1", "192.168.0.5", "10.0.0.1", "10.0.0.5"};
    int allowed_ports[] = {80, 443, 22};
    int allowed_ip_count = 4;
    int allowed_port_count = 3;

    char* input_ip = calloc(16, sizeof(char));
    printf("Enter IP address: ");
    scanf("%s", input_ip);

    // Check if input IP is allowed
    int ip_allowed = 0;
    for (int i = 0; i < allowed_ip_count; i++) {
        if (strcmp(input_ip, allowed_ips[i]) == 0) {
            ip_allowed = 1;
            break;
        }
    }

    // Check if input port is allowed
    int input_port;
    printf("Enter port number: ");
    scanf("%d", &input_port);

    int port_allowed = 0;
    for (int i = 0; i < allowed_port_count; i++) {
        if (input_port == allowed_ports[i]) {
            port_allowed = 1;
            break;
        }
    }

    // Determine whether to allow or block the traffic
    if (ip_allowed && port_allowed) {
        printf("Traffic allowed.\n");
        return 0;
    } else {
        printf("Traffic blocked.\n");
        return 1;
    }
}