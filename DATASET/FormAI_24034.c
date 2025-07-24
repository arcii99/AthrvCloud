//FormAI DATASET v1.0 Category: Client Server Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 9000

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("error creating socket");
        exit(EXIT_FAILURE);
    }

    // setup the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        perror("error listening");
        exit(EXIT_FAILURE);
    }

    printf("server listening on port %d...\n", PORT);

    // accept incoming connections
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);
    if (client_fd < 0) {
        perror("error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("client connected\n");

    // read and process messages from the client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (read(client_fd, buffer, BUFFER_SIZE) < 0) {
            perror("error reading from socket");
            exit(EXIT_FAILURE);
        }

        // echo the message back to the client
        if (write(client_fd, buffer, strlen(buffer)) < 0) {
            perror("error writing to socket");
            exit(EXIT_FAILURE);
        }

        printf("message from client: %s", buffer);
    }

    return 0;
}