//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUF_SIZE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buf[BUF_SIZE];

    // Create a TCP socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to an IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sock, BACKLOG) == -1) {
        perror("listen");
        return 1;
    }

    printf("TCP server is listening on 0.0.0.0:%d\n", ntohs(server_addr.sin_port));

    // Accept incoming connections
    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len)) == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, buf, sizeof(buf));
        printf("Accepted connection from %s:%d\n", buf, ntohs(client_addr.sin_port));

        // Read incoming data from the client
        memset(&buf, 0, sizeof(buf));
        if (recv(client_sock, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        printf("Received data from client: %s\n", buf);

        // Send response to the client
        if (send(client_sock, "Hello from server", strlen("Hello from server"), 0) == -1) {
            perror("send");
            close(client_sock);
            continue;
        }

        close(client_sock);
    }

    return 0;
}