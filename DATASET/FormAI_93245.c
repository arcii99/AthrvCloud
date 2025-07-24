//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_NODES 50
#define MAX_EDGES 100

struct Edge {
    int u, v;
    int cost;
};

struct NetworkTopology {
    int num_nodes;
    int num_edges;
    char** node_names;
    struct Edge* edges;
};

void init_network_topology(struct NetworkTopology* topology) {
    topology->num_nodes = 0;
    topology->num_edges = 0;
    topology->node_names = (char**)malloc(sizeof(char*) * MAX_NODES);
    topology->edges = (struct Edge*)malloc(sizeof(struct Edge) * MAX_EDGES);
}

void print_network_topology(struct NetworkTopology topology) {
    printf("Network Topology:\n");
    printf("Number of nodes: %d\n", topology.num_nodes);
    printf("Node names: ");
    for (int i = 0; i < topology.num_nodes; i++) {
        printf("%s ", topology.node_names[i]);
    }
    printf("\nNumber of edges: %d\n", topology.num_edges);
    printf("Edges: ");
    for (int i = 0; i < topology.num_edges; i++) {
        printf("(%d,%d,%d) ", topology.edges[i].u, topology.edges[i].v, topology.edges[i].cost);
    }
    printf("\n");
}

int find_node_index(char* node_name, struct NetworkTopology topology) {
    for (int i = 0; i < topology.num_nodes; i++) {
        if (strcmp(node_name, topology.node_names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int add_node(char* node_name, struct NetworkTopology* topology) {
    if (topology->num_nodes == MAX_NODES) {
        printf("Maximum number of nodes reached!\n");
        return -1;
    }
    int index = find_node_index(node_name, *topology);
    if (index != -1) {
        printf("Node %s already exists!\n", node_name);
        return -1;
    }
    topology->node_names[topology->num_nodes] = (char*)malloc(sizeof(char) * (strlen(node_name) + 1));
    strcpy(topology->node_names[topology->num_nodes], node_name);
    topology->num_nodes++;
    return topology->num_nodes - 1;
}

int add_edge(char* node1_name, char* node2_name, int cost, struct NetworkTopology* topology) {
    int index1 = find_node_index(node1_name, *topology);
    if (index1 == -1) {
        printf("Node %s does not exist!\n", node1_name);
        return -1;
    }
    int index2 = find_node_index(node2_name, *topology);
    if (index2 == -1) {
        printf("Node %s does not exist!\n", node2_name);
        return -1;
    }
    if (topology->num_edges == MAX_EDGES) {
        printf("Maximum number of edges reached!\n");
        return -1;
    }
    topology->edges[topology->num_edges].u = index1;
    topology->edges[topology->num_edges].v = index2;
    topology->edges[topology->num_edges].cost = cost;
    topology->num_edges++;
    return topology->num_edges - 1;
}

void send_topology(char* dest_ip, int dest_port, struct NetworkTopology topology) {
    struct sockaddr_in dest_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: cannot create socket.\n");
        return;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(dest_port);
    if(inet_pton(AF_INET, dest_ip, &dest_addr.sin_addr) <= 0) {
        printf("Error: invalid destination IP address.\n");
        return;
    }
    if(connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) < 0) {
        printf("Error: cannot connect to server.\n");
        return;
    }
    if(write(sockfd, &topology, sizeof(topology)) < 0) {
        printf("Error: failed to send topology.\n");
        return;
    }
    close(sockfd);
}

int main() {
    struct NetworkTopology topology;
    init_network_topology(&topology);
    int node1 = add_node("Node1", &topology);
    int node2 = add_node("Node2", &topology);
    int node3 = add_node("Node3", &topology);
    int node4 = add_node("Node4", &topology);
    int edge1 = add_edge("Node1", "Node2", 5, &topology);
    int edge2 = add_edge("Node1", "Node3", 10, &topology);
    int edge3 = add_edge("Node2", "Node4", 7, &topology);
    int edge4 = add_edge("Node3", "Node4", 8, &topology);
    print_network_topology(topology);
    send_topology("127.0.0.1", 9000, topology);
    return 0;
}