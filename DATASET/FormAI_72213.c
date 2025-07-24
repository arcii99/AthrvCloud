//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NODES 100
#define PORT 8888

struct Node {
    int id;
    struct sockaddr_in address;
};

struct Topology {
    int num_nodes;
    struct Node nodes[MAX_NODES];
    int adjacency_matrix[MAX_NODES][MAX_NODES];
};

void print_topology(struct Topology topology) {
    printf("Number of Nodes: %d\n", topology.num_nodes);
    printf("Nodes:\n");
    for (int i = 0; i < topology.num_nodes; i++) {
        printf("Node %d - IP Address: %s  Port Number: %d\n", topology.nodes[i].id, inet_ntoa(topology.nodes[i].address.sin_addr), ntohs(topology.nodes[i].address.sin_port));
    }
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < topology.num_nodes; i++) {
        for (int j = 0; j < topology.num_nodes; j++) {
            printf("%d ", topology.adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int add_node(struct Topology *topology, struct sockaddr_in address) {
    for (int i = 0; i < topology->num_nodes; i++) {
        if (memcmp(&(topology->nodes[i].address), &address, sizeof(struct sockaddr_in)) == 0) {
            return topology->nodes[i].id; // Node is already in the topology
        }
    }
    if (topology->num_nodes >= MAX_NODES) {
        return -1; // Topology is already at maximum capacity
    }
    int node_id = topology->num_nodes;
    topology->nodes[node_id].id = node_id;
    topology->nodes[node_id].address = address;
    topology->num_nodes++;
    return node_id;
}

void *handle_connection(void *arg) {
    int client_socket = *((int*)arg);
    free(arg);
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(struct sockaddr_in);
    getpeername(client_socket, (struct sockaddr*)&client_address, &client_address_len);
    printf("Connection from IP Address: %s  Port Number: %d\n", inet_ntoa(client_address.sin_addr) , ntohs(client_address.sin_port));
    struct Topology *topology = (struct Topology*)malloc(sizeof(struct Topology));
    topology->num_nodes = 0;
    memset(topology->adjacency_matrix, 0, sizeof(topology->adjacency_matrix));
    while (1) {
        int node_id = add_node(topology, client_address);
        if (node_id < 0) {
            printf("Topology is at maximum capacity. Connection closed.\n");
            break;
        }
        for (int i = 0; i < topology->num_nodes; i++) {
            if (i == node_id) {
                continue;
            }
            if (topology->adjacency_matrix[node_id][i] == 1) {
                continue;
            }
            topology->adjacency_matrix[node_id][i] = 1;
            topology->adjacency_matrix[i][node_id] = 1;
            struct Node node = topology->nodes[i];
            char message[256];
            sprintf(message, "%d,%d", node.id, ntohs(node.address.sin_port));
            send(client_socket, message, strlen(message), 0);
        }
        sleep(1); // Wait for all nodes to connect
    }
    print_topology(*topology);
    free(topology);
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Topology Mapper Running. Listening on port %d...\n", PORT);
    while (1) {
        int *client_socket = malloc(sizeof(int));
        if ((*client_socket = accept(server_socket, NULL, NULL)) < 0) {
            perror("accept failed");
            continue;
        }
        pthread_t thread;
        pthread_create(&thread, NULL, handle_connection, (void*)client_socket);
        pthread_detach(thread);
    }
    return 0;
}