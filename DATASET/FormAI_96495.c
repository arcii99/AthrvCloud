//FormAI DATASET v1.0 Category: Client Server Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number
#define PORT 8080

int main(int argc, char *argv[]) {
    int sock_fd, conn_fd;
    struct sockaddr_in serv_addr, client_addr;

    // Create a socket for communication
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        printf("Unable to create the socket.\n");
        return 1;
    }

    // Set the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified port
    if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Unable to bind the server socket to port %d.\n", PORT);
        return 1;
    }

    // Listen for incoming connections
    if(listen(sock_fd, 5) < 0) {
        printf("Error while listening for incoming connections.\n");
        return 1;
    }
    printf("Server is listening on port %d.\n", PORT);

    // Accept incoming connections
    socklen_t client_addr_len = sizeof(client_addr);
    conn_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(conn_fd < 0) {
        printf("Error while accepting incoming connection.\n");
        return 1;
    }
    printf("Client %s:%d connected.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Send and receive messages
    while(1) {
        char buffer[1024] = {0};
        int bytes_read = read(conn_fd, buffer, 1024);
        if(bytes_read < 0) {
            printf("Error while reading data from client.\n");
            break;
        }
        printf("Received message: %s", buffer);

        char response[1024];
        printf("Enter your response: ");
        fgets(response, 1024, stdin);
        int bytes_written = write(conn_fd, response, strlen(response));
        if(bytes_written < 0) {
            printf("Error while sending data to client.\n");
            break;
        }
    }

    // Close the connection and the server socket
    close(conn_fd);
    close(sock_fd);
    return 0;
}