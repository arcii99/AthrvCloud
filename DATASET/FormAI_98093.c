//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1, addr_len = sizeof(client_addr);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port number
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen and accept incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client: %s\n", inet_ntoa(client_addr.sin_addr));

    while(1) {
        memset(&buffer, 0, sizeof(buffer));
        int valread = read(new_sockfd, buffer, 1024);
        if(valread) {
            printf("Message received from client: %s\n", buffer);
            send(new_sockfd, hello, strlen(hello), 0);
        } else {
            printf("Client disconnected\n");
            close(new_sockfd);
            break;
        }
    }

    close(sockfd);
    return 0;
}