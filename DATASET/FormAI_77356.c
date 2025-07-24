//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define DEFAULT_PORT 55555

struct node {
    char *ip_addr;
    int port_num;
    int *neighbors;
    int num_neighbors;
};

struct network {
    struct node *nodes;
    int num_nodes;
};

int main(int argc, char *argv[]) {
    int port_num = DEFAULT_PORT;
    int opt;
    char *ip_addr;

    while ((opt = getopt(argc, argv, "p:i:")) != -1) {
        switch (opt) {
            case 'p':
                port_num = atoi(optarg);
                break;
            case 'i':
                ip_addr = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-p port] [-i ip address]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    int sock_fd;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port_num);

    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection to server failed");
        exit(EXIT_FAILURE);
    }

    // read network info from server
    struct network my_network;
    char buf[BUFSIZ];
    memset(buf, 0, sizeof(buf));
    read(sock_fd, buf, sizeof(buf));
    parse_network_info(buf, &my_network);

    // perform network mapping
    for (int i = 0; i < my_network.num_nodes; i++) {
        printf("Node %d has IP address %s and port number %d.\n", i+1, my_network.nodes[i].ip_addr, my_network.nodes[i].port_num);
        printf("Node %d has %d neighbors.\n", i+1, my_network.nodes[i].num_neighbors);
        printf("Node %d's neighbors are: ", i+1);
        for (int j = 0; j < my_network.nodes[i].num_neighbors; j++) {
            printf("%d ", my_network.nodes[i].neighbors[j]);
        }
        printf("\n");
    }

    close(sock_fd);

    return 0;
}

void parse_network_info(char *buf, struct network *my_network) {
    char *line = strtok(buf, "\n");

    // read number of nodes
    my_network->num_nodes = atoi(line);

    // allocate memory for array of nodes
    my_network->nodes = malloc(sizeof(struct node) * my_network->num_nodes);

    // read nodes one by one
    for (int i = 0; i < my_network->num_nodes; i++) {
        // read IP address and port number
        line = strtok(NULL, "\n");
        char *ip_addr = strtok(line, " ");
        my_network->nodes[i].ip_addr = strdup(ip_addr);
        int port_num = atoi(strtok(NULL, " "));
        my_network->nodes[i].port_num = port_num;

        // read number of neighbors and their IDs
        line = strtok(NULL, "\n");
        int num_neighbors = atoi(line);
        my_network->nodes[i].num_neighbors = num_neighbors;
        my_network->nodes[i].neighbors = malloc(sizeof(int) * num_neighbors);
        line = strtok(NULL, "\n");
        char *neighbor_id = strtok(line, " ");
        int j = 0;
        while (neighbor_id != NULL) {
            my_network->nodes[i].neighbors[j] = atoi(neighbor_id);
            j++;
            neighbor_id = strtok(NULL, " ");
        }
    }
}