//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100 // Maximum number of network devices

// Structure to represent a network device
typedef struct node
{
    char name[20]; // Device name
    int ip_address; // Device IP address
} node;

// Structure to represent a network link between two devices
typedef struct link
{
    int from; // Index of the device from which the link originates
    int to; // Index of the device to which the link connects
    int cost; // Link cost
} link;

// Structure to represent the network
typedef struct network
{
    node nodes[MAX_NODES]; // Array of network devices
    link links[MAX_NODES*(MAX_NODES-1)/2]; // Array of network links
    int num_nodes; // Number of network devices
    int num_links; // Number of network links
} network;

// Function to add a device to the network
void add_device(network *net, char name[], int ip)
{
    // Check if the maximum number of devices has been reached
    if(net->num_nodes == MAX_NODES)
    {
        printf("Unable to add device - maximum number of devices reached.\n");
        return;
    }
    
    // Add the device to the network
    strcpy(net->nodes[net->num_nodes].name, name);
    net->nodes[net->num_nodes].ip_address = ip;
    net->num_nodes++;
}

// Function to add a link between two devices
void add_link(network *net, int from, int to, int cost)
{
    // Check if the devices are already linked
    for(int i=0; i<net->num_links; i++)
    {
        if((net->links[i].from == from && net->links[i].to == to) ||
           (net->links[i].from == to && net->links[i].to == from))
        {
            printf("Unable to add link - devices are already linked.\n");
            return;
        }
    }
    
    // Add the link to the network
    net->links[net->num_links].from = from;
    net->links[net->num_links].to = to;
    net->links[net->num_links].cost = cost;
    net->num_links++;
}

// Function to print the network
void print_network(network *net)
{
    printf("Network Topology:\n");
    for(int i=0; i<net->num_nodes; i++)
    {
        printf("%s (%d)", net->nodes[i].name, net->nodes[i].ip_address);
        for(int j=0; j<net->num_links; j++)
        {
            if(net->links[j].from == i)
            {
                printf(" --> %s (%d) (%d)", net->nodes[net->links[j].to].name,
                       net->nodes[net->links[j].to].ip_address, net->links[j].cost);
            }
            else if(net->links[j].to == i)
            {
                printf(" <-- %s (%d) (%d)", net->nodes[net->links[j].from].name,
                       net->nodes[net->links[j].from].ip_address, net->links[j].cost);
            }
        }
        printf("\n");
    }
}

// Main function
int main()
{
    network net;
    net.num_nodes = 0;
    net.num_links = 0;
    
    // Add devices to the network
    add_device(&net, "Device 1", 19216811);
    add_device(&net, "Device 2", 19216812);
    add_device(&net, "Device 3", 19216813);
    add_device(&net, "Device 4", 19216814);
    
    // Add links to the network
    add_link(&net, 0, 1, 10);
    add_link(&net, 0, 2, 5);
    add_link(&net, 1, 3, 20);
    add_link(&net, 2, 3, 15);
    
    // Print the network
    print_network(&net);
    
    return 0;
}