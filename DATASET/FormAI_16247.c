//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    // Check for valid arguments
    if (argc != 3) {
        printf("Usage: ./http_proxy <PORT> <BLACKLIST_FILE>\n");
        return 1;
    }

    // Open blacklist file
    char* blacklist_file = argv[2];
    FILE* fp_blacklist = fopen(blacklist_file, "r");
    if (fp_blacklist == NULL) {
        printf("Error opening blacklist file.\n");
        return 1;
    }

    // Read blacklist and store in array
    char blacklist[10][100];
    memset(blacklist, 0, sizeof(blacklist));
    int i = 0;
    while (fgets(blacklist[i], 100, fp_blacklist) != NULL) {
        // Remove newline character from end of string
        strtok(blacklist[i], "\n");
        i++;
    }

    // Create socket
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation error.\n");
        return 1;
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Setsockopt error.\n");
        return 1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        printf("Bind failed.\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Listen error.\n");
        return 1;
    }

    // Accept incoming connection and handle request
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            printf("Accept error.\n");
            return 1;
        }

        // Receive request from client
        memset(buffer, 0, sizeof(buffer));
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread < 0) {
            printf("Read error.\n");
            return 1;
        }

        // Parse request to get hostname and port number
        char method[10], url[100], version[10], hostname[50], path[50];
        int port = 80;
        sscanf(buffer, "%s %s %s", method, url, version);
        if (strncmp(url, "http://", 7) == 0) {
            sscanf(url, "http://%[^/]/%s", hostname, path);
        }
        else {
            sscanf(url, "%[^/]/%s", hostname, path);
        }
        char* port_pos = strstr(hostname, ":");
        if (port_pos != NULL) {
            sscanf(port_pos+1, "%d", &port);
            *port_pos = '\0';
        }

        // Check if hostname is in blacklist
        for (int i = 0; i < 10; i++) {
            if (strcmp(hostname, blacklist[i]) == 0) {
                write(new_socket, "HTTP/1.1 403 Forbidden\n\n", 24);
                close(new_socket);
                break;
            }
        }

        // If hostname is not in blacklist, forward request to server
        struct sockaddr_in server_addr;
        int server_fd, bytes_sent, bytes_received, server_addrlen = sizeof(server_addr);
        char server_buffer[BUFFER_SIZE] = {0};
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Server socket error.\n");
            return 1;
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(hostname);
        memset(&(server_addr.sin_zero), 0, 8);

        if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Server connect error.\n");
            return 1;
        }

        bytes_sent = send(server_fd, buffer, strlen(buffer), 0);
        if (bytes_sent < 0) {
            printf("Server send error.\n");
            return 1;
        }

        // Receive response from server and forward to client
        while (1) {
            bytes_received = recv(server_fd, server_buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) break;
            bytes_sent = send(new_socket, server_buffer, bytes_received, 0);
            if (bytes_sent < 0) {
                printf("Client send error.\n");
                return 1;
            }
            memset(server_buffer, 0, BUFFER_SIZE);
        }

        // Close server connection and client connection
        close(server_fd);
        close(new_socket);
    }

    return 0;
}