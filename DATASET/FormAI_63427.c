//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message, client_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (new_socket < 0) {
        perror("accept failed. Error");
        return 1;
    }
    puts("Connection accepted");

    // Send welcome message to the client
    message = "Hello Client, I have received your connection. And now I am going to echo back your message\n";
    write(new_socket, message, strlen(message));

    // Receive a message from the client
    while(recv(new_socket, client_reply, 2000, 0) > 0) {
        printf("Client: %s", client_reply);
        write(new_socket, client_reply, strlen(client_reply));
        memset(client_reply, 0, sizeof(client_reply));
    }

    if(recv(new_socket, client_reply, 2000, 0) == 0) {
        puts("Client disconnected");
    }
    else {
        perror("recv failed. Error");
    }

    close(new_socket);

    return 0;
}