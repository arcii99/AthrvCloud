//FormAI DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define MAX_CONNECTIONS 100
#define DEFAULT_PORT 8080

typedef struct node {
    struct in_addr ip;
    bool blocked;
    struct node *next;
} Node;

Node *head = NULL;

// Wrapper function to initialize the socket
int create_socket(int *server_fd, struct sockaddr_in *address, int port) {
    int opt = 1;
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }
    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return -1;
    }
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(port);
    if (bind(*server_fd, (struct sockaddr *) address, sizeof(*address)) < 0) {
        perror("bind failed");
        return -1;
    }
    if (listen(*server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        return -1;
    }
    return 0;
}

// Function to block an IP
void block_ip(char *ip) {
    struct in_addr addr;
    if (inet_aton(ip, &addr) == 0) {
        printf("Invalid IP address\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (temp->ip.s_addr == addr.s_addr) {
            temp->blocked = true;
            printf("Blocked IP address: %s\n", ip);
            return;
        }
        temp = temp->next;
    }
    // IP not found in the list, add it to the list
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->ip = addr;
    new_node->blocked = true;
    new_node->next = head;
    head = new_node;
    printf("Blocked IP address: %s\n", ip);
}

// Function to unblock an IP
void unblock_ip(char *ip) {
    struct in_addr addr;
    if (inet_aton(ip, &addr) == 0) {
        printf("Invalid IP address\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (temp->ip.s_addr == addr.s_addr) {
            temp->blocked = false;
            printf("Unblocked IP address: %s\n", ip);
            return;
        }
        temp = temp->next;
    }
    printf("IP address not found\n");
}

// Function to check if an IP is blocked
bool is_blocked(struct in_addr *addr) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->ip.s_addr == addr->s_addr && temp->blocked == true) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello, World";

    // Create socket and bind to default port
    if (create_socket(&server_fd, &address, DEFAULT_PORT) < 0) {
        return -1;
    }

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            continue;
        }
        if (!is_blocked(&address.sin_addr)) {
            printf("Accepted connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            send(new_socket, message, strlen(message), 0);
        } else {
            printf("Rejected connection from blocked IP: %s\n", inet_ntoa(address.sin_addr));
        }
        close(new_socket);
    }

    return 0;
}

// Example usage
// block_ip("192.168.0.1");
// unblock_ip("192.168.0.1");