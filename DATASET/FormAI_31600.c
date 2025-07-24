//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUM 3000
#define MESSAGE_SIZE 1024

int main(void) {
    //create socket object
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    //configure server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUM);
    inet_aton("127.0.0.1", &server_address.sin_addr);

    //connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    //send a test message to server
    char message[MESSAGE_SIZE] = "Hello, server!";
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Failed to send message");
        exit(1);
    }

    //receive response from server
    char response[MESSAGE_SIZE];
    memset(response, 0, MESSAGE_SIZE);
    if (recv(socket_fd, response, MESSAGE_SIZE, 0) < 0) {
        perror("Failed to receive response");
        exit(1);
    }

    //log response from server
    printf("Response from server: %s\n", response);

    //close socket connection
    close(socket_fd);
    
    return 0;
}