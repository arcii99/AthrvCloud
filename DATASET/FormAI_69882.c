//FormAI DATASET v1.0 Category: Client Server Application ; Style: decentralized
// C Client Server Application - Decentralized style

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    int yes = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 1) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for client connection...\n");

    int client_sock = accept(sock, NULL, NULL);
    if (client_sock == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected!\n");

    char buffer[MAX_BUFFER_SIZE];

    while (1) {
        memset(&buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client disconnected!\n");
            break;
        } else {
            printf("Received Message: %s", buffer);
            if (strcmp(buffer, "exit\n") == 0) {
                printf("Client disconnected!\n");
                break;
            }

            // Send response to client
            int bytes_sent = send(client_sock, buffer, strlen(buffer), 0);
            if (bytes_sent == -1) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    close(client_sock);
    close(sock);
    return 0;
}