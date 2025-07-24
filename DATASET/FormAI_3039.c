//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define SERVER_PORT 8888

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }

    puts("bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");

        // Receive message from client
        while((read_size = recv(client_sock, client_message, 2000, 0)) > 0 ) {
            // Send response to the client
            write(client_sock, "Hello, client! Your message was received.", strlen("Hello, client! Your message was received."));
        }

        if (read_size == 0) {
            puts("Client disconnected");
        }
        else if (read_size == -1) {
            perror("recv failed");
        }
    }

    return 0;
}