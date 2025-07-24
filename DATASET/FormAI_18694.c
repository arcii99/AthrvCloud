//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, new_sock;
    int port = 4444;
    struct sockaddr_in host_addr, client_addr;
    char buffer[1024];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set up the server's address
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(port);
    host_addr.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) < 0) {
        perror("Error binding socket to address");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        exit(1);
    }

    printf("Server started listening on port %d...\n", port);

    while (1) {
        unsigned int sin_size = sizeof(struct sockaddr_in);

        // accept a connection
        new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);

        if (new_sock < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("New connection from %s on port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (!fork()) {
            // child process
            close(sockfd);

            while (1) {
                int bytes_received = recv(new_sock, buffer, sizeof(buffer), 0);

                if (bytes_received < 0) {
                    printf("Error receiving data\n");
                    exit(1);
                }

                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                    close(new_sock);
                    exit(0);
                }

                printf("Received data from client: %s\n", buffer);

                // send a response to the client
                if (send(new_sock, "Hello from the server", 22, 0) == -1) {
                    perror("Error sending data");
                    exit(1);
                }
            }
        }

        // parent process
        close(new_sock);
    }

    return 0;
}