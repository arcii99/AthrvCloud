//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};

    // Initialize the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        return -1;
    }

    // Listen on the socket for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        return -1;
    }

    while (1) {
        printf("Waiting for incoming connections...\n");

        // Accept a new connection
        int client_address_length = sizeof(client_address);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0) {
            perror("accept failed");
            return -1;
        }

        // Convert the client IP address to a printable format
        char client_ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip_address, INET_ADDRSTRLEN);
        printf("Accepted connection from %s:%d\n", client_ip_address, ntohs(client_address.sin_port));

        // Read data from client and send a response
        int read_size;
        while ((read_size = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
            buffer[read_size] = '\0';
            printf("Received data from client %s:%d: %s\n", client_ip_address, ntohs(client_address.sin_port), buffer);
            write(client_fd, "Message received.", strlen("Message received."));
        }

        if (read_size == 0) {
            // The client has disconnected
            printf("Connection closed by client %s:%d\n", client_ip_address, ntohs(client_address.sin_port));
        }
        else if (read_size < 0) {
            perror("read failed");
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}