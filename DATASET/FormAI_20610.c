//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_NODES 25 //maximum number of nodes in the network

// structure to represent each node in the network
struct Node {
    char name[20];
    char ip[20];
    char neighbors[20][20]; //list of neighbors of a node
};

// function to print the current state of the network
void printNetwork(struct Node network[], int numNodes) {
    printf("Network Topology:\n");
    for(int i = 0; i < numNodes; i++) {
        printf("Node %s (IP: %s) - Neighbors: ", network[i].name, network[i].ip);
        for(int j = 0; strcmp(network[i].neighbors[j], ""); j++) {
            printf("%s ", network[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize the network with empty nodes
    struct Node network[MAX_NODES];
    for(int i = 0; i < MAX_NODES; i++) {
        strcpy(network[i].name, "");
        strcpy(network[i].ip, "");
        strcpy(network[i].neighbors[0], "");
    }

    int numNodes = 0; //number of nodes in the network

    // add nodes to the network
    strcpy(network[numNodes].name, "A");
    strcpy(network[numNodes].ip, "192.168.0.1");
    strcpy(network[numNodes].neighbors[0], "B");
    numNodes++;

    strcpy(network[numNodes].name, "B");
    strcpy(network[numNodes].ip, "192.168.0.2");
    strcpy(network[numNodes].neighbors[0], "A");
    strcpy(network[numNodes].neighbors[1], "C");
    numNodes++;

    strcpy(network[numNodes].name, "C");
    strcpy(network[numNodes].ip, "192.168.0.3");
    strcpy(network[numNodes].neighbors[0], "B");
    strcpy(network[numNodes].neighbors[1], "D");
    numNodes++;

    strcpy(network[numNodes].name, "D");
    strcpy(network[numNodes].ip, "192.168.0.4");
    strcpy(network[numNodes].neighbors[0], "C");
    numNodes++;

    // print the current state of the network
    printNetwork(network, numNodes);

    return 0;
}