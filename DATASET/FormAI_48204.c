//FormAI DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main() {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char message[2000], client_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Bind failed");
        return 1;
    }

    puts("Bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0) {
        puts("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    // Receive a message from the client
    while (recv(client_sock, client_reply, 2000, 0) > 0) {
        // Send the message back to client
        write(client_sock, client_reply, strlen(client_reply));
        memset(client_reply, 0, 2000);
    }

    if (client_reply[0] == '\0') {
        puts("Client disconnected");
        fflush(stdout);
    }

    close(socket_desc);
    return 0;
}