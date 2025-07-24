//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 2048

struct sockaddr_in server, client;
char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int sock, client_sock, val_read;
    socklen_t client_size = sizeof(client);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Could not create socket.");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    listen(sock, 5);

    printf("QoS Monitor is running on port 8888.\n");

    while(1) {
        client_sock = accept(sock, (struct sockaddr *) &client, &client_size);

        if (client_sock < 0) {
            perror("Error accepting connection.");
            continue;
        }

        printf("Connection accepted from %s:%d.\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        val_read = read(client_sock, buffer, BUFFER_SIZE);

        if (val_read < 0) {
            perror("Error reading from socket.");
            close(client_sock);
            continue;
        }

        printf("Received message: %s\n", buffer);

        close(client_sock);
    }

    return 0;
}