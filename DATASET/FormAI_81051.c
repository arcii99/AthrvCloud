//FormAI DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    int clients[MAX_CLIENTS];
    int num_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = { 0 };
    char message[1024] = { 0 };
    int opt = 1;
    int addrlen = sizeof(server_addr);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 1;
    }

    // Forcefully attaching socket to the server port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return 1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        // Accept incoming connections
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }
        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add client to the list of clients
        clients[num_clients++] = client_fd;

        // Receive client message and send response
        if (recv(client_fd, buffer, 1024, 0) < 0) {
            perror("recv failed");
            close(client_fd);
            continue;
        }

        // Generate response message
        strcpy(message, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        strcat(message, "<html><head><title>Simple Web Server</title></head><body>");
        strcat(message, "<h1>Hello, world!</h1>");
        strcat(message, "</body></html>");

        // Send response message to client
        if (send(client_fd, message, strlen(message), 0) < 0) {
            perror("send failed");
            close(client_fd);
            continue;
        }

        // Close client connection
        close(client_fd);
        num_clients--;
    }

    // Close server socket
    close(server_fd);

    return 0;
}