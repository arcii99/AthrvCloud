//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
// As the sun sets on the ocean of code,

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The neon lights of the internet cafe illuminate the surreal world of programming

#define PORT 8080

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    int addrlen = sizeof(client_address);

    // The server socket emerges from the murky depths

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    // The server sets its parameters to listen to the incoming data

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket\n");
        return -1;
    }

    // The server begins listening for incoming connections

    if (listen(sockfd, 3) < 0) {
        printf("Failed to listen\n");
        return -1;
    }

    // The server waits for the client to approach

    printf("Waiting for incoming connections...\n");

    new_sockfd = accept(sockfd, (struct sockaddr*)&client_address, (socklen_t*)&addrlen);
    if (new_sockfd < 0) {
        printf("Failed to accept connection\n");
        return -1;
    }

    // The server accepts the client and starts talking

    printf("Connection established!\n");

    send(new_sockfd, "Hello, I am your server!\nWhat is your name?\n", strlen("Hello, I am your server!\nWhat is your name?\n"), 0);
    recv(new_sockfd, buffer, 1024, 0);
    printf("Client: %s", buffer);

    // The server and client engage in a surreal conversation

    send(new_sockfd, "Interesting name. Let's count to 10 backwards together.\n", strlen("Interesting name. Let's count to 10 backwards together.\n"), 0);
    for (int i = 10; i > 0; i--) {
        sprintf(buffer, "%d\n", i);
        send(new_sockfd, buffer, strlen(buffer), 0);
        recv(new_sockfd, buffer, 1024, 0);
    }

    // The server bids farewell to the client and closes the connection

    send(new_sockfd, "Goodbye, it was nice talking to you!\n", strlen("Goodbye, it was nice talking to you!\n"), 0);
    close(new_sockfd);
    close(sockfd);

    return 0;
}