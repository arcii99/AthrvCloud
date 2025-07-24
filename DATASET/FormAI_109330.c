//FormAI DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
/*
 * A simple client-server application in C using socket programming
 * 
 * The server listens on a specified port and accepts incoming connections from clients.
 * Upon receiving a connection request message from the client, the server sends an acknowledgement message
 * back to the client.
 * 
 * Author: Dennis Ritchie
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *ack_message = "ACKNOWLEDGEMENT\n";
       
    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }
       
    // attach socket to the specified port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        return -1;
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        return -1;
    }
    printf("Listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            return -1;
        }
        printf("New connection accepted\n");
        valread = read(new_socket, buffer, 1024);
        printf("Received message from client: %s", buffer);
        send(new_socket, ack_message, strlen(ack_message), 0);
        printf("Acknowledgement sent to client\n");
        close(new_socket);
        printf("Connection closed\n");
    }
    return 0;
}