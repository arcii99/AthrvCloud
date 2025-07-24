//FormAI DATASET v1.0 Category: Client Server Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
        printf("Set socket option error\n");
        return -1;
    }

    // Setup server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to the server address
    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind error\n");
        return -1;
    }

    // Listen to incoming connections
    if (listen(sock, 3) < 0) {
        printf("Listen error\n");
        return -1;
    }

    while (1) {
        // Accept incoming connections
        int new_sock;
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);
        if ((new_sock = accept(sock, (struct sockaddr *) &client_addr,
                (socklen_t*) &addrlen)) < 0) {
            printf("Accept error\n");
            return -1;
        }

        // Read message from client
        valread = read(new_sock, buffer, 1024);
        printf("Message from client: %s\n", buffer);

        // Send response to client
        char *msg = "Hello from server!";
        send(new_sock, msg, strlen(msg), 0);
        printf("Response sent to client\n");

        // Close connection
        close(new_sock);
    }

    return 0;
}