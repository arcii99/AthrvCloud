//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Define the port the proxy will listen on
#define PORT 8888

// Define the maximum buffer size
#define MAX_BUFFER_SIZE 65536

// Define structure to hold details of client and server connections
struct connection {
    int client_sock;
    int server_sock;
    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    size_t buffer_size;
};

// Function to create a new socket
int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a specific port
void bind_socket(int sock, struct sockaddr_in addr) {
    int ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
}

// Function to connect to a server using a socket
void connect_socket(int sock, struct sockaddr_in addr) {
    int ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
}

// Function to close a socket
void close_socket(int sock) {
    int ret = close(sock);
    if (ret < 0) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}

// Function to handle client requests and pass them to the server
void process_request(struct connection *conn) {
    int ret = recv(conn->client_sock, conn->buffer, MAX_BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Failed to receive data from client");
        exit(EXIT_FAILURE);
    }
    conn->buffer_size = ret;

    printf("Received %zu bytes from client:\n%s", conn->buffer_size, conn->buffer);

    // Connect to the server
    connect_socket(conn->server_sock, conn->server_addr);

    // Send request to server
    ret = send(conn->server_sock, conn->buffer, conn->buffer_size, 0);
    if (ret < 0) {
        perror("Failed to send data to server");
        exit(EXIT_FAILURE);
    }

    printf("Sent %zu bytes to server:\n%s", conn->buffer_size, conn->buffer);

    // Receive response from server
    ret = recv(conn->server_sock, conn->buffer, MAX_BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Failed to receive data from server");
        exit(EXIT_FAILURE);
    }
    conn->buffer_size = ret;

    printf("Received %zu bytes from server:\n%s", conn->buffer_size, conn->buffer);

    // Send response to client
    ret = send(conn->client_sock, conn->buffer, conn->buffer_size, 0);
    if (ret < 0) {
        perror("Failed to send data to client");
        exit(EXIT_FAILURE);
    }

    printf("Sent %zu bytes to client:\n%s", conn->buffer_size, conn->buffer);
}

// Main function
int main() {
    // Create proxy listening socket
    int proxy_sock = create_socket(AF_INET, SOCK_STREAM, 0);

    // Configure proxy listening address
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind proxy listening socket to address
    bind_socket(proxy_sock, proxy_addr);

    // Start listening on proxy socket
    int ret = listen(proxy_sock, 5);
    if (ret < 0) {
        perror("Failed to start listening on proxy socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming client connection
        struct connection conn;
        conn.client_sock = accept(proxy_sock, (struct sockaddr *)&conn.client_addr, (socklen_t *)&conn.client_addr);
        if (conn.client_sock < 0) {
            perror("Failed to accept incoming client connection");
            exit(EXIT_FAILURE);
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(conn.client_addr.sin_addr), ntohs(conn.client_addr.sin_port));

        // Create server connection
        conn.server_sock = create_socket(AF_INET, SOCK_STREAM, 0);

        // Configure server address
        memset(&conn.server_addr, 0, sizeof(conn.server_addr));
        conn.server_addr.sin_family = AF_INET;
        conn.server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        conn.server_addr.sin_port = htons(80);

        // Process client request and send response
        process_request(&conn);

        // Close server connection
        close_socket(conn.server_sock);

        // Close client connection
        close_socket(conn.client_sock);

        printf("Closed client connection from %s:%d\n", inet_ntoa(conn.client_addr.sin_addr), ntohs(conn.client_addr.sin_port));
    }

    // Close proxy listening socket
    close_socket(proxy_sock);

    return 0;
}