//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define BLOCKED_IPS_MAX_COUNT 100

struct BlockedIps {
    char ip[BUFFER_SIZE];
    int count;
};

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int listen_fd, conn_fd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    struct BlockedIps blocked_ips[BLOCKED_IPS_MAX_COUNT];
    int blocked_ips_count = 0;

    // Initialize blocked_ips array
    for (int i = 0; i < BLOCKED_IPS_MAX_COUNT; i++) {
        strcpy(blocked_ips[i].ip, "");
        blocked_ips[i].count = 0;
    }

    // Create socket
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set options on socket
    int opt = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080);
    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 10) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        cli_len = sizeof(cli_addr);

        // Accept incoming connection
        conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, &cli_len);
        if (conn_fd == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Get client IP address
        char cli_ip[INET_ADDRSTRLEN];
        if (inet_ntop(AF_INET, &cli_addr.sin_addr, cli_ip, INET_ADDRSTRLEN) == NULL) {
            perror("Error getting client IP address");
            continue;
        }

        // Check if client IP is blocked
        int is_blocked = 0;
        for (int i = 0; i < BLOCKED_IPS_MAX_COUNT; i++) {
            if (strcmp(blocked_ips[i].ip, cli_ip) == 0) {
                is_blocked = 1;
                blocked_ips[i].count++;
                break;
            } else if (strcmp(blocked_ips[i].ip, "") == 0) {
                strcpy(blocked_ips[i].ip, cli_ip);
                blocked_ips[i].count++;
                blocked_ips_count++;
                break;
            }
        }

        // If client IP is blocked, send error message and close connection
        if (is_blocked) {
            printf("Blocked IP: %s\n", cli_ip);
            char *error_message = "HTTP/1.1 403 Forbidden\r\n\r\n";
            send(conn_fd, error_message, strlen(error_message), 0);
            close(conn_fd);
            continue;
        }

        // Read request from client
        n = recv(conn_fd, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            perror("Error reading from socket");
            close(conn_fd);
            continue;
        }
        buffer[n] = '\0';

        // Print request
        printf("Received request:\n%s", buffer);

        // Process request
        char *response_message = "HTTP/1.1 200 OK\r\n\r\nHello, World!";
        send(conn_fd, response_message, strlen(response_message), 0);

        // Close connection
        close(conn_fd);
    }

    return 0;
}