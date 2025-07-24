//FormAI DATASET v1.0 Category: Socket programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    printf("Listening on port %d...\n", PORT);

    // Listen
    listen(sock, 3);

    int new_sock;
    struct sockaddr_in client;
    int c = sizeof(struct sockaddr_in);

    // Accept client connections
    while ((new_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Read client message
        char client_message[2000];
        recv(new_sock, client_message, 2000, 0);
        printf("Client message: %s\n", client_message);

        // Send message back to client
        char* message = "Thanks for connecting!";
        send(new_sock, message, strlen(message), 0);

        close(new_sock);
    }

    if (new_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}