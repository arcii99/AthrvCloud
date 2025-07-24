//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSTS 20 // max hosts in the network

typedef struct {
    char name[20];
    int num_connections;
    int connections[MAX_HOSTS];
} Host;

int main() {
    Host hosts[MAX_HOSTS];
    int num_hosts = 0;

    // Add some sample hosts and their connections
    strcpy(hosts[num_hosts].name, "Server");
    hosts[num_hosts].num_connections = 4;
    hosts[num_hosts].connections[0] = 1;
    hosts[num_hosts].connections[1] = 2;
    hosts[num_hosts].connections[2] = 3;
    hosts[num_hosts].connections[3] = 4;
    num_hosts++;

    strcpy(hosts[num_hosts].name, "Switch");
    hosts[num_hosts].num_connections = 5;
    hosts[num_hosts].connections[0] = 0;
    hosts[num_hosts].connections[1] = 2;
    hosts[num_hosts].connections[2] = 4;
    hosts[num_hosts].connections[3] = 5;
    hosts[num_hosts].connections[4] = 6;
    num_hosts++;

    strcpy(hosts[num_hosts].name, "PC1");
    hosts[num_hosts].num_connections = 3;
    hosts[num_hosts].connections[0] = 0;
    hosts[num_hosts].connections[1] = 1;
    hosts[num_hosts].connections[2] = 4;
    num_hosts++;

    strcpy(hosts[num_hosts].name, "PC2");
    hosts[num_hosts].num_connections = 2;
    hosts[num_hosts].connections[0] = 1;
    hosts[num_hosts].connections[1] = 4;
    num_hosts++;

    strcpy(hosts[num_hosts].name, "Printer");
    hosts[num_hosts].num_connections = 3;
    hosts[num_hosts].connections[0] = 1;
    hosts[num_hosts].connections[1] = 2;
    hosts[num_hosts].connections[2] = 6;
    num_hosts++;

    // Print the network topology
    printf("Network topology:\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s:", hosts[i].name);
        for (int j = 0; j < hosts[i].num_connections; j++) {
            printf(" %s", hosts[hosts[i].connections[j]].name);
        }
        printf("\n");
    }

    return 0;
}