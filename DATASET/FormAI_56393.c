//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *message){
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]){
    // Create socket file descriptor
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1)
        error("Failed to create socket");

    // Configure socket address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to server
    int connect_status = connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(connect_status == -1)
        error("Failed to connect to server");

    // Receive message from server
    char buffer[BUFFER_SIZE] = {0};
    int recv_status = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if(recv_status == -1)
        error("Failed to receive message from server");
    printf("Server message: %s\n", buffer);

    // Send message to server
    char *message_out = "Client: Requesting data from server";
    if(send(socket_fd, message_out, strlen(message_out), 0) == -1)
        error("Failed to send message to server");

    // Receive data from server
    char data_buffer[BUFFER_SIZE] = {0};
    int data_recv_status = recv(socket_fd, data_buffer, BUFFER_SIZE, 0);
    if(data_recv_status == -1)
        error("Failed to receive data from server");
    printf("Data received from server: %s\n", data_buffer);

    // Close socket
    close(socket_fd);
    return 0;
}