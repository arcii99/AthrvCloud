//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char command[BUFFER_SIZE];

    // Clear existing rules
    sprintf(command, "iptables --flush");
    system(command);

    // Allow incoming SSH connections
    sprintf(command, "iptables -A INPUT -p tcp --dport ssh -j ACCEPT");
    system(command);

    // Block all other incoming traffic
    sprintf(command, "iptables -P INPUT DROP");
    system(command);

    // Allow outgoing traffic
    sprintf(command, "iptables -P OUTPUT ACCEPT");
    system(command);

    // Print firewall rules
    printf("Current Firewall Rules:\n");
    sprintf(command, "iptables -L");
    system(command);

    return 0;
}