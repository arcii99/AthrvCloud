//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8888

int main() {
    int socket_desc;
    struct sockaddr_in server, client;
    char message[2000], reply[2000];

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // bind socket with address
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    listen(socket_desc, 1);
    printf("Server is listening on port %d\n", PORT);

    // accept incoming connection
    int c = sizeof(struct sockaddr_in);
    int client_desc = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if(client_desc < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // receive message from client
    memset(&message, 0, sizeof(message));
    if(read(client_desc, message, sizeof(message)) < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Client: %s\n", message);

    // send reply to client
    memset(&reply, 0, sizeof(reply));
    strcpy(reply, "Welcome to the server, client!");
    if(send(client_desc, reply, strlen(reply), 0) < 0) {
        perror("Error sending reply");
        exit(EXIT_FAILURE);
    }
    printf("Reply sent to client\n");

    // close socket
    close(socket_desc);
    printf("Socket closed\n");

    return 0;
}