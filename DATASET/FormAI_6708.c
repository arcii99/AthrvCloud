//FormAI DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket.");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0) {
        // Print an ASCII art of a surprised face
        printf("          !!!!!!!\n");
        printf("       !!!      !!!\n");
        printf("      !!          !!\n");
        printf("     !!    !!!!!!    !!\n");
        printf("     !!          !!\n");
        printf("     !!    !!    !!\n");
        printf("     !!!!!!!!!!!!!\n");
        printf("   !!                !!\n");
        printf(" !!!!!              !!!!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        printf("Sorry, could not bind to port 8888.\n");
        return 1;
    }

    puts("Waiting for incoming connections...");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        printf("Could not accept connection.");
        return 1;
    }

    puts("Client connected.\n");

    // Receive message from client
    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0 ) {
        // Print the received message
        printf("Received message: %s\n", client_message);

        // Send message back to client
        if (send(client_sock, client_message, strlen(client_message), 0) < 0) {
            printf("Could not send message.");
            return 1;
        }

        // Clear the buffer
        memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
        puts("Client disconnected.\n");
        fflush(stdout);
    }
    else if (read_size == -1) {
        printf("Could not receive message.");
        return 1;
    }

    return 0;
}