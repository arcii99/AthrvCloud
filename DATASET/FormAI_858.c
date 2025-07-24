//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT 8080

// Function that converts an IP address string to struct sockaddr_in.
struct sockaddr_in get_address(char *host) {
    struct hostent *servers = gethostbyname(host);
    struct sockaddr_in address;
    bzero((char *)&address, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *)servers->h_addr, (char *)&address.sin_addr.s_addr, servers->h_length);
    address.sin_port = htons(PORT);
    return address;
}

// Function that initializes a socket on port 8080.
int get_socket() {
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in address;
    bzero((char *)&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Initializes a new socket for connections on port 8080.
    server_fd = get_socket();

    // Start accepting connections.
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[1024] = {0};
        valread = read(new_socket, buffer, 1024);

        // Echo the message back to the sender.
        if (valread > 0) {
            printf("%s\n", buffer);
            send(new_socket, buffer, strlen(buffer), 0);
        }

        // Close the socket for this connection.
        close(new_socket);
    }
    return 0;
}