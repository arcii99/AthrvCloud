//FormAI DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // initialize socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // set server attributes
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    // send initial message
    printf("Sending message to cyberpunk server...\n");
    char *message = "Hello, cyberpunks!";
    send(socket_fd, message, strlen(message), 0);

    // receive response message
    read(socket_fd, buffer, 1024);
    printf("Server response: %s\n", buffer);

    // close socket file descriptor
    close(socket_fd);

    return 0;
}