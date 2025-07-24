//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HOSTS 20 // Maximum number of hosts that can be connected in the network
#define MAX_LENGTH 10 // Maximum length of host names and IP addresses

// Structure to represent a host and its connections
struct host {
    char name[MAX_LENGTH];
    char ip_address[MAX_LENGTH];
    struct host* connected[MAX_HOSTS];
    int num_connections;
};

// Function to initialize a new host
void initialize_host(struct host* h, char* name, char* ip_address) {
    strcpy(h->name, name);
    strcpy(h->ip_address, ip_address);
    h->num_connections = 0;
}

// Function to add a connection between two hosts
void add_connection(struct host* h1, struct host* h2) {
    if (h1->num_connections < MAX_HOSTS && h2->num_connections < MAX_HOSTS) {
        h1->connected[h1->num_connections] = h2;
        h2->connected[h2->num_connections] = h1;
        h1->num_connections++;
        h2->num_connections++;
    }
}

// Function to print the network topology as an adjacency list
void print_topology(struct host* hosts[], int num_hosts) {
    printf("Network Topology:\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s (%s): ", hosts[i]->name, hosts[i]->ip_address);
        for (int j = 0; j < hosts[i]->num_connections; j++) {
            printf("%s (%s) ", hosts[i]->connected[j]->name, hosts[i]->connected[j]->ip_address);
        }
        printf("\n");
    }
}

int main() {
    // Create host objects
    struct host h1, h2, h3, h4, h5;

    // Initialize hosts with name and IP address
    initialize_host(&h1, "Host1", "192.168.1.1");
    initialize_host(&h2, "Host2", "192.168.1.2");
    initialize_host(&h3, "Host3", "192.168.1.3");
    initialize_host(&h4, "Host4", "192.168.1.4");
    initialize_host(&h5, "Host5", "192.168.1.5");

    // Add connections between hosts
    add_connection(&h1, &h2);
    add_connection(&h1, &h3);
    add_connection(&h2, &h3);
    add_connection(&h2, &h4);
    add_connection(&h3, &h4);
    add_connection(&h4, &h5);

    // Create an array of host pointers
    struct host* hosts[5] = {&h1, &h2, &h3, &h4, &h5};

    // Print the network topology
    print_topology(hosts, 5);

    return 0;
}