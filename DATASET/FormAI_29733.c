//FormAI DATASET v1.0 Category: Client Server Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_socket, client_socket, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("failed to create socket");
    }

    // set server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the socket
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("binding failed");
    }

    // listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        error("listening failed");
    }

    printf("Brave chat server is running on port %d\n", PORT);

    // accept incoming connections
    socklen_t addr_len = sizeof(client_addr);
    if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
        error("accept failed");
    }

    printf("Incoming connection accepted\n");

    // read from client and print
    while (1) {
        valread = read(client_socket, buffer, 1024);
        printf("Client: %s", buffer);
        if (strcmp(buffer, "bye\n") == 0) {
            break;
        }
        memset(buffer, 0, sizeof(buffer));
    }

    // close sockets and exit
    close(client_socket);
    close(server_socket);
    return 0;
}