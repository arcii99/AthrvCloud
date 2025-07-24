//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_HOSTS 50
#define MAX_NAME_LEN 64

/*
 * This program is a network topology mapper that prints out the nodes in a network and
 * their connections to each other.
 *
 * Usage: ./mapper <host>
 * Example: ./mapper 192.168.1.1
 */

struct node {
    char name[MAX_NAME_LEN];
    int id;
    struct node *next;
};

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./mapper <host>\n");
        exit(1);
    }

    struct node hosts[MAX_HOSTS];
    int num_hosts = 0;

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(4200);

    // Convert the IP address to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Get the list of hosts from the server
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Parse the list of hosts and add them to the nodes array
    char *token = strtok(buffer, "\n");
    while (token != NULL) {
        char name[MAX_NAME_LEN];
        memset(name, 0, sizeof(name));
        int id;
        sscanf(token, "%s %d", name, &id);

        struct node new_node;
        strcpy(new_node.name, name);
        new_node.id = id;
        new_node.next = NULL;

        hosts[num_hosts++] = new_node;

        token = strtok(NULL, "\n");
    }

    // Print out the nodes and their connections
    for (int i = 0; i < num_hosts; i++) {
        printf("%s (%d) is connected to:\n", hosts[i].name, hosts[i].id);
        for (int j = 0; j < num_hosts; j++) {
            if (i != j) {
                printf("\t%s (%d)\n", hosts[j].name, hosts[j].id);
            }
        }
        printf("\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}