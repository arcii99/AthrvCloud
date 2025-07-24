//FormAI DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

// struct to represent a node in a decentralized system
typedef struct {
    char ip_address[16];
    int status;
} Node;

// struct to represent the entire decentralized system
typedef struct {
    int num_nodes;
    Node nodes[MAX_NODES];
} DecentralizedSystem;

// function to initialize a new node
Node init_node(char* ip) {
    Node node;
    strcpy(node.ip_address, ip);
    node.status = 1;
    return node;
}

// function to add a new node to the system
void add_node(DecentralizedSystem* system, char* ip) {
    if (system->num_nodes < MAX_NODES) {
        Node node = init_node(ip);
        system->nodes[system->num_nodes] = node;
        system->num_nodes++;
    } else {
        printf("ERROR: Maximum number of nodes already reached.\n");
    }
}

// function to remove a node from the system
void remove_node(DecentralizedSystem* system, char* ip) {
    int index = -1;
    for (int i = 0; i < system->num_nodes; i++) {
        if (strcmp(system->nodes[i].ip_address, ip) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < system->num_nodes - 1; i++) {
            system->nodes[i] = system->nodes[i+1];
        }
        system->num_nodes--;
    } else {
        printf("ERROR: Node not found.\n");
    }
}

// function to update the status of a node in the system
void update_node_status(DecentralizedSystem* system, char* ip, int status) {
    for (int i = 0; i < system->num_nodes; i++) {
        if (strcmp(system->nodes[i].ip_address, ip) == 0) {
            system->nodes[i].status = status;
            return;
        }
    }
    printf("ERROR: Node not found.\n");
}

// function to print the status of all nodes in the system
void print_system_status(DecentralizedSystem* system) {
    for (int i = 0; i < system->num_nodes; i++) {
        printf("Node %d: IP Address = %s, Status = %d\n", i+1, system->nodes[i].ip_address, system->nodes[i].status);
    }
}

int main() {
    DecentralizedSystem system;
    system.num_nodes = 0;

    add_node(&system, "192.168.1.101");
    add_node(&system, "192.168.1.102");
    add_node(&system, "192.168.1.103");
    add_node(&system, "192.168.1.104");

    update_node_status(&system, "192.168.1.102", 0);

    remove_node(&system, "192.168.1.103");

    print_system_status(&system);

    return 0;
}