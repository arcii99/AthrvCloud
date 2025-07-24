//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODE 100
#define MAX_INT 2147483647 // maximum value of int

int adj_matrix[MAX_NODE][MAX_NODE];
int nodes_number = 0;

void init_adj_matrix() {
    int i, j;
    for (i = 0; i < MAX_NODE; i++)
        for (j = 0; j < MAX_NODE; j++)
            adj_matrix[i][j] = MAX_INT;
}

void add_node(char ip[]) {
    int i, node_exists = 0;
    for (i = 0; i < nodes_number; i++)
        if (strcmp(ip, inet_ntoa(*(struct in_addr*)&adj_matrix[i][nodes_number])) == 0) {
            printf("\nNode already exists with IP %s.\n", ip);
            node_exists = 1;
            break;
        }
    if (!node_exists) {
        printf("\nNode %s with index %d added.\n", ip, nodes_number);
        nodes_number++;
    }
}

void add_edge(char ip1[], char ip2[], int cost) {
    int i, j, u = -1, v = -1;
    for (i = 0; i < nodes_number; i++) {
        if (strcmp(ip1, inet_ntoa(*(struct in_addr*)&adj_matrix[i][nodes_number])) == 0) u = i;
        if (strcmp(ip2, inet_ntoa(*(struct in_addr*)&adj_matrix[i][nodes_number])) == 0) v = i;
    }
    if (u == -1 || v == -1 || cost < 0) {
        printf("\nInvalid edge (%s, %s, %d).\n", ip1, ip2, cost);
        return;
    }
    adj_matrix[u][v] = cost;
    adj_matrix[v][u] = cost;
    printf("\nEdge added between nodes %s and %s with cost %d.\n", ip1, ip2, cost);
}

void print_adj_matrix() {
    printf("\nAdjacency matrix:\n");
    printf("        ");
    int i, j;
    for (i = 0; i < nodes_number; i++) printf("%-8s", inet_ntoa(*(struct in_addr*)&adj_matrix[i][nodes_number]));
    printf("\n");
    for (i = 0; i < nodes_number; i++) {
        printf("%-8s", inet_ntoa(*(struct in_addr*)&adj_matrix[i][nodes_number]));
        for (j = 0; j < nodes_number; j++) {
            if (adj_matrix[i][j] == MAX_INT) printf("%-8s", "INF");
            else printf("%-8d", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sockfd, len, n;
    struct sockaddr_in servaddr, client;
    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }
    len = sizeof(client);
    init_adj_matrix();
    while (1) {
        n = recvfrom(sockfd, buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr*)&client, &len);
        buffer[n] = '\0';
        if (buffer[0] == 'N') {
            add_node(buffer + 1);
        }
        else if (buffer[0] == 'E') {
            char ip1[40], ip2[40];
            int cost;
            sscanf(buffer + 1, "%s %s %d", ip1, ip2, &cost);
            add_edge(ip1, ip2, cost);
        }
        else if (buffer[0] == 'P') {
            print_adj_matrix();
        }
        else {
            printf("\nInvalid message received.\n");
            printf("Use N<IP> to add node.\n");
            printf("Use E<IP1> <IP2> <cost> to add edge.\n");
            printf("Use P to print adjacency matrix.\n");
        }
    }
    return 0;
}