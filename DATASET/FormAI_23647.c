//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock_fd, connect_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
 
    // Setting server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(client_addr);

    // Accepting incoming connections and receiving message
    if ((connect_fd =accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    int message_len = read(connect_fd, buffer, 1024);
    printf("Client message: %s\n", buffer);

    char* server_response = "Hello from server!";
    send(connect_fd, server_response, strlen(server_response), 0);
    printf("Message sent back to client\n");

    return 0;
}