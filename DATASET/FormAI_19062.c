//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8080

int main() {

    int socket_fd, new_socket, valread;
    struct sockaddr_in servaddr, cliaddr;
    char message[500];

    // Create Socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: Unable to create socket.\n");
        exit(0);
    }

    // Assigning IP and Port
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: Unable to Bind.\n");
        exit(0);
    }
    
    printf("\nServer Started Successfully!\n");

    // Listen for Client Requests
    if (listen(socket_fd, 5) == -1) {
        printf("Error: Unable to Listen.\n");
        exit(0);
    }
    
    // Accept the Connection
    int len = sizeof(cliaddr);
    new_socket = accept(socket_fd, (struct sockaddr*)&cliaddr , (socklen_t*)&len);
    if (new_socket < 0) {
        printf("Error: Unable to Accept the Connection.\n");
        exit(0);
    }
    
    printf("Connected to the Client Successfully!\n\n");

    // Receive message from the Client
    valread = read(new_socket, message, 500);
    printf("Client Message: %s\n", message);

    // Send message to the Client
    char *server_message = "Hello Client, I got your Message!";
    send(new_socket, server_message, strlen(server_message), 0);
    printf("Response Sent Successfully!\n");

    // Close Sockets
    close(new_socket);
    close(socket_fd);
    printf("\nSockets Closed Successfully!\n");

    return 0;
}