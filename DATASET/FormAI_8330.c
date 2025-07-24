//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HOSTS 100

struct Host {
    char name[20];
    char ip[20];
    int connections[MAX_HOSTS];
    int num_connections;
};

struct Network {
    struct Host hosts[MAX_HOSTS];
    int num_hosts;
};

void add_host(struct Network* net, char* name, char* ip) {
    strcpy(net->hosts[net->num_hosts].name, name);
    strcpy(net->hosts[net->num_hosts].ip, ip);
    net->hosts[net->num_hosts].num_connections = 0;
    net->num_hosts++;
}

void add_connection(struct Network* net, char* host1, char* host2) {
    int index1 = -1;
    int index2 = -1;

    // Find the indices of the hosts
    for (int i = 0; i < net->num_hosts; i++) {
        if (strcmp(net->hosts[i].name, host1) == 0) {
            index1 = i;
        }
        else if (strcmp(net->hosts[i].name, host2) == 0) {
            index2 = i;
        }
    }

    // If either host isn't in the network, return
    if (index1 == -1 || index2 == -1) {
        return;
    }

    // If the hosts are already connected, return
    for (int i = 0; i < net->hosts[index1].num_connections; i++) {
        if (net->hosts[index1].connections[i] == index2) {
            return;
        }
    }

    // Add the connections
    net->hosts[index1].connections[net->hosts[index1].num_connections] = index2;
    net->hosts[index1].num_connections++;
    net->hosts[index2].connections[net->hosts[index2].num_connections] = index1;
    net->hosts[index2].num_connections++;
}

bool is_connected(struct Network* net, char* host1, char* host2) {
    int index1 = -1;
    int index2 = -1;

    // Find the indices of the hosts
    for (int i = 0; i < net->num_hosts; i++) {
        if (strcmp(net->hosts[i].name, host1) == 0) {
            index1 = i;
        }
        else if (strcmp(net->hosts[i].name, host2) == 0) {
            index2 = i;
        }
    }

    // If either host isn't in the network, return
    if (index1 == -1 || index2 == -1) {
        return false;
    }

    // Check if the hosts are connected
    for (int i = 0; i < net->hosts[index1].num_connections; i++) {
        if (net->hosts[index1].connections[i] == index2) {
            return true;
        }
    }

    return false;
}

void print_network(struct Network* net) {
    printf("Network Topology:\n");
    for (int i = 0; i < net->num_hosts; i++) {
        struct Host host = net->hosts[i];
        printf("%s (%s): ", host.name, host.ip);
        for (int j = 0; j < host.num_connections; j++) {
            struct Host connected_host = net->hosts[host.connections[j]];
            printf("%s (%s)", connected_host.name, connected_host.ip);
            if (j != host.num_connections - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Network net;
    net.num_hosts = 0;

    // Add hosts
    add_host(&net, "Router", "192.168.1.1");
    add_host(&net, "Desktop", "192.168.1.2");
    add_host(&net, "Laptop", "192.168.1.3");

    // Add connections
    add_connection(&net, "Router", "Desktop");
    add_connection(&net, "Router", "Laptop");

    // Test connectivity
    printf("Is Desktop connected to Router? %s\n", is_connected(&net, "Desktop", "Router") ? "YES" : "NO");
    printf("Is Desktop connected to Laptop? %s\n", is_connected(&net, "Desktop", "Laptop") ? "YES" : "NO");

    // Print network topology
    print_network(&net);

    return 0;
}